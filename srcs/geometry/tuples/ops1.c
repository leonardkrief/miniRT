/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:23:34 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 16:06:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple_add(const t_tuple a, const t_tuple b)
{
	t_tuple	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return (c);
}

t_tuple	tuple_sub(const t_tuple a, const t_tuple b)
{
	t_tuple	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return (c);
}

t_tuple	tuple_neg(const t_tuple a)
{
	t_tuple	b;

	b.x = -a.x;
	b.y = -a.y;
	b.z = -a.z;
	b.w = -a.w;
	return (b);
}

t_tuple	tuple_mul(const double q, const t_tuple a)
{
	t_tuple	b;

	b.x = a.x * q;
	b.y = a.y * q;
	b.z = a.z * q;
	b.w = a.w * q;
	return (b);
}

t_tuple	tuple_crossprod(const t_tuple a, const t_tuple b)
{
	t_tuple	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}
