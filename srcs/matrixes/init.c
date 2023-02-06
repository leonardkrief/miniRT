/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 05:54:01 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

// This function does not entirely depends on MATRIX_DIM
void	matrix_insert_col(t_matrix *m, t_tuple a, int n)
{
	if (!(n >= 0 && n <= MATRIX_DIM))
		return ;
	(m->m)[0][n] = a.x;
	(m->m)[1][n] = a.y;
	(m->m)[2][n] = a.z;
	(m->m)[3][n] = a.w;
}

// This function does not entirely depends on MATRIX_DIM
t_matrix	matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d)
{
	t_matrix	m;

	ft_memset(&m, 0, sizeof(m));
	matrix_insert_col(&m, a, 0);
	matrix_insert_col(&m, b, 1);
	matrix_insert_col(&m, c, 2);
	matrix_insert_col(&m, d, 3);
	return (m);
}

t_matrix	matrix_identity(void)
{
	t_matrix	m;

	ft_memset(&m, 0, sizeof(m));
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}