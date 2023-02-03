/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:07 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 06:45:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define MAX_PRINT_LEN "8"
#define PRECISION "3"
#define TUPLE_F "%+-"MAX_PRINT_LEN"."PRECISION"lf"

void	print_row(t_matrix m, int n)
{
	if (n != 0)
		printf("\t\t");
	printf("[" TUPLE_F ", " TUPLE_F ", " TUPLE_F
		", " TUPLE_F "]\n", (m.m)[n][0], (m.m)[n][1], (m.m)[n][2], (m.m)[n][3]);
}

void	print_matrix(t_matrix m, char *name)
{
	printf("%s: matrix:\t", name);
	print_row(m, 0);
	print_row(m, 1);
	print_row(m, 2);
	print_row(m, 3);
	printf("\n");
}

#undef MAX_PRINT_LEN
#undef PRECISION
#undef TUPLE_F