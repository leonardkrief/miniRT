/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:38:57 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:18:48 by lkrief           ###   ########.fr       */
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
