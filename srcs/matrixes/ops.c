/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:08:09 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 06:54:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	matrix_vect(t_matrix m, t_tuple t)
{
	t_tuple	result;

	result.x = m.m[0][0] * t.x + m.m[0][1] * t.y + m.m[0][2] * t.z + m.m[0][3] * t.w;
	result.y = m.m[1][0] * t.x + m.m[1][1] * t.y + m.m[1][2] * t.z + m.m[1][3] * t.w;
	result.z = m.m[2][0] * t.x + m.m[2][1] * t.y + m.m[2][2] * t.z + m.m[2][3] * t.w;
	result.w = m.m[3][0] * t.x + m.m[3][1] * t.y + m.m[3][2] * t.z + m.m[3][3] * t.w;
	return (result);
}

t_matrix	matrix_matrix(t_matrix m, t_matrix n)
{
	int			i;
	int			j;
	t_matrix	result;

	i = -1;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= 3)
			result.m[i][j] = m.m[i][0] * n.m[0][j] + m.m[i][1] * n.m[1][j]
				+ m.m[i][2] * n.m[2][j] + m.m[i][3] * n.m[3][j];
	}
	return (result);
}

t_matrix	transpose(t_matrix m)
{
	int			i;
	int			j;
	double		tmp;

	i = 0;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= i)
		{
			tmp = m.m[i][j];
			m.m[i][j] = m.m[j][i];
			m.m[j][i] = tmp;
		}
	}
	return (m);
}
