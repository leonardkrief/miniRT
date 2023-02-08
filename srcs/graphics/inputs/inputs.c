/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:44:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/08 06:53:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	input_key_camera_translation(int keysym, t_canvas *cvs)
{
	// double	d;

	(void)cvs;
	(void)keysym;
	// printf("key: %d", keysym);
	// d = 20 * (cvs->image.origin) / WIDTH;
	// set_point(&a, 0, 0);
	// if (keysym == 65361)
	// 	set_point(&a, -d, 0);
	// else if (keysym == 65363)
	// 	set_point(&a, d, 0);
	// else if (keysym == 65364)
	// 	set_point(&a, 0, -d);
	// else if (keysym == 65362)
	// 	set_point(&a, 0, d);
	// translate_img(vars->img, a, vars->fractal);
	// fractal_to_img(vars->img, vars->fractal, vars);
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	// return (0);
}

void	input_key_close_window(int keysym, t_canvas *cvs)
{
	if (keysym == KEY_ESC || keysym == CLOSE_WINDOW_KEY_EVENT)
		mlx_loop_end(cvs->window.mlx);
}

int	input_key(int keysym, t_canvas *cvs)
{
	input_key_camera_translation(keysym, cvs);
	input_key_close_window(keysym, cvs);
	return (0);
}

int	input_mouse(int mousesym, int x, int y, t_canvas *cvs)
{
	(void)cvs;
	printf("mouse click: %d, x: %d, y: %d\n", mousesym, x, y);
	fflush(stdout);
	if (mousesym == MOUSE_ZOOM_IN || mousesym == MOUSE_ZOOM_OUT)
	{
		// zoom in & out
	}
	return (0);
}
