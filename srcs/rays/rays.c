/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 23:18:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_raytracer	raytracer(t_tuple origin, t_tuple direction)
{
	t_raytracer	rt;

	ft_memset(&rt, 0, sizeof(rt));
	if (!eq(origin.w, 1))
	{
		ft_puterror(ERROR_RAY, ": origin should be a point");
		return (rt);
	}
	if (!eq(direction.w, 0))
	{
		ft_puterror(ERROR_RAY, ": direction should be a vector");
		return (rt);
	}
	rt.ray.origin = origin;
	rt.ray.direction = tuple_normalize(direction);
	rt.itr_front.t = __DBL_MAX__;
	rt.itr_back.t = -__DBL_MAX__;
	return (rt);
}

t_tuple	position(t_ray ray, double t)
{
	return (tuple_add(ray.origin, tuple_mul(t, ray.direction)));
}

t_intersection intersection(t_shape geometric_figure_id, double t, void * figure)
{
	t_intersection itr;

	ft_memset(&itr, 0, sizeof (itr));
	if (geometric_figure_id < SPHERE_ID || geometric_figure_id > MAX_ID)
	{
		ft_puterror(ERROR_INTERSECTION, ": unvalid geometric figure");
		itr.id = MAX_ID + 1;
		return (itr);
	}
	itr.id = geometric_figure_id;
	itr.t = t;
	if (itr.id == SPHERE_ID)
		itr.sp = (t_sphere *)figure;
	return (itr);
}

t_ray	matrix_ray(const t_matrix *m, const t_ray *ray)
{
	t_ray	r;

	r.origin = matrix_vect(*m, ray->origin);
	r.direction = matrix_vect(*m, ray->direction);
	return (r);
}
