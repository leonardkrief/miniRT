/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/01 15:14:59 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	*matrix_vect(t_matrix *q, t_tuple *r)
{
	t_tuple	*result;

	result  = ft_calloc(1, sizeof(*result));
	if (result == NULL)
		return NULL;
	result->x = q[0][0] * r->x + q[0][1] * r->y + q[0][2] * r->z + q[0][3] * r->w;
	result->y = q[1][0] * r->x + q[1][1] * r->y + q[1][2] * r->z + q[1][3] * r->w;
	result->z = q[2][0] * r->x + q[2][1] * r->y + q[2][2] * r->z + q[2][3] * r->w;
	result->w = q[3][0] * r->x + q[3][1] * r->y + q[3][2] * r->z + q[3][3] * r->w;
	return (result);
}
