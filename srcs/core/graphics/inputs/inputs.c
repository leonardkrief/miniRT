/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:44:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 17:21:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	input_key_camera_movements(int keysym, t_all *args)
{
	double	t_tick;
	double	r_tick;

	t_tick = CAMERA_TRANSLATION_SENSITIVITY;
	r_tick = CAMERA_ROTATION_SENSITIVITY;
	if (keysym == KEY_Z)
		camera_transform(args->camera, matrix_translation(0, 0, t_tick));
	else if (keysym == KEY_S)
		camera_transform(args->camera, matrix_translation(0, 0, -t_tick));
	else if (keysym == KEY_Q)
		camera_transform(args->camera, matrix_translation(-t_tick, 0, 0));
	else if (keysym == KEY_D)
		camera_transform(args->camera, matrix_translation(t_tick, 0, 0));
	else if (keysym == KEY_UP)
		camera_transform(args->camera, matrix_rotation_x(-r_tick));
	else if (keysym == KEY_DOWN)
		camera_transform(args->camera, matrix_rotation_x(r_tick));
	else if (keysym == KEY_RIGHT)
		camera_transform(args->camera, matrix_rotation_y(r_tick));
	else if (keysym == KEY_LEFT)
		camera_transform(args->camera, matrix_rotation_y(-r_tick));
	render(args->canvas, args->camera, args->world);
	mlx_put_image_to_window(args->canvas->window.mlx, args->canvas->window.win, args->canvas->image.img, 0, 0);
}

void	input_key_close_window(int keysym, t_all *args)
{
	if (keysym == KEY_ESC || keysym == CLOSE_WINDOW_BUTTON_EVENT)
		exit_program(args);
}

int	input_key(int keysym, t_all *args)
{
	int static count;

	count++;
	printf("(%d) pressed key: %3d\n", count, keysym);
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
