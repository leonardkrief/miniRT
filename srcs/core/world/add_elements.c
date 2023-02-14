/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:14:20 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 00:52:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	world_add_light(t_world *world, t_light light)
{
	if (world->nb_lights >= MAX_LIGHTS)
		printf("Lights limit reached. You cannot put more than %d lights.\n",
			MAX_LIGHTS);
	else
	{
		world->lights[world->nb_lights] = light;
		world->nb_lights++;
	}
}

void	world_add_sphere(t_world *world, t_sphere *sp)
{
	t_object_list	*new;

	new = ft_lstnew(sp, SPHERE_ID);
	if (new == NULL)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__));
	ft_lstadd_front(&world->objs, new);
}

void	world_add_plane(t_world *world, t_plane *pl)
{
	t_object_list	*new;

	new = ft_lstnew(pl, PLANE_ID);
	if (new == NULL)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__));
	ft_lstadd_front(&world->objs, new);
}

t_object_list	*new_object(const int id)
{
	t_object_list	*new;
	void			*obj;

	obj = NULL;
	new = NULL;
	if ((unsigned int)id < MIN_ID || (unsigned int)id > MAX_ID)
		return (ft_puterror(UNKNOWN_OBJECT, (char *)__func__), NULL);
	if (id == SPHERE_ID)
		obj = sphere();
	else if (id == PLANE_ID)
		obj = plane();
	// else if (id == CYLINDER_ID)
	// 	obj = cylinder();
	// else if (id == TRIANGLE_ID)
	// 	obj = triangle();
	if (obj == NULL)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__), NULL);
	if (id == SPHERE_ID)
		new = ft_lstnew(obj, SPHERE_ID);
	else if (id == PLANE_ID)
		new = ft_lstnew(obj, PLANE_ID);
	// else if (id == CYLINDER_ID)
	// 	new = ft_lstnew(obj, CYLINDER_ID);
	// else if (id == TRIANGLE_ID)
	// 	new = ft_lstnew(obj, TRIANGLE_ID);
	if (new == NULL)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__), NULL);
	return (new);
}
