/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 12:47:27 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

// This function does not entirely depends on MATRIX_DIM
void	matrix_print_row_padding(t_matrix m, int n, int padding)
{
	if (n < 0 || n > 3)
		return ;
	if (n != 0)
		printf("%*s", padding + 11, "");
	printf("[" TUPLE_FORMAT " " TUPLE_FORMAT
		" " TUPLE_FORMAT " " TUPLE_FORMAT_SINGLE "]\n",
		(m.m)[n][0], (m.m)[n][1], (m.m)[n][2], (m.m)[n][3]);
}

// This function does not entirely depends on MATRIX_DIM
void	matrix_print_padding(t_matrix m, char *name, int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%smatrix:%*s", padding, "", name, 4, "");
	matrix_print_row_padding(m, 0, padding + len);
	matrix_print_row_padding(m, 1, padding + len);
	matrix_print_row_padding(m, 2, padding + len);
	matrix_print_row_padding(m, 3, padding + len);
	printf("\n");
}

void	matrix_print(t_matrix m, char *name)
{
	matrix_print_padding(m, name, 0);
}
