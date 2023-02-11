/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:40:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 05:38:51 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_computations	prepare_computations(const t_ray *ray, const t_intersection *itr)
{
	t_computations	comps;

	ft_memset(&comps, 0, sizeof(comps));
	comps.t = itr->t;
	comps.id = itr->id;
	comps.ob = itr->ob;
	comps.point = position(*ray, comps.t);
	comps.eye = tuple_neg(ray->direction);
	comps.normal = normal_at(comps.id, comps.ob, comps.point);
	if (tuple_dotprod(comps.normal, comps.eye) < 0)
	{
		comps.inside = true;
		comps.normal = tuple_neg(comps.normal);
	}
	else
		comps.inside = false;
	return (comps);
}

t_tmp_pixel	shade_hit(const t_world *w, const t_computations *c)
{
	size_t	i;
	t_tmp_pixel	color;

	i = 0;
	ft_memset(&color, 0, sizeof(color));
	if (c->id == SPHERE_ID)
	{
		while (i < w->nb_lights)
			color = tmp_pixel_add(color, lighting(((t_sphere *)(c->ob))->mat,
						w->lights[i++], c->point, c->eye, c->normal));
		return (color);
	}
	// else if (c->id == PLANE_ID)
	// 	return (lighting(((t_plane *)(c->ob))->mat, w->lights[0], c->point, c->eye, c->normal));
	// else if (c->id == CYLINDER_ID)
	// 	return (lighting(((t_cylinder *)(c->ob))->mat, w->lights[0], c->point, c->eye, c->normal));
	// else if (c->id == TRIANGLE_ID)
	// 	return(lighting(((t_triangle *)(c->ob))->mat, w->lights[0], c->point, c->eye, c->normal));
	else
		return (tmp_pixel(TMP_PIXEL_BLACK, 0));
}

t_pixel	color_at(const t_world *w, const t_ray *ray)
{
	t_computations	c;
	t_tmp_pixel		tmp_p;

	intersect_world(w, ray);
	if (ray->itr_front == NULL)
		return (pixel(PIXEL_BLACK, 0));
	c = prepare_computations(ray, ray->itr_front);
	tmp_p = shade_hit(w, &c);
	return (tmp_pixel_to_pixel(tmp_p));
}