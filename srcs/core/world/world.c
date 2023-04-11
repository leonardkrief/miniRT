/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:06:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:11:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	world(void)
{
	t_world			w;
	t_light			l;
	t_object_list	*elem;

	ft_memset(&w, 0, sizeof(t_world));
	l = light_point(point(-10, 10, -10), tmp_pixel(TMP_PIXEL_WHITE));
	world_add_light(&w, l);
	elem = new_object(SPHERE_ID);
	if (elem == NULL)
		return (ft_puterror(FAILED_CREATING_OBJECT, (char *)__func__), w);
	((t_sphere *)elem->ob)->mat.color = tmp_pixel(0.8, 1, 0.6, 0);
	((t_sphere *)elem->ob)->mat.diffuse = 0.7;
	((t_sphere *)elem->ob)->mat.specular = 0.2;
	ft_lstadd_front(&w.objs, elem);
	elem = new_object(SPHERE_ID);
	if (elem == NULL)
		return (ft_puterror(FAILED_CREATING_OBJECT, (char *)__func__), w);
	transform_sp(((t_sphere *)elem->ob), matrix_scaling(0.5, 0.5, 0.5));
	ft_lstadd_front(&w.objs, elem);
	return (w);
}

void	intersect_world(const t_world *world, const t_ray *ray)
{
	t_object_list	*objs;

	objs = world->objs;
	while (objs)
	{
		if (objs->id == SPHERE_ID)
			intersect_sp(objs->ob, (t_ray *)ray);
		else if (objs->id == PLANE_ID)
			intersect_pl(objs->ob, (t_ray *)ray);
		else if (objs->id == CYLINDER_ID)
			intersect_cy(objs->ob, (t_ray *)ray);
		else
			ft_puterror(UNKNOWN_OBJECT, (char *)__func__);
		objs = objs->next;
	}
}

void	free_world(t_world *world)
{
	ft_lstclear(&world->objs, free);
}
