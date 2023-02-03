/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:08:09 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 18:01:53 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// This function does not entirely depends on MATRIX_DIM
t_tuple	matrix_vect(t_matrix m, t_tuple t)
{
	t_tuple	result;

	result.x = m.m[0][0] * t.x + m.m[0][1] * t.y + m.m[0][2] * t.z + m.m[0][3] * t.w;
	result.y = m.m[1][0] * t.x + m.m[1][1] * t.y + m.m[1][2] * t.z + m.m[1][3] * t.w;
	result.z = m.m[2][0] * t.x + m.m[2][1] * t.y + m.m[2][2] * t.z + m.m[2][3] * t.w;
	result.w = m.m[3][0] * t.x + m.m[3][1] * t.y + m.m[3][2] * t.z + m.m[3][3] * t.w;
	return (result);
}

t_matrix	matrix_matrix(t_matrix m, t_matrix n, int dim)
{
	int			i;
	int			j;
	int			k;
	t_matrix	result;

	i = -1;
	ft_memset(&result, 0, sizeof(result));
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			k = -1;
			while (++k < dim)
				result.m[i][j] += m.m[i][k] * n.m[k][j];
		}
	}
	return (result);
}

t_matrix	transpose(t_matrix m)
{
	int			i;
	int			j;
	double		tmp;

	i = 0;
	while (++i < MATRIX_DIM)
	{
		j = -1;
		while (++j < i)
		{
			tmp = m.m[i][j];
			m.m[i][j] = m.m[j][i];
			m.m[j][i] = tmp;
		}
	}
	return (m);
}
