/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:23:34 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/05 23:27:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return (a);
}

t_tuple	tuple_neg(t_tuple a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	a.w = -a.w;
	return (a);
}

t_tuple	tuple_mul(double q, t_tuple a)
{
	a.x *= q;
	a.y *= q;
	a.z *= q;
	a.w *= q;
	return (a);
}

t_tuple	crossprod(t_tuple a, t_tuple b)
{
	double	x;
	double	y;
	double	z;

	x = a.x;
	y = a.y;
	z = a.z;
	a.x = y * b.z - z * b.y;
	a.y = z * b.x - x * b.z;
	a.z = x * b.y - y * b.x;
	return (a);
}
