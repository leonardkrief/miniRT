/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:33:52 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixels.h"

t_pixel	pixel(t_pixel_color r, t_pixel_color g, t_pixel_color b, t_pixel_color a)
{
	return ((int)a << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

t_pixel_color	pixel_get_a(t_pixel pixel)
{
	return ((t_pixel_color)((pixel >> 24) & 0xFF));
}

t_pixel_color	pixel_get_r(t_pixel pixel)
{
	return ((t_pixel_color)((pixel >> 16) & 0xFF));
}

t_pixel_color	pixel_get_g(t_pixel pixel)
{
	return ((t_pixel_color)((pixel >> 8) & 0xFF));
}

t_pixel_color	pixel_get_b(t_pixel pixel)
{
	return ((t_pixel_color)(pixel & 0xFF));
}
