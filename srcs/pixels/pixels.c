/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 23:16:39 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pixel	pixel(t_color r, t_color g, t_color b, t_color a)
{
	return ((int)a << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

t_color	get_a(t_pixel pixel)
{
	return ((t_color)((pixel >> 24) & 0xFF));
}

t_color	get_r(t_pixel pixel)
{
	return ((t_color)((pixel >> 16) & 0xFF));
}

t_color	get_g(t_pixel pixel)
{
	return ((t_color)((pixel >> 8) & 0xFF));
}

t_color	get_b(t_pixel pixel)
{
	return ((t_color)(pixel & 0xFF));
}
