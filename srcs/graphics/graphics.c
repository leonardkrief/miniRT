/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:59:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 20:55:38 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_window	*window(t_window *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (NULL);
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	if (window->win == NULL)
	{
		free(window->mlx);
		return (NULL);
	}
	return (window);
}

t_image	*image(t_image *img, void *mlx)
{
	img->mlx = mlx;
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
					&(img->line_length), &(img->endian));
	return (img);
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
	*(unsigned int *)dst =
		(*(int *)(unsigned char [4]){pixel.b, pixel.g, pixel.r, pixel.a});
}
