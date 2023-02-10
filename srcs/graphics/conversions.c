/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:13:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/08 09:21:30 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_tuple	pixel_to_point(const t_image *img, const int i, const int j)
{
	return (point(img->origin.x
			+ ((double)i / (double)WIDTH - 0.5) * img->extension.x,
			img->origin.y
			- ((double)j / (double)HEIGHT - 0.5) * img->extension.y,
			img->origin.z));
}

t_tuple	point_to_pixel(const t_image *img, const double x, const double y)
{
	double	tmp;

	tmp = ((x - img->origin.x) / img->extension.x + 0.5) * WIDTH;
	(void)tmp;
	return (point(
			round((0.5 + (x - img->origin.x)
					/ (2 * img->extension.x)) * WIDTH),
			round((0.5 - (y - img->origin.y)
					/ (2 * img->extension.y)) * HEIGHT),
			0));
}
