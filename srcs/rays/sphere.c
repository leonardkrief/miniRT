/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:04:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 07:49:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_sphere	*sphere(t_tuple origin, double radius)
{
	t_sphere	*sp;

	if (!eq(origin.w, 1))
	{
		ft_puterror(ERROR_SPHERE, ": origin should be a point");
		return (NULL);
	}
	if (radius <= 0)
	{
		ft_puterror(ERROR_SPHERE, ": radius should be positive");
		return (NULL);
	}
	sp = ft_calloc(1, sizeof (*sp));
	if (sp == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return (NULL);
	}
	sp->origin = origin;
	sp->radius = radius;
	sp->m = matrix_identity();
	return (sp);
}

void	transform_sp(t_sphere *sp, const t_matrix *m)
{
	sp->m = matrix_matrix(sp->m, matrix_invert(*m, 4), 4);
}

void	intersection_sp(t_raytracer *rt, const t_sphere *sp)
{
	t_tuple			sp_to_ray;
	double			q[4];
	t_intersection	itr[2];
	t_ray			ray;

	ray = matrix_ray(&sp->m, &rt->ray);
	sp_to_ray = tuple_sub(ray.origin, sp->origin);
	q[0] = dotprod(ray.direction, ray.direction);
	q[1] = 2 * dotprod(ray.direction, sp_to_ray);
	q[2] = dotprod(sp_to_ray, sp_to_ray) - 1;
	q[3] = q[1] * q[1] - 4 * q[0] * q[2];
	if (q[3] >= 0)
	{
		itr[0] = intersection(SPHERE_ID, (double)(-q[1] - sqrt(q[3])) / (double)(2 * q[0]), (void *)sp);
		itr[1] = intersection(SPHERE_ID, (double)(-q[1] + sqrt(q[3])) / (double)(2 * q[0]), (void *) sp);
		if (itr[1].t < 0 && itr[1].t > rt->itr_back.t)
			rt->itr_back = itr[1];
		else if (itr[0].t > 0 && itr[0].t < rt->itr_front.t)
			rt->itr_front = itr[0];
		else
		{
			if (itr[1].t > 0 && itr[1].t < rt->itr_front.t)
				rt->itr_front = itr[1];
			if (itr[0].t < 0 && itr[0].t > rt->itr_back.t)
				rt->itr_back = itr[0];
		}
	}
}
