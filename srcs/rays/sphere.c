/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:04:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 20:52:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	intersection_sp(t_raytracer *rt, const t_sphere *sp)
{
	t_tuple			sp_to_ray;
	double			q[4];
	t_intersection	itr[2];
	t_ray			ray;

	ray = matrix_ray(&sp->m, &rt->ray);
	sp_to_ray = tuple_sub(ray.origin, sp->origin);
	q[0] = tuple_dotprod(ray.direction, ray.direction);
	q[1] = 2 * tuple_dotprod(ray.direction, sp_to_ray);
	q[2] = tuple_dotprod(sp_to_ray, sp_to_ray) - 1;
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

// After tranbsforming the point from world space to object
// space (1st matrix_vect call), we should get the normal vector
// of the sphere at this point. But as the point was transformed
// to object space, origin of the sphere stays 0,0,0 so the
// calculation should be tuple_sub(point, point(0,0,0)) which achieves
// exactly the same as writing point.w = 0.
