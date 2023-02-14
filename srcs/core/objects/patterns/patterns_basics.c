/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:47 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 03:02:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

// Multiply p by obj->m               matrix_vect(obj->m, p);
// Multiply the result by pat->m
//                      matrix_vect(pat->m, matrix_vect(obj->m, p));
// pat->m is the inverse of the 
// transformation matrix of pattern
// pass this point to original pattern_at and result the result
// All of this is done in a single line in lighting function (world/hits.c)
// because of stupid 42 limiting variables rule

t_pattern	pattern(const t_tmp_pixel a, const t_tmp_pixel b,
		const t_pattern_id id)
{
	t_pattern	pat;

	pat.color1 = a;
	pat.color2 = b;
	pat.m = matrix_identity();
	if (id == STRIPED_PATTERN)
		pat.f = stripe_at;
	else if (id == GRADIENT_PATTERN)
		pat.f = gradient_at;
	else if (id == RING_PATTERN)
		pat.f = ring_at;
	else if (id == THREED_CHECKER_PATTERN)
		pat.f = threed_checker_at;
	else if (id == PLATINIUM_STRIPED_PATTERN)
		pat.f = platinium_striped_at;
	else if (id == MASTER_PATTERN)
		pat.f = master_at;
	else if (id == TEST_PATTERN)
		pat.f = test_at;
	return (pat);
}

// transform point from world space to object space
// to pattern space then returns its color through pattern function

t_tmp_pixel	pattern_at(const t_object *obj, const t_object_id id,
					const t_material *mat, const t_computations *c)
{
	t_tuple		point;
	t_matrix	m;

	point = c->over_point;
	if (id == SPHERE_ID)
		m = ((t_sphere *)obj)->m;
	else if (id == PLANE_ID)
		m = ((t_plane *)obj)->m;
	// to be continued...
	else
	{
		ft_puterror(UNKNOWN_OBJECT, (char *)__func__);
		m = matrix(NULL_MATRIX);
	}
	point = matrix_vect(m, point);
	point = matrix_vect(mat->pattern.m, point);
	return (mat->pattern.f(point, &mat->pattern));
}

void	transform_pattern(t_pattern *pat, const t_matrix m)
{
	pat->m = matrix_invert(m, 4);
}
