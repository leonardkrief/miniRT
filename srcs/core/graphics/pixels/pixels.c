/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/09 06:28:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_pixel	pixel(const t_pixel_color r, const t_pixel_color g,
		const t_pixel_color b, const t_pixel_color a)
{
	return ((int)a << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

t_pixel_color	pixel_get_a(const t_pixel pixel)
{
	return ((t_pixel_color)((pixel >> 24) & 0xFF));
}

t_pixel_color	pixel_get_r(const t_pixel pixel)
{
	return ((t_pixel_color)((pixel >> 16) & 0xFF));
}

t_pixel_color	pixel_get_g(const t_pixel pixel)
{
	return ((t_pixel_color)((pixel >> 8) & 0xFF));
}

t_pixel_color	pixel_get_b(const t_pixel pixel)
{
	return ((t_pixel_color)(pixel & 0xFF));
}
