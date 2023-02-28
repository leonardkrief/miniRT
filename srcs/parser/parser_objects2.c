/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 16:30:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_matrix	plane_matrix(t_tuple origin, t_tuple ortn)
{
	t_matrix	r;
	t_matrix	b;
	t_tuple		a;
	t_tuple		q;
	double		t;

	a = tuple_normalize(tuple_crossprod(vector(0, 1, 0), ortn));
	t = acos(tuple_dotprod(vector(0, 1, 0), ortn));
	q.x = cos(t);
	q.y = sin(t);
	q.z = 1 - q.x;
	r = matrix_transpose(matrix(
				tuple(q.z * a.x * a.x + q.x, q.z * a.x * a.y - q.y * a.z,
					q.z * a.x * a.z + q.y * a.y, 0),
				tuple(q.z * a.x * a.y + q.y * a.z, q.z * a.y * a.y + q.x,
					q.z * a.y * a.z - q.y * a.x, 0),
				tuple(q.z * a.x * a.z - q.y * a.y, q.z * a.y * a.z + q.y * a.x,
					q.z * a.z * a.z + q.x, 0),
				tuple(0, 0, 0, 1)));
	b = matrix_translation(origin.x, origin.y, origin.z);
	r = matrix_matrix(b, r, 4);
	a = matrix_vect(r, vector(0, 1, 0));
	return (r);
}

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
// because of disgusting 25 lines rule + no init inside ifs, I initiate
// my plane after initing origin to be able to test both at the same time
// DISGUSTING
char	*parser_plane(char *str, t_world *w)
{
	t_tuple	origin;
	t_tuple	ortn;
	t_tuple	clr;
	t_plane	*pl;

	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	pl = plane();
	if (pl == NULL || parser_valid_tuple(origin, FLAG_DEFAULT))
		return (NULL);
	ortn = vector(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(ortn, FLAG_ABS_UNIT))
		return (NULL);
	clr = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_PIXEL))
		return (NULL);
	pl->mat.color = tmp_pixel(clr.x, clr.y, clr.z, 0);
	transform_pl(pl, plane_matrix(origin, tuple_normalize(ortn)));
	return (world_add_plane(w, pl), str);
}
