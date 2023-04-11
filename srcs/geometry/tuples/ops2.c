/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:23:34 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/02 15:11:29 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple_reflect(const t_tuple ray, const t_tuple normal)
{
	return (tuple_sub(ray, tuple_mul(2 * tuple_dotprod(ray, normal), normal)));
}

int	tuple_eq(const t_tuple a, const t_tuple b)
{
	if (eq(a.x, b.x) && eq(a.y, b.y) && eq(a.z, b.z) && eq(a.w, b.w))
		return (1);
	return (0);
}

double	tuple_first_non_null(const t_tuple a)
{
	if (!eq(a.x, 0))
		return (a.x);
	if (!eq(a.y, 0))
		return (a.y);
	if (!eq(a.z, 0))
		return (a.z);
	return (0);
}

int	tuple_colinear(t_tuple a, t_tuple b)
{
	if (tuple_eq(tuple_crossprod(a, b), vector(0, 0, 0)))
		return (1);
	return (0);
}
