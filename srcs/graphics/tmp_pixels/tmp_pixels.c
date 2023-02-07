/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:17:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_tmp_pixel	tmp_pixel(const float r, const float g, const float b, const float a)
{
	t_tmp_pixel	u;

	u.r = r;
	u.g = g;
	u.b = b;
	u.a = a;
	return (u);
}
