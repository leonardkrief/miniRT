/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:38:29 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/14 19:29:25 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	all(t_all *args, t_canvas *cvs, t_camera *c, t_world *w)
{
	args->canvas = cvs;
	args->camera = c;
	args->world = w;
}

// mlx_mouse_hook(cvs->window.win, &input_mouse, args);
// jai enleve le mouse input car genere un leak de la mlx
// je le laisse en com car peut etre utile au debuggage
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
	mlx_loop(cvs->window.mlx);
}

void	render(const t_canvas *cvs, const t_camera *c, const t_world *w)
{
	t_ray			r;
	int				i;
	int				j;

	j = -1;
	while (++j < c->height)
	{
		i = -1;
		while (++i < c->width)
		{
			r = ray_for_pixel(c, i, j);
			put_pixel((t_image *)&cvs->image, i, j, color_at(w, &r));
			free_ray(r);
		}
	}
}
