/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/08 09:26:18 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

// This function does not entirely depends on MATRIX_DIM
void	matrix_print_row(t_matrix m, int n)
{
	if (n != 0)
		printf("\t\t");
	printf("[" TUPLE_FORMAT " " TUPLE_FORMAT
		" " TUPLE_FORMAT " " TUPLE_FORMAT_SINGLE "]\n",
		(m.m)[n][0], (m.m)[n][1], (m.m)[n][2], (m.m)[n][3]);
}

// This function does not entirely depends on MATRIX_DIM
void	matrix_print(t_matrix m, char *name)
{
	printf("%s: matrix:\t", name);
	matrix_print_row(m, 0);
	matrix_print_row(m, 1);
	matrix_print_row(m, 2);
	matrix_print_row(m, 3);
	printf("\n");
}
