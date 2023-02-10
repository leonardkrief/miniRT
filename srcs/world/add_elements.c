/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:14:20 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 05:26:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	world_add_light(t_world *world, t_light *light)
{
	if (world->nb_lights >= MAX_LIGHTS)
		printf("Lights limit reached. You cannot put more than %d lights.\n",
				MAX_LIGHTS);
	else
	{
		world->lights[world->nb_lights] = *light;
		world->nb_lights++;
	}
}

void	world_add_sphere(t_world *world, t_sphere *sp)
{
	t_object_list *new;

	new = ft_lstnew(sp, SPHERE_ID);
	if (new == NULL)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__));
	ft_lstadd_front(&world->objs, new);
}