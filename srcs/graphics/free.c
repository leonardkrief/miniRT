/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:41:24 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:48:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	free_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	free(window->mlx);
}

void	free_image(t_image *image)
{
	mlx_destroy_image(image->mlx, image->img);
}

void	free_canvas(t_canvas *canvas)
{
	free_image(&canvas->image);
	free_window(&canvas->window);
}
