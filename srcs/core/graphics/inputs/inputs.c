/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:44:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 00:18:25 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "world.h"

void	input_key_camera_movements(int keysym, t_all *args)
{
	(void)keysym;
	(void)args;
	// if (keysym == KEY_Z)
	// 	cvs->camera->origin.y += 10;
	// else if (keysym == KEY_S)
	// 	cvs->camera->origin.y -= 10;
	// else if (keysym == KEY_Q)
	// 	cvs->camera->origin.x -= 10;
	// else if (keysym == KEY_D)
	// 	cvs->camera->origin.x += 10;
	// else if (keysym == KEY_UP)
	// 	cvs->camera->origin.z += 10;
	// else if (keysym == KEY_DOWN)
	// 	cvs->camera->origin.z -= 10;
	// else if (keysym == KEY_LEFT)
	// 	cvs->camera->orientation.y += 0.1;
	// else if (keysym == KEY_RIGHT)
	// 	cvs->camera->orientation.y -= 0.1;
	// else
	// 	return ;
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

void	input_key_close_window(int keysym, t_all *args)
{
	if (keysym == KEY_ESC || keysym == CLOSE_WINDOW_BUTTON_EVENT)
		exit_program(args);
}

int	input_key(int keysym, t_all *args)
{
	printf("pressed key: %3d\n", keysym);
	input_key_camera_movements(keysym, args);
	input_key_close_window(keysym, args);
	return (0);
}

int	input_mouse(int mousesym, int i, int j, t_all *args)
{
	t_canvas	*cvs;

	cvs = args->canvas;
	printf("mouse click: %3d  i: %d  j: %d\n", mousesym, i, j);
	t_tuple t = pixel_to_point(&cvs->image, i, j);
	printf("                  x: %f  y: %f\n", t.x, t.y);
	fflush(stdout);
	if (mousesym == MOUSE_ZOOM_IN || mousesym == MOUSE_ZOOM_OUT)
	{
		// zoom in & out
	}
	return (0);
}
