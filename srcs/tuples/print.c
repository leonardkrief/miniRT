/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:50:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 03:22:12 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define MAX_PRINT_LEN "8"
#define PRECISION "3"
#define TUPLE_F "%+-"MAX_PRINT_LEN"."PRECISION"lf"

void	print_tuple(t_tuple a, char *name)
{
	if (eq(1, a.w))
		printf("%s: point:\t", name);
	else if (eq(0, a.w))
		printf("%s: vector:\t", name);
	else
		printf("%s: tuple:\t", name);
	printf("[" TUPLE_F ", " TUPLE_F ", " TUPLE_F
		", " TUPLE_F "]\n", a.x, a.y, a.z, a.w);
}

#undef MAX_PRINT_LEN
#undef PRECISION
#undef TUPLE_F