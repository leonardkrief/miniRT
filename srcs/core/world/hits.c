/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:40:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 17:23:53 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_computations	prepare_computations(const t_ray *ray,
										const t_intersection *itr)
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
	comps.over_point = tuple_add(comps.point, tuple_mul(EPSILON, comps.normal));
	return (comps);
}

bool	is_shadowed(const t_world *w, const t_tuple point, const t_light *light)
{
	t_tuple	v;
	double	distance;
	t_ray	r;

	v = tuple_sub(light->position, point);
	distance = tuple_modulus(v);
	r = ray(point, tuple_normalize(v));
	intersect_world(w, &r);
	if (r.itr_front && r.itr_front->t < distance)
		return (true);
	return (false);
}

t_tmp_pixel	shade_hit(const t_world *w, const t_computations *c)
{
	size_t		i;
	t_tmp_pixel	color;
	t_material	*mat;

	i = 0;
	ft_memset(&color, 0, sizeof(color));
	if (c->id == SPHERE_ID)
		mat = &((t_sphere *)(c->ob))->mat;
	else if (c->id == PLANE_ID)
		mat = &((t_plane *)(c->ob))->mat;
	else
		return (tmp_pixel(TMP_PIXEL_BLACK));
	while (i < w->nb_lights)
	{
		color = tmp_pixel_add(color, lighting(c, mat, &w->lights[i],
					is_shadowed(w, c->over_point, &w->lights[i])));
		i++;
	}
	return (color);
}

t_tmp_pixel	lighting(const t_computations *c, const t_material *mat,
									const t_light *light, bool in_shadow)
{
	t_tmp_pixel	effective_color;
	t_tmp_pixel	ambient;
	t_tuple		lightv;
	double		light_dot_normal;
	t_tmp_pixel	diffuse;

	if (mat->pattern.f == NULL)
		effective_color = tmp_pixel_mul(mat->color, light->intensity);
	else
		effective_color = tmp_pixel_mul(pattern_at(c->ob, c->id, mat, c),
				light->intensity);
	ambient = tmp_pixel_mul(c->world->ambient, effective_color);
	if (in_shadow)
		return (ambient);
	lightv = tuple_normalize(tuple_sub(light->position, c->over_point));
	light_dot_normal = tuple_dotprod(lightv, c->normal);
	if (light_dot_normal < 0)
		return (ambient);
	else
	{
		diffuse = tmp_pixel_scal(mat->diffuse * light_dot_normal,
				effective_color);
		return (tmp_pixel_add(ambient,
				point_in_front_light(c, mat, light, diffuse)));
	}
}

// I was forced to recalculate the lightv vector because of this stupid
// 4 arguments limit rule
t_tmp_pixel	point_in_front_light(const t_computations *c, const t_material *mat,
				const t_light *light, t_tmp_pixel diffuse)
{
	t_tuple		lightv;
	t_tmp_pixel	specular;
	double		factor;
	t_tuple		reflectv;
	double		reflect_dot_eye;

	lightv = tuple_normalize(tuple_sub(light->position, c->over_point));
	reflectv = tuple_reflect(tuple_neg(lightv), c->normal);
	reflect_dot_eye = tuple_dotprod(reflectv, c->eye);
	if (reflect_dot_eye <= 0)
		specular = tmp_pixel(TMP_PIXEL_BLACK);
	else
	{
		factor = powf(reflect_dot_eye, mat->shininess);
		specular = tmp_pixel_scal(mat->specular * factor, light->intensity);
	}
	return (tmp_pixel_add(diffuse, specular));
}

t_pixel	color_at(const t_world *w, const t_ray *ray)
{
	t_computations	c;
	t_tmp_pixel		tmp_p;

	intersect_world(w, ray);
	if (ray->itr_front == NULL)
		return (pixel(PIXEL_BLACK));
	c.world = (t_world *)w;
	c = prepare_computations(ray, ray->itr_front);
	tmp_p = shade_hit(w, &c);
	return (tmp_pixel_to_pixel(tmp_p));
}
