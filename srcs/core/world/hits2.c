/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:40:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/11 12:30:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_pixel	color_at(const t_world *w, const t_ray *ray)
{
	t_computations	c;
	t_tmp_pixel		tmp_p;

	intersect_world(w, ray);
	if (ray->itr_front == NULL)
		return (pixel(0, 0, 0, 0));
	c = prepare_computations(ray, ray->itr_front);
	c.world = (t_world *)w;
	tmp_p = shade_hit(w, &c);
	return (tmp_pixel_to_pixel(tmp_p));
}
