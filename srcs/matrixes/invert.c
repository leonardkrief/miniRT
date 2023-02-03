/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 07:03:41 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 17:20:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	submatrix(t_matrix a, int row, int col)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col)
	{
		i = row - 1;
		while (++i < MATRIX_DIM - 1)
			a.m[i][j] = a.m[i + 1][j];
	}
	j--;
	while (++j < MATRIX_DIM - 1)
	{
		i = -1;
		while (++i < row)
			a.m[i][j] = a.m[i][j + 1];
		i--;
		while (++i < MATRIX_DIM - 1)
			a.m[i][j] = a.m[i + 1][j + 1];
	}
	i = -1;
	while (++i < MATRIX_DIM)
	{
		a.m[i][MATRIX_DIM - 1] = 0;
		a.m[MATRIX_DIM - 1][i] = 0;
	}
	return (a);
}

t_matrix	pivot(t_matrix m, int col, int *row_is_null)
{
	int		row;
	int		non_null_col;
	double	pivot;

	non_null_col = null_row_forward(m, col);
	if (non_null_col >= MATRIX_DIM)
	{
		*row_is_null = 1;
		return (m);
	}
	m = swap_cols(m, col, non_null_col);
	pivot = m.m[col][col];
	row = col;
	while (++row < MATRIX_DIM)
		m = row_transmutation(m, row, -m.m[row][col] / pivot, col);
	return (m);
}

double	det(t_matrix m, int dim)
{
	int	row;
	int	row_is_null;
	float	det;

	row_is_null = 0;
	row = -1;
	while (++row < dim)
	{
		m = pivot(m, row, &row_is_null);
		if (row_is_null == 1)
			return (0);
	}
	det = m.m[0][0];
	row = 0;
	while (++row < dim)
		det *= m.m[row][row];
	return (det);
}

double	cofactor(t_matrix m, int row, int col, int dim)
{
	double	res;

	res = det(submatrix(m, row, col), dim - 1);
	if ((row + col) % 2)
		return (-res);
	return (res);
}

t_matrix	invert(t_matrix m, int dim)
{
	int			row;
	int			col;
	int			d;
	t_matrix	inv;

	memset(&inv, 0, sizeof (inv));
	d = det(m, dim);
	if (eq(d, 0))
	{
		ft_puterror(ERROR_INVERT_MATRIX, (char *)__func__);
		return (inv);
	}
	row = -1;
	while (++row < dim)
	{
		col = -1;
		while (++col < dim)
			inv.m[row][col] = cofactor(m, col, row, dim) / d;
	}
	return (inv);
}