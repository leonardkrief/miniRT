/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 12:18:37 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_ray	ray(const t_tuple origin, const t_tuple direction)
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
	ray.direction = tuple_normalize(direction);
	ray.itr_front = NULL;
	ray.itr_back = NULL;
	return (ray);
}

t_tuple	position(const t_ray ray, const double t)
{
	return (tuple_add(ray.origin, tuple_mul(t, ray.direction)));
}

t_ray	matrix_ray(const t_matrix *m, const t_ray *ray)
{
	t_ray	r;

	r.origin = matrix_vect(*m, ray->origin);
	r.direction = matrix_vect(*m, ray->direction);
	r.itr_front = ray->itr_front;
	r.itr_back = ray->itr_back;
	return (r);
}
