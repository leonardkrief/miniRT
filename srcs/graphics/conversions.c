/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:13:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 13:38:25 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_tuple	pixel_to_point(const t_image *img, const int i, const int j)
{
	return (point(img->origin.x
			+ ((double)i / (double)WINDOW_WIDTH - 0.5) * img->extension.x,
			img->origin.y
			- ((double)j / (double)WINDOW_HEIGHT - 0.5) * img->extension.y,
			img->origin.z));
}

t_tuple	point_to_pixel(const t_image *img, const double x, const double y)
{
	double	tmp;

	tmp = ((x - img->origin.x) / img->extension.x + 0.5) * WINDOW_WIDTH;
	(void)tmp;
	return (point(
			round((0.5 + (x - img->origin.x)
					/ (2 * img->extension.x)) * WINDOW_WIDTH),
			round((0.5 - (y - img->origin.y)
					/ (2 * img->extension.y)) * WINDOW_HEIGHT),
			0));
}
