/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:33:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 20:31:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_camera	camera(double camera_width, double camera_height, double fov)
{
	t_camera	c;

	ft_memset(&c, 0, sizeof(c));
	c.width = camera_width;
	c.height = camera_height;
	c.fov = fov;
	c.transform = view_transform(DEFAULT_CAMERA_FROM, DEFAULT_CAMERA_TO, DEFAULT_CAMERA_UP);
	pixel_size(&c);
	return (c);
}

void	pixel_size(t_camera *c)
{
	double	half_view;
	double	aspect;

	half_view = tan(c->fov / 2);
	aspect = (double)c->width / (double)c->height;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / c->width;
}

t_ray	ray_for_pixel(const t_camera *c, const int i, const int j)
{
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;

	// xoffset = (i + 0.5) * c.pixel_size;
	// yoffset = (j + 0.5) * c.pixel_size;
	world_x = c->half_width - ((i + 0.5) * c->pixel_size);
	world_y = c->half_height - ((j + 0.5) * c->pixel_size);
	pixel = matrix_vect(c->transform, point(world_x, world_y, -1));
	origin = matrix_vect(c->transform, point(0, 0, 0));
	return ray(origin, tuple_normalize(tuple_sub(pixel, origin)));
}

void	transform_camera(t_camera *c, const t_matrix transform)
{
	c->transform = matrix_matrix(c->transform, matrix_invert(transform, 4), 4);
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