/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:47 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 22:51:41 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

t_tmp_pixel	stripe_at(const t_tuple p, const t_pattern *pat)
{
	if ((int)floor(p.x) % 2 == 0)
		return (pat->color1);
	else
		return (pat->color2);
}

// line 32, modifiying this factor changes the width of the gradient stripes
t_tmp_pixel	gradient_at(const t_tuple p, const t_pattern *pat)
{
	t_tmp_pixel	distance;
	double		var;
	double		l;

	distance = tmp_pixel_sub(pat->color2, pat->color1);
	var = (p.x + 1) / 10;
	l = var - floor(var);
	if ((int)floor(var) % 2 == 0)
		return (tmp_pixel_add(pat->color1, tmp_pixel_scal(l, distance)));
	else
		return (tmp_pixel_add(pat->color1, tmp_pixel_scal(1 - l, distance)));
}

t_tmp_pixel	ring_at(const t_tuple p, const t_pattern *pat)
{
	if ((int)floor(sqrt(p.x * p.x + p.z * p.z)) % 2 == 0)
		return (pat->color1);
	else
		return (pat->color2);
}

t_tmp_pixel	threed_checker_at(const t_tuple p, const t_pattern *pat)
{
	if (((int)floor(p.x) + (int)floor(p.y) + (int)floor(p.z)) % 2 == 0)
		return (pat->color1);
	else
		return (pat->color2);
}

t_tmp_pixel	platinium_striped_at(const t_tuple p, const t_pattern *pat)
{
	t_pattern	tmp;

	tmp = pattern(gradient_at(p, pat), gradient_at(tuple_mul(1.5, p), pat),
			STRIPED_PATTERN);
	transform_pattern(&tmp, matrix_rotation_y(M_PI / 6));
	return (stripe_at(p, &tmp));
}
