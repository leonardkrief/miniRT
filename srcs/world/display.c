/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:38:29 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 00:21:07 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	all(t_all *args, t_canvas *cvs, t_camera *c, t_world *w)
{
	args->canvas = cvs;
	args->camera = c;
	args->world = w;
}

void	display_loop(t_all *args)
{
	t_canvas	*cvs;
	t_camera	*c;
	t_world		*w;

	cvs = args->canvas;
	c = args->camera;
	w = args->world;
	render(cvs, c, w);
	mlx_put_image_to_window(cvs->window.mlx, cvs->window.win, cvs->image.img, 0, 0);
	mlx_key_hook(cvs->window.win, &input_key, args);
	mlx_hook(cvs->window.win, CLOSE_WINDOW_BUTTON_EVENT, 0, &exit_program, args);
	mlx_mouse_hook(cvs->window.win, &input_mouse, args);
	mlx_loop(cvs->window.mlx);
}