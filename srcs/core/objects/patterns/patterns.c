/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:47 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/13 22:55:55 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "objects.h"
# include <math.h>

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

t_tmp_pixel	striped_gradient_at(const t_tuple p, const t_pattern *pat)
{
	t_tmp_pixel	distance;
	double		fraction;
	
	
	distance = tmp_pixel_sub(pat->color2, pat->color1);
	fraction = cos((p.x / 2 + 0.5) * 100 * M_PI);
	// fraction += (p.y / 2 + 0.5) - floor((p.y / 2 + 0.5)) / 3;
	// fraction += (p.z / 2 + 0.5) - floor((p.z / 2 + 0.5)) / 3;
	return (tmp_pixel_add(pat->color1, tmp_pixel_scal(fraction, distance)));
}