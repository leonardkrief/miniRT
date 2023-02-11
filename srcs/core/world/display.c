/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:38:29 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 15:37:41 by lkrief           ###   ########.fr       */
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
	// mlx_key_hook(cvs->window.win, &input_key, args);
	mlx_hook(cvs->window.win, 2, 1UL << 0, &input_key, args);
	mlx_hook(cvs->window.win, CLOSE_WINDOW_BUTTON_EVENT, 0, &exit_program, args);
	mlx_mouse_hook(cvs->window.win, &input_mouse, args);
	mlx_loop(cvs->window.mlx);
}

// t_ray	ray_for_pixel(const t_camera *c, const int i, const int j)
// {
// 	double	world_x;
// 	double	world_y;
// 	t_tuple	pixel;
// 	t_tuple	origin;

// 	// xoffset = (i + 0.5) * c.pixel_size;
// 	// yoffset = (j + 0.5) * c.pixel_size;
// 	world_x = c->half_width - ((i + 0.5) * c->pixel_size);
// 	world_y = c->half_height - ((j + 0.5) * c->pixel_size);
// 	matrix_print(matrix_invert(c->transform, 4), "c->transform^-1: ");
// 	pixel = matrix_vect(matrix_invert(c->transform, 4), point(world_x, world_y, -1));
// 	origin = matrix_vect(matrix_invert(c->transform, 4), point(0, 0, 0));
// 	return ray(origin, tuple_normalize(tuple_sub(pixel, origin)));
// }

void	render(const t_canvas *cvs, const t_camera *c, const t_world *w)
{
	t_ray	r;
	int		i;
	int		j;

	j = -1;
	while (++j < c->height)
	{
		i = -1;
		while (++i < c->width)
		{
			r = ray_for_pixel(c, i, j);
			put_pixel((t_image *)&cvs->image, i, j, color_at(w, &r));
			if (r.itr_back)
				free(r.itr_back);
			if (r.itr_front)
				free(r.itr_front);
		}
	}
}