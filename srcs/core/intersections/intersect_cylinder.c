/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:38:57 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/04 01:22:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

t_tuple	normal_at_cy(const t_cylinder *cy, t_tuple point)
{
	t_tuple	local_point;
	t_tuple	world_normal;
	double	dist;

	local_point = matrix_vect(cy->m, point);
	dist = local_point.x * local_point.x + local_point.z * local_point.z;
	if (dist < 1 && local_point.y >= cy->hgt / 2 - EPSILON)
		world_normal = vector(0, 1, 0);
	else if (dist < 1 && local_point.y <= -cy->hgt / 2 + EPSILON)
		world_normal = vector(0, -1, 0);
	else
	{
		local_point.y = 0;
		local_point.w = 0;
	}
	world_normal = matrix_vect(cy->t_m, local_point);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}


static bool	check_cap(t_ray *ray0, const t_cylinder *cy, double t)
{
	double	x;
	double	z;
	t_ray	ray;

	ray = matrix_ray(&cy->m, ray0);
	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((x * x + z * z) <= 1);
}


static void intersect_caps_cy(t_ray *ray0, const t_cylinder *cy)
{
	t_ray	ray;
	double	t;
	t_intersection	*itr;

	ray = matrix_ray(&cy->m, ray0);
	if (eq(ray.direction.y, 0))
		return ;
	t = (-cy->hgt / 2 - ray.origin.y) / ray.direction.y;
	if (check_cap(ray0, cy, t))
	{
		itr = intersection(CYLINDER_ID, (t_object *)cy);
		if (!itr)
			return (ft_puterror(FAILED_MALLOC, (char *)__func__));
		itr->t = t;
		add_intersection_to_ray(ray0, itr);
	}
	t = (cy->hgt / 2 - ray.origin.y) / ray.direction.y;
	if (check_cap(ray0, cy, t))
	{
		// bug d'afichage ici si on a un angle rasant avec la face d'un cylindre
		itr = intersection(CYLINDER_ID, (t_object *)cy);
		if (!itr)
			return (ft_puterror(FAILED_MALLOC, (char *)__func__));
		itr->t = t;
		add_intersection_to_ray(ray0, itr);
	}
}




static void verify_intersections_cybis(const double *q,
			t_ray *ray0, const t_cylinder *cy)
{
	t_intersection	*itr2;
	t_ray			ray;

	itr2 = NULL;
	ray = matrix_ray(&cy->m, ray0);
	if (fabs(ray.origin.y + (double)(-q[1] + sqrt(q[3])) / (double)(2 * q[0])
			* ray.direction.y) < cy->hgt / 2)
	{
		itr2 = intersection(CYLINDER_ID, (t_object *)cy);
		if (!itr2)
			return (ft_puterror(FAILED_MALLOC, (char *)__func__));
		itr2->t = (double)(-q[1] + sqrt(q[3])) / (double)(2 * q[0]);
		add_intersection_to_ray(ray0, itr2);
	}
	intersect_caps_cy(ray0, cy);
}

static void verify_intersections_cy(const double *q,
			t_ray *ray0, const t_cylinder *cy)
{
	t_intersection	*itr1;
	t_ray			ray;

	itr1 = NULL;
	ray = matrix_ray(&cy->m, ray0);
	if (fabs(ray.origin.y + (double)(-q[1] - sqrt(q[3])) / (double)(2 * q[0])
			* ray.direction.y) < cy->hgt / 2)
	{
		itr1 = intersection(CYLINDER_ID, (t_object *)cy);
		if (!itr1)
			ft_puterror(FAILED_MALLOC, (char *)__func__);
		itr1->t = (double)(-q[1] - sqrt(q[3])) / (double)(2 * q[0]);
		add_intersection_to_ray(ray0, itr1);
	}
	verify_intersections_cybis(q, ray0, cy);
}

// After transforming the point from world space to object
// space (1st matrix_vect call), we should get the normal vector
// of the sphere at this point. But as the point was transformed
// to object space, origin of the sphere stays 0,0,0 so the
// calculation should be tuple_sub(point, point(0,0,0)) which achieves
// exactly the same as writing point.w = 0.
void intersect_cy(const t_cylinder *cy, t_ray *ray0)
{
	double q[4];
	t_ray ray;

	ray = matrix_ray(&cy->m, ray0);
	// local_intersect_at starts_here
	q[0] = ray.direction.x * ray.direction.x
		+ ray.direction.z * ray.direction.z;
	if (eq(q[0], 0))
		return;
	q[1] = 2 * ray.origin.x * ray.direction.x + 2
		* ray.origin.z * ray.direction.z;
	q[2] = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	q[3] = q[1] * q[1] - 4 * q[0] * q[2];
	if (q[3] >= 0)
		verify_intersections_cy(q, ray0, cy);
}