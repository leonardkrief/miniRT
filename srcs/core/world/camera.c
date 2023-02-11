/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:33:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 17:33:09 by lkrief           ###   ########.fr       */
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
	c.transform.m[0][0] = 1;
	c.transform.m[1][1] = 1;
	c.transform.m[2][2] = 1;
	c.transform.m[3][3] = 1;
	c.inv_transform = c.transform;
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

void	view_transform(t_camera *c, t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	upn;
	t_tuple	left;
	t_tuple	true_up;
	t_matrix orientation;

	forward = tuple_normalize(tuple_sub(to, from));
	upn = tuple_normalize(up);
	left = tuple_crossprod(forward, upn);
	true_up = tuple_crossprod(left, forward);
	orientation = matrix_transpose(
		matrix(left, true_up, tuple_neg(forward), point(0, 0, 0)));
	c->transform = matrix_matrix(orientation, matrix_translation(
				-from.x, -from.y, -from.z), 4);
	c->inv_transform = matrix_invert(c->transform, 4);
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
	pixel = matrix_vect(c->inv_transform, point(world_x, world_y, -1));
	origin = matrix_vect(c->inv_transform, point(0, 0, 0));
	return ray(origin, tuple_normalize(tuple_sub(pixel, origin)));
}

void	camera_transform(t_camera *c, const t_matrix transform)
{
	c->transform = matrix_matrix(transform, c->transform, 4);
	c->inv_transform = matrix_invert(c->transform, 4);
}
