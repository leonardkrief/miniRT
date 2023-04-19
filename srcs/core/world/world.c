/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:06:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/11 12:32:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

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
