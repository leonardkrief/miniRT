/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 03:26:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ft_memset(&ray, 0, sizeof(ray));
	if (!eq(origin.w, 1))
	{
		ft_puterror(ERROR_RAY, ": origin should be a point");
		return (ray);
	}
	if (!eq(direction.w, 0))
	{
		ft_puterror(ERROR_RAY, ": direction should be a vector");
		return (ray);
	}
	ray.origin = origin;
	ray.direction = normalize(direction);
	ray.itr_front.t = INT_MAX;
	ray.itr_back.t = INT_MIN;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	return (tuple_add(ray.origin, tuple_mul(t, ray.direction)));
}

t_intersection intersection(t_geometric_figure geometric_figure_id, double t, void * figure)
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