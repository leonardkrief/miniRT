/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/05 20:04:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_pixel	pixel_add(t_pixel p, t_pixel q)
{
	t_pixel	u;

	u = 0;
	u |= (int)(pixel_get_r(p) + pixel_get_r(q)) << 16;
	u |= (int)(pixel_get_g(p) + pixel_get_g(q)) << 8;
	u |= (int)(pixel_get_b(p) + pixel_get_b(q));
	return (u);
}

t_pixel	pixel_sub(t_pixel p, t_pixel q)
{
	t_pixel	u;

	u = 0;
	u |= (int)(pixel_get_r(p) - pixel_get_r(q)) << 16;
	u |= (int)(pixel_get_g(p) - pixel_get_g(q)) << 8;
	u |= (int)(pixel_get_b(p) - pixel_get_b(q));
	return (u);
}

t_pixel	pixel_scal(float q, t_pixel p)
{
	t_pixel	u;

	u = 0;
	u |= (int)(q * (float)pixel_get_r(p)) << 16;
	u |= (int)(q * (float)pixel_get_g(p)) << 8;
	u |= (int)(q * (float)pixel_get_b(p));
	return (u);
}

t_pixel	pixel_mul(t_pixel p, t_pixel q)
{
	t_pixel	u;

	u = 0;
	u |= (int)((float)pixel_get_r(p) * (float)pixel_get_r(q) / 255) << 16;
	u |= (int)((float)pixel_get_g(p) * (float)pixel_get_g(q) / 255) << 8;
	u |= (int)((float)pixel_get_b(p) * (float)pixel_get_b(q) / 255);
	return (u);
}
