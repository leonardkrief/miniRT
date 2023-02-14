/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:59:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 00:39:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_window	*window(t_window *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (NULL);
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_NAME);
	if (window->win == NULL)
	{
		FREE_DISPLAY(window->mlx);
		return (NULL);
	}
	return (window);
}

t_image	*image(t_image *image, void *mlx)
{
	image->mlx = mlx;
	image->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (image->img == NULL)
		return (NULL);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel),
			&(image->line_length), &(image->endian));
	image->origin = point(0, 0, -3);
	image->extension = vector(2, 2, 0);
	return (image);
}

t_canvas	*canvas(t_canvas *canvas)
{
	if (window(&canvas->window) == NULL)
		return (NULL);
	if (image(&canvas->image, canvas->window.mlx) == NULL)
	{
		free_window(&canvas->window);
		return (NULL);
	}
	return (canvas);
}

void	put_pixel(t_image *img, int x, int y, t_pixel pixel)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)pixel;
}
