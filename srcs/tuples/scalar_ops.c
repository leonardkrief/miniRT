/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:40:00 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 01:32:07 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

int	eq(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

double	tuple_modulus(t_tuple a)
{
	if (eq(0, a.w))
		return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
	ft_puterror(ERROR_MODULUS, (char *)__func__);
	return (INT_MIN);
}

t_tuple	tuple_normalize(t_tuple a)
{
	double	m;

	if (!eq(0, a.w))
	{
		ft_puterror(ERROR_NORMALIZE, (char *)__func__);
		ft_memset(&a, 0, sizeof (a));
		return (a);
	}
	m = tuple_modulus(a);
	if (eq(m, 0))
	{
		a.x = 0;
		a.y = 0;
		a.z = 0;
	}
	else
	{
		a.x = (double)a.x / (double)m;
		a.y = (double)a.y / (double)m;
		a.z = (double)a.z / (double)m;
	}
	return (a);
}

double	tuple_dotprod(const t_tuple a, const t_tuple b)
{
	if (eq(0, a.w) && eq(0, b.w))
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	ft_puterror(ERROR_DOTPROD, (char *)__func__);
	return (INT_MIN);
}
