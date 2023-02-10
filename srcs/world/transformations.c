/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:37:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 06:02:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	upn;
	t_tuple	left;
	t_tuple	true_up;
	t_matrix orientation;

	forward = tuple_normalize(tuple_sub(to, from));
	upn = tuple_normalize(up);
	left = tuple_crossprod(forward, upn);
	true_up = tuple_crossprod(left, forward);
	orientation = matrix_transpose(
		matrix(left, true_up, tuple_neg(forward), point(0, 0, 0)));
	return (matrix_matrix(orientation, matrix_translation(
				-from.x, -from.y, -from.z), 4));
}
