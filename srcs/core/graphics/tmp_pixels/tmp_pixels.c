/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:09:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_tmp_pixel	tmp_pixel(const float r, const float g, const float b,
				const float a)
{
	t_tmp_pixel	u;

	u.r = r;
	u.g = g;
	u.b = b;
	u.a = a;
	return (u);
}

t_pixel	tmp_pixel_to_pixel(const t_tmp_pixel p)
{
	return (pixel((t_pixel_color) fmax(fmin(p.r * 255, 255), 0),
			(t_pixel_color) fmax(fmin(p.g * 255, 255), 0),
			(t_pixel_color) fmax(fmin(p.b * 255, 255), 0),
			(t_pixel_color) fmax(fmin(p.a * 255, 255), 0)));
}

t_tmp_pixel	pixel_to_tmp_pixel(const t_pixel p)
{
	return (tmp_pixel((float) fmax(fmin(((double)pixel_get_r(p)) / 255, 1), 0),
			(float) fmax(fmin(((double)pixel_get_g(p)) / 255, 1), 0),
			(float) fmax(fmin(((double)pixel_get_b(p)) / 255, 1), 0),
			(float) fmax(fmin(((double)pixel_get_a(p)) / 255, 1), 0)));
}
