/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:40:00 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 12:04:06 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

int	eq(const double a, const double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

double	tuple_modulus(const t_tuple a)
{
	if (eq(0, a.w))
		return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
	ft_puterror(ERROR_MODULUS, (char *)__func__);
	return (INT_MIN);
}

t_tuple	tuple_normalize(const t_tuple a)
{
	double	m;
	t_tuple	n;

	ft_memset(&n, 0, sizeof (n));
	if (!eq(0, n.w))
	{
		ft_puterror(ERROR_NORMALIZE, (char *)__func__);
		return (n);
	}
	m = tuple_modulus(a);
	if (eq(m, 0))
		return (n);
	n.x = (double)a.x / (double)m;
	n.y = (double)a.y / (double)m;
	n.z = (double)a.z / (double)m;
	return (n);
}

double	tuple_dotprod(const t_tuple a, const t_tuple b)
{
	if (eq(0, a.w) && eq(0, b.w))
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	ft_puterror(ERROR_DOTPROD, (char *)__func__);
	return (INT_MIN);
}
