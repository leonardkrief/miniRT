/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:47 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 22:51:32 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

t_tmp_pixel	master_at(const t_tuple p, const t_pattern *pat)
{
	t_pattern	tmp;

	tmp = pattern(stripe_at(p, pat), gradient_at(p, pat), STRIPED_PATTERN);
	transform_pattern(&tmp, matrix_rotation_z(M_PI / 6));
	return (ring_at(p, &tmp));
}

t_tmp_pixel	test_at(const t_tuple p, const t_pattern *pat)
{
	t_pattern	tmp;

	tmp = pattern(ring_at(p, pat), platinium_striped_at(p, pat),
			STRIPED_PATTERN);
	transform_pattern(&tmp, matrix_rotation_z(M_PI / 5));
	return (stripe_at(p, &tmp));
}
