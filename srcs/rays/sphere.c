/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:04:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 03:28:14 by lkrief           ###   ########.fr       */
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
	return (sp);
}

void	intersection_sp(t_ray *ray, const t_sphere *sp)
{
	t_tuple			sp_to_ray;
	double			q[3];
	double			delta; // possible de stocker delta dans q pour sauver une ligne
	t_intersection	itr[2];

	sp_to_ray = tuple_sub(ray->origin, sp->origin);
	q[0] = dotprod(ray->direction, ray->direction);
	q[1] = 2 * dotprod(ray->direction, sp_to_ray);
	q[2] = dotprod(sp_to_ray, sp_to_ray) - 1;
	delta = q[1] * q[1] - 4 * q[0] * q[2];
	if (delta >= 0)
	{
		itr[0] = intersection(SPHERE_ID, -q[1] - sqrt(delta) / (2 * q[0]), (void *)sp);
		itr[1] = intersection(SPHERE_ID, -q[1] + sqrt(delta) / (2 * q[0]), (void *) sp);
		if (itr[1].t < 0 && itr[1].t > ray->itr_back.t)
			ray->itr_back = itr[1];
		else if (itr[0].t > 0 && itr[1].t < ray->itr_front.t)
			ray->itr_front = itr[0];
		else
		{
			if (itr[1].t > 0 && itr[1].t < ray->itr_front.t)
				ray->itr_front = itr[1];
			if (itr[0].t < 0 && itr[0].t > ray->itr_back.t)
				ray->itr_back = itr[0];
		}
	}
}