/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:04:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:15:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

// local_normal_at always returns a vector (0, 1, 0) here
// Normally, I should first transform point to object space
// through m then apply local_normal_at then get back to world space
// through t_m. but to save computations, I dont transform to
// object space and just return the vector (0, 1, 0) in world space
t_tuple	normal_at_pl(const t_plane *pl, t_tuple point)
{
	t_tuple	world_normal;

	(void)point;
	world_normal = matrix_vect(pl->t_m, vector(0, 1, 0));
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}

void	intersect_pl(const t_plane *pl, t_ray *ray0)
{
	t_intersection	*itr;
	t_ray			ray;

	ray = matrix_ray(&pl->m, ray0);
	if (eq(ray.origin.y, 0) || eq(ray.direction.y, 0))
		return ;
	itr = intersection(PLANE_ID, (t_object *)pl);
	if (itr)
	{
		itr->t = -ray.origin.y / ray.direction.y;
		add_intersection_to_ray(ray0, itr);
	}
	else
		ft_puterror(FAILED_MALLOC, (char *)__func__);
}
