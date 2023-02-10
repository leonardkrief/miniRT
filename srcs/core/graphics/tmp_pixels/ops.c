/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:07:15 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:37:38 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_tmp_pixel	tmp_pixel_add(const t_tmp_pixel p, const t_tmp_pixel q)
{
	t_tmp_pixel	u;

	u.r = p.r + q.r;
	u.g = p.g + q.g;
	u.b = p.b + q.b;
	u.a = p.a + q.a;
	return (u);
}

t_tmp_pixel	tmp_pixel_sub(const t_tmp_pixel p, const t_tmp_pixel q)
{
	t_tmp_pixel	u;

	u.r = p.r - q.r;
	u.g = p.g - q.g;
	u.b = p.b - q.b;
	u.a = p.a - q.a;
	return (u);
}

t_tmp_pixel	tmp_pixel_scal(const double q, const t_tmp_pixel p)
{
	t_tmp_pixel	u;

	u.r = q * p.r;
	u.g = q * p.g;
	u.b = q * p.b;
	u.a = q * p.a;
	return (u);
}

t_tmp_pixel	tmp_pixel_mul(const t_tmp_pixel p, const t_tmp_pixel q)
{
	t_tmp_pixel	u;

	u.r = p.r * q.r;
	u.g = p.g * q.g;
	u.b = p.b * q.b;
	u.a = p.a * q.a;
	return (u);
}
