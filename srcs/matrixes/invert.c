/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 07:03:41 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 08:23:23 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	submatrix(t_matrix a, int n, int m)
{
	int	i;
	int	j;

	j = -1;
	while (++j < m)
	{
		i = n - 1;
		while (++i < 3)
			a.m[i][j] = a.m[i + 1][j];
	}
	j--;
	while (++j < 3)
	{
		i = -1;
		while (++i < n)
			a.m[i][j] = a.m[i][j + 1];
		i--;
		while (++i < 3)
			a.m[i][j] = a.m[i + 1][j + 1];
	}
	i = -1;
	while (++i < 4)
	{
		a.m[i][3] = 0;
		a.m[3][i] = 0;
	}
	return (a);
}

int	nullify_col(t_matrix *m, int col)
{
	int		i;
	double	pivot;
	double	nulling;

	pivot = (*m).m[col][col];
	if (eq(pivot, 0) && switch_cols_nullify(m) == 0)
		
	i = col;
	while (++i < 4)
	{
		nulling = 
	}
}

double	det(t_matrix m, int dim)
{
	if (dim == 2)
		return (m.m[0][0] * m.m[1][1] - m.m[1][0] * m.m[0][1]);
	else if (dim == 3)
		return (m.m[0][0] * det(submatrix(m, 0, 0), 2)
			- m.m[0][1] * det(submatrix(m, 0, 1), 2)
			+ m.m[0][2] * det(submatrix(m, 0, 2), 2));
	else if (dim == 4)
		return (m.m[0][0] * det(submatrix(m, 0, 0), 3)
			- m.m[0][1] * det(submatrix(m, 0, 1), 3)
			+ m.m[0][2] * det(submatrix(m, 0, 2), 3))
			- m.m[0][3] * det(submatrix(m, 0, 3), 3);
	else
		ft_puterror(ERROR_DETERMINANT, (char *)__func__);
	return (INT_MIN);
}