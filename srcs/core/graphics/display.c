/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:38:29 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 00:38:42 by lkrief           ###   ########.fr       */
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
	mlx_put_image_to_window(cvs->window.mlx, cvs->window.win,
		cvs->image.img, 0, 0);
	mlx_hook(cvs->window.win, 2, 1UL << 0, &input_key, args);
	mlx_hook(cvs->window.win, CLOSE_WINDOW_BUTTON_EVENT, 0,
		&exit_program, args);
	mlx_mouse_hook(cvs->window.win, &input_mouse, args);
	mlx_loop(cvs->window.mlx);
}

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
