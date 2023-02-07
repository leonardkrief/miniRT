/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparing_functions_performance.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:36:04 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 02:56:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// (1)
t_tuple	tuple1(t_tuple a)
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

// (2)
t_tuple	tuple2(const t_tuple a)
{
	double	m;
	t_tuple	b;

	if (!eq(0, a.w))
	{
		ft_puterror(ERROR_NORMALIZE, (char *)__func__);
		ft_memset((void *)&a, 0, sizeof (a));
		return (a);
	}
	m = tuple_modulus(a);
	if (eq(m, 0))
		b = tuple(0, 0, 0, a.w);
	else
		b = tuple((double)a.x / (double)m, (double)a.y / (double)m,
			(double)a.z / (double)m, a.w);
	return (b);
}

#define ITERS 200000000

int main(int ac, char **av)
{
	int			i;
	long int	n;
	t_tuple		a;
	clock_t		start, end;
	double		execution_time_1, execution_time_2;

	a.x = 1.5;
	a.y = 2;
	a.z = 35897.78;
	a.w = 4.6698;
	if (ac > 1)
		n = atol(av[1]);
	else
		n = ITERS;
	start = clock();
	for (i = 0; i < n; i++)
		tuple1(a);
	end = clock();
	execution_time_1 = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("(1) exec_time = %.3f\n    n = %.f * 1e6\n", execution_time_1, n / 1e6);
	start = clock();
	for (i = 0; i < n; i++)
		tuple2(a);
	end = clock();
	execution_time_2 = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("(2) exec_time = %.3f\n    n = %.f * 1e6\n", execution_time_1, n / 1e6);
	if (execution_time_1 < execution_time_2)
		printf("(1) is better than (2): -%.3fs optimization", execution_time_2 - execution_time_1);
	else
		printf("(2) is better than (1): -%.3fs optimization", execution_time_2 - execution_time_1);
}