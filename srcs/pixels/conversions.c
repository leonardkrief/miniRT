/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:13:22 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:28:13 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixels.h"

t_tuple	pixel_to_point(t_image img, int i, int j)
{
	return (vector(
		img.origin.x + ((double)i / (double)WIDTH - 0.5) * img.extension.x, 
		img.origin.y - ((double)j / (double)HEIGHT - 0.5) * img.extension.y,
		0));
}

t_tuple	point_to_pixel(t_image img, double x, double y)
{
	double tmp;

	tmp = ((x - img.origin.x) / img.extension.x + 0.5) * WIDTH;
	(void)tmp;
	return (point(
		round((0.5 + (x - img.origin.x) / (2 * img.extension.x)) * WIDTH),
		round((0.5 + (img.origin.y - y) / (2 * img.extension.y)) * HEIGHT),
		0));
}
