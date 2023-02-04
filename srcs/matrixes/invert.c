/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 07:03:41 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:26:56 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

t_matrix	matrix_submatrix(t_matrix a, int row, int col)
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

t_matrix	matrix_pivot(t_matrix m, int col, int dim, int *row_is_null)
{
	int		row;
	int		non_null_col;
	double	pivot;

	non_null_col = matrix_null_row_forward(m, col, dim);
	if (non_null_col >= dim)
	{
		*row_is_null = 1;
		return (m);
	}
	m = matrix_swap_cols(m, col, non_null_col);
	pivot = m.m[col][col];
	row = col;
	while (++row < dim)
		m = matrix_row_transmutation(m, row, -m.m[row][col] / pivot, col);
	return (m);
}

double	det(t_matrix m, int dim)
{
	int	row;
	int	row_is_null;
	float	det;

	row_is_null = 0;
	det = 1;
	row = -1;
	while (++row < dim)
	{
		if (eq(m.m[row][row], 0))
			det *= -1;
		m = matrix_pivot(m, row, dim, &row_is_null);
		if (row_is_null == 1)
			return (0);
	}
	row = -1;
	while (++row < dim)
		det *= m.m[row][row];
	return (det);
}

double	matrix_cofactor(t_matrix m, int row, int col, int dim)
{
	double	res;

	if (row == 3 && col == 1)
	{
		res = 0;
	}
	res = det(matrix_submatrix(m, row, col), dim - 1);
	if ((row + col) % 2)
		return (-res);
	return (res);
}

t_matrix	matrix_invert(t_matrix m, int dim)
{
	int			row;
	int			col;
	int			d;
	t_matrix	inv;

	ft_memset(&inv, 0, sizeof (inv));
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
			inv.m[row][col] = matrix_cofactor(m, col, row, dim) / d;
	}
	return (inv);
}
