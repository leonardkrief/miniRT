/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:38:57 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/01 02:57:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

// After transforming the point from world space to object
// space (1st matrix_vect call), we should get the normal vector
// of the sphere at this point. But as the point was transformed
// to object space, origin of the sphere stays 0,0,0 so the
// calculation should be tuple_sub(point, point(0,0,0)) which achieves
// exactly the same as writing point.w = 0.
void	intersect_cy(const t_cylinder *cy, t_ray *ray0)
{
	t_tuple			cy_to_ray;
	double			q[4];
	t_ray			ray;

	ray = matrix_ray(&cy->m, ray0);
	// local_intersect_at starts_here
	cy_to_ray = tuple_sub(ray.origin, point(0, 0, 0));
	q[0] = ray.direction.x * ray.direction.x
			+ ray.direction.z * ray.direction.z;
	if (eq(q[0], 0))
		return ;
	q[1] = 2 * ray.origin.x * ray.direction.x
			+ 2 * ray.origin.z * ray.direction.z;
	q[2] = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	q[3] = q[1] * q[1] - 4 * q[0] * q[2];
	if (q[3] >= 0)
		verify_intersections_sp(q, ray0, sp);
}