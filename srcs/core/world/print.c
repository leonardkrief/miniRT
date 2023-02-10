/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:51:18 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/09 16:22:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	world_print(t_world *world)
{
	size_t i;
	char light_id[] = "spot _:   ";

	i = 0;
	while (i < world->nb_lights)
	{
		light_id[5] = i + '0';
		light_print(&world->lights[i], light_id);
		i++;
	}
	ft_lstprint(world->objs);
}