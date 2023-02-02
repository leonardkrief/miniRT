/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:50:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 18:36:13 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define MAX_PRINT_LEN "8"
#define PRECISION "3"
#define TUPLE_F "%+-"MAX_PRINT_LEN"."PRECISION"lf"

void	print_tuple(t_tuple *a, char *name)
{
	if (a == NULL)
		printf("%s: tuple:\t(NULL)\n", name);
	if (eq(1, a->w))
	{
		printf("%s: point:\t", name);
		printf("[" TUPLE_F ", " TUPLE_F ", " TUPLE_F "]\n", a->x, a->y, a->z);
	}
	else if (eq(0, a->w))
	{
		printf("%s: vector:\t", name);
		printf("[" TUPLE_F ", " TUPLE_F ", " TUPLE_F "]\n", a->x, a->y, a->z);
	}
	else
		printf("Error print: %s: invalid tuple\n", name);
}
