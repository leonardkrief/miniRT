/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:55:54 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/13 14:25:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

int	matrix_null_row_forward(const t_matrix m, const int row, const int dim)
{
	int	i;

	i = row;
	while (i < dim && eq(m.m[row][i], 0))
		i++;
	return (i);
}

t_matrix	matrix_swap_cols(t_matrix m, const int col1, const int col2)
{
	int		i;
	double	tmp;

	if (col1 == col2)
		return (m);
	i = -1;
	while (++i < MATRIX_DIM)
	{
		tmp = m.m[i][col1];
		m.m[i][col1] = m.m[i][col2];
		m.m[i][col2] = tmp;
	}
	return (m);
}

t_matrix	matrix_row_transmutation(t_matrix m, const int row,
						const double q, const int to_add)
{
	int	i;

	i = -1;
	while (++i < MATRIX_DIM)
		m.m[row][i] += q * m.m[to_add][i];
	return (m);
}
