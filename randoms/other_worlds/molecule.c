/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   molecule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:41:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 13:45:55 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	world_molecule(void)
{
	t_world			w;
	t_object_list	*elem;
	t_matrix		scale;

	ft_memset(&w, 0, sizeof(t_world));
	w.lights[0] = light_point(point(5, 0, -5), tmp_pixel(1, 1, 1, 0));
	w.nb_lights++;
	elem = new_object(SPHERE_ID);
	if (elem == NULL)
		return (ft_puterror(FAILED_CREATING_OBJECT, (char *)__func__), w);
	((t_sphere *)elem->ob)->mat.color = tmp_pixel(1, 0.2, 0.2, 0);
	((t_sphere *)elem->ob)->mat.diffuse = 0.8;
	((t_sphere *)elem->ob)->mat.specular = 0.6;
	ft_lstadd_front(&w.objs, elem);
	elem = new_object(SPHERE_ID);
	if (elem == NULL)
		return (ft_puterror(FAILED_CREATING_OBJECT, (char *)__func__), w);
	scale = matrix_matrix(matrix_translation(1, 0, -0.5), matrix_scaling(0.5, 0.5, 0.5), 4);
	transform_sp(((t_sphere *)elem->ob), &scale);
	ft_lstadd_front(&w.objs, elem);
	return (w);
}