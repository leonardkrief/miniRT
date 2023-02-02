/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:40:00 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 14:11:10 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	eq(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return 1;
	return 0;
}

double	modulus(t_tuple *a)
{
	if (eq(0, a->w))
		return sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	printf("Error modulus: non-vector object detected\n");
	return INT_MIN;
}

void	normalize(t_tuple *a)
{
	int	m;

	if (!eq(0, a->w))
	{
		printf("Error normalize: non-vector object detected\n");
		return ;
	}
	m = modulus(a);
	if (eq(m, 0))
	{
		a->x = 0;
		a->y = 0;
		a->z = 0;
	}
	else
	{
		a->x /= m;
		a->y /= m;
		a->z /= m;
	}
}

double	dotprod(t_tuple *a, t_tuple *b)
{
	if (eq(0, a->w) && eq(0, b->w))
		return a->x * b->x + a->y * b->y + a->z * b->z;
	printf("Error dotprod: non-vector objects detected\n");
	return INT_MIN;
}
