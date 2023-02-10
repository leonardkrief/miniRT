/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:41:24 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 23:18:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "world.h"

void	free_window(const t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	FREE_DISPLAY(window->mlx);
	free(window->mlx);
}

void	free_image(const t_image *image)
{
	mlx_destroy_image(image->mlx, image->img);
}

int	free_canvas(const t_canvas *canvas)
{
	free_image(&canvas->image);
	free_window(&canvas->window);
	return (0);
}

// devra prendre plus qu'un canvas plus tard mais ok pour l'instant
int	exit_program(t_all *args)
{
	free_canvas(args->canvas);
	free_world(args->world);
	exit (0);
}
