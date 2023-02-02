/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 23:46:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pixel	add_pixel(t_pixel p, t_pixel q)
{
	t_pixel	u;

	u = 0;
	u |= (int)(get_r(p) + get_r(q)) << 16;
	u |= (int)(get_g(p) + get_g(q)) << 8;
	u |= (int)(get_b(p) + get_b(q));
	return (u);
}

t_pixel	sub_pixel(t_pixel p, t_pixel q)
{
	t_pixel	u;

	u = 0;
	u |= (int)(get_r(p) - get_r(q)) << 16;
	u |= (int)(get_g(p) - get_g(q)) << 8;
	u |= (int)(get_b(p) - get_b(q));
	return (u);
}

t_pixel	scal_pixel(float q, t_pixel p)
{
	t_pixel	u;

	u = 0;
	u |= (int)(q * (float)get_r(p)) << 16;
	u |= (int)(q * (float)get_g(p)) << 8;
	u |= (int)(q * (float)get_b(p));
	return (u);
}

t_pixel	mul_pixel(t_pixel p, t_pixel q)
{
	t_pixel	u;

	u = 0;
	u |= (int)((float)get_r(p) * (float)get_r(q) / 255) << 16;
	u |= (int)((float)get_g(p) * (float)get_g(q) / 255) << 8;
	u |= (int)((float)get_b(p) * (float)get_b(q) / 255);
	return (u);
}
