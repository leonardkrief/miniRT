/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 15:58:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// This function does not entirely depends on MATRIX_DIM
void	insert_col_in_matrix(t_matrix *m, t_tuple a, int n)
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
	insert_col_in_matrix(&m, a, 0);
	insert_col_in_matrix(&m, b, 1);
	insert_col_in_matrix(&m, c, 2);
	insert_col_in_matrix(&m, d, 3);
	return (m);
}
