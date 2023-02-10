/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:04:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 02:18:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static void	verify_intersections_sp(const double *q, t_ray *ray,
				const t_sphere *sp)
{
	t_intersection	*itr1;
	t_intersection	*itr2;

	itr1 = intersection(SPHERE_ID, (t_object *)sp);
	if (itr1)
	{
		itr1->t = (double)(-q[1] - sqrt(q[3])) / (double)(2 * q[0]);
		add_intersection_to_ray(ray, itr1);
	}
	else
		ft_puterror(FAILED_MALLOC, (char *)__func__);
	itr2 = intersection(SPHERE_ID, (t_object *)sp);
	if (itr2)
	{
		itr2->t = (double)(-q[1] + sqrt(q[3])) / (double)(2 * q[0]);
		if (itr2->t != itr1->t) // If the 2 intersections are the same, we only keep one ?
			add_intersection_to_ray(ray, itr2);
		else
			free(itr2);
	}
	else
		ft_puterror(FAILED_MALLOC, (char *)__func__);
}

// After tranbsforming the point from world space to object
// space (1st matrix_vect call), we should get the normal vector
// of the sphere at this point. But as the point was transformed
// to object space, origin of the sphere stays 0,0,0 so the
// calculation should be tuple_sub(point, point(0,0,0)) which achieves
// exactly the same as writing point.w = 0.
void	intersect_sp(const t_sphere *sp, t_ray *ray0)
{
	t_tuple			sp_to_ray;
	double			q[4];
	t_ray			ray;

	ray = matrix_ray(&sp->m, ray0);
	sp_to_ray = tuple_sub(ray.origin, point(0, 0, 0));
	q[0] = tuple_dotprod(ray.direction, ray.direction);
	q[1] = 2 * tuple_dotprod(ray.direction, sp_to_ray);
	q[2] = tuple_dotprod(sp_to_ray, sp_to_ray) - 1;
	q[3] = q[1] * q[1] - 4 * q[0] * q[2];
	if (q[3] >= 0)
		verify_intersections_sp(q, ray0, sp);
}



// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sphere.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/06 02:04:01 by lkrief            #+#    #+#             */
// /*   Updated: 2023/02/09 18:12:31 by lkrief           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "raytracer.h"

// static void	verify_intersections(const double *q, t_raytracer *rt,
// 				const t_sphere *sp)
// {
// 	t_intersection	itr[2];

// 	itr[0] = intersection(SPHERE_ID, (double)(-q[1] - sqrt(q[3]))
// 			/ (double)(2 * q[0]), (void *)sp);
// 	itr[1] = intersection(SPHERE_ID, (double)(-q[1] + sqrt(q[3]))
// 			/ (double)(2 * q[0]), (void *) sp);
// 	if (itr[1].t < 0 && itr[1].t > rt->itr_back.t)
// 		rt->itr_back = itr[1];
// 	else if (itr[0].t > 0 && itr[0].t < rt->itr_front.t)
// 		rt->itr_front = itr[0];
// 	else
// 	{
// 		if (itr[1].t > 0 && itr[1].t < rt->itr_front.t)
// 			rt->itr_front = itr[1];
// 		if (itr[0].t < 0 && itr[0].t > rt->itr_back.t)
// 			rt->itr_back = itr[0];
// 	}
// }

// // After tranbsforming the point from world space to object
// // space (1st matrix_vect call), we should get the normal vector
// // of the sphere at this point. But as the point was transformed
// // to object space, origin of the sphere stays 0,0,0 so the
// // calculation should be tuple_sub(point, point(0,0,0)) which achieves
// // exactly the same as writing point.w = 0.
// void	intersection_sp(t_raytracer *rt, const t_sphere *sp)
// {
// 	t_tuple			sp_to_ray;
// 	double			q[4];
// 	t_ray			ray;

// 	ray = matrix_ray(&sp->m, &rt->ray);
// 	sp_to_ray = tuple_sub(ray.origin, sp->origin);
// 	q[0] = tuple_dotprod(ray.direction, ray.direction);
// 	q[1] = 2 * tuple_dotprod(ray.direction, sp_to_ray);
// 	q[2] = tuple_dotprod(sp_to_ray, sp_to_ray) - 1;
// 	q[3] = q[1] * q[1] - 4 * q[0] * q[2];
// 	if (q[3] >= 0)
// 		verify_intersections(q, rt, sp);
// }