/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:44:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/19 15:11:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int	input_key_camera_movements_aux(t_input keysym, t_all *arg,
		const double t, const double r)
{
	if (keysym == KEY_Z)
		return (camera_transform(arg->camera, matrix_translation(0, 0, t)), 0);
	else if (keysym == KEY_S)
		return (camera_transform(arg->camera, matrix_translation(0, 0, -t)), 0);
	else if (keysym == KEY_Q)
		return (camera_transform(arg->camera, matrix_translation(-t, 0, 0)), 0);
	else if (keysym == KEY_D)
		return (camera_transform(arg->camera, matrix_translation(t, 0, 0)), 0);
	else if (keysym == KEY_X)
		return (camera_transform(arg->camera, matrix_translation(0, -t, 0)), 0);
	else if (keysym == KEY_W)
		return (camera_transform(arg->camera, matrix_translation(0, t, 0)), 0);
	else if (keysym == KEY_UP)
		return (camera_transform(arg->camera, matrix_rotation_x(-r)), 0);
	else if (keysym == KEY_DOWN)
		return (camera_transform(arg->camera, matrix_rotation_x(r)), 0);
	else if (keysym == KEY_RIGHT)
		return (camera_transform(arg->camera, matrix_rotation_y(r)), 0);
	else if (keysym == KEY_LEFT)
		return (camera_transform(arg->camera, matrix_rotation_y(-r)), 0);
	else if (keysym == KEY_SLASH)
		return (camera_transform(arg->camera, matrix_rotation_z(r)), 0);
	else if (keysym == KEY_PLUS)
		return (camera_transform(arg->camera, matrix_rotation_z(-r)), 0);
	return (1);
}

void	input_key_camera_movements(t_input keysym, t_all *args)
{
	double	t_tick;
	double	r_tick;

	t_tick = CAMERA_TRANSLATION_SENSITIVITY;
	r_tick = CAMERA_ROTATION_SENSITIVITY;
	if (input_key_camera_movements_aux(keysym, args, t_tick, r_tick) == 0)
	{
		render(args->canvas, args->camera, args->world);
		mlx_put_image_to_window(args->canvas->window.mlx,
			args->canvas->window.win, args->canvas->image.img, 0, 0);
	}
}

void	input_key_close_window(t_input keysym, t_all *args)
{
	if (keysym == KEY_ESC || keysym == CLOSE_WINDOW_BUTTON_EVENT)
		exit_program(args);
}

int	input_key(t_input keysym, t_all *args)
{
	static int	count;

	count++;
	printf("(%d) pressed key: %3d\n", count, keysym);
	input_key_camera_movements(keysym, args);
	input_key_close_window(keysym, args);
	return (0);
}

int	input_mouse(t_input mousesym, int i, int j, t_all *args)
{
	static int	count;
	t_ray		r;
	t_pixel		color;

	(void)args;
	count++;
	printf("(%d) mouse click: %d  i: %d  j: %d\n", count, mousesym, i, j);
	r = ray_for_pixel(args->camera, i, j);
	color = color_at(args->world, &r);
	printf("     %d %d %d\n\n", pixel_get_r(color), pixel_get_g(color),
		pixel_get_b(color));
	fflush(stdout);
	return (0);
}
