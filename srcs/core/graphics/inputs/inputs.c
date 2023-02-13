/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:44:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 18:29:05 by lkrief           ###   ########.fr       */
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
	else if (keysym == KEY_SLASH)
		camera_transform(args->camera, matrix_rotation_z(r_tick));
	else if (keysym == KEY_PLUS)
		camera_transform(args->camera, matrix_rotation_z(-r_tick));
	render(args->canvas, args->camera, args->world);
	mlx_put_image_to_window(args->canvas->window.mlx,
			args->canvas->window.win, args->canvas->image.img, 0, 0);
}

void	input_key_close_window(int keysym, t_all *args)
{
	if (keysym == KEY_ESC || keysym == CLOSE_WINDOW_BUTTON_EVENT)
		exit_program(args);
}

int	input_key(int keysym, t_all *args)
{
	static int	count;

	count++;
	printf("(%d) pressed key: %3d\n", count, keysym);
	input_key_camera_movements(keysym, args);
	input_key_close_window(keysym, args);
	return (0);
}

int	input_mouse(int mousesym, int i, int j, t_all *args)
{
	(void)args;
	static int	count;

	count++;
	printf("(%d) mouse click: %d  i: %d  j: %d\n", count, mousesym, i, j);
	
	t_ray	r = ray_for_pixel(args->camera, i, j);
	t_pixel	color = color_at(args->world, &r);
	printf("     %d %d %d\n\n", pixel_get_r(color), pixel_get_g(color), pixel_get_b(color));

	fflush(stdout);
	return (0);
}
