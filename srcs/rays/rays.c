/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:24:29 by lkrief           ###   ########.fr       */
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
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	return (tuple_add(ray.origin, tuple_mul(t, ray.direction)));
}