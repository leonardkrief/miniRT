/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:50:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/05 20:34:30 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

void	tuple_raw_print(t_tuple a)
{
	if (!(eq(1, a.w) || eq(0, a.w)))
		printf("[" TUPLE_FORMAT ", " TUPLE_FORMAT ", "
			TUPLE_FORMAT ", " TUPLE_FORMAT_SINGLE , a.x, a.y, a.z, a.w);
	else
		printf("[" TUPLE_FORMAT ", " TUPLE_FORMAT
			", " TUPLE_FORMAT_SINGLE , a.x, a.y, a.z);
	printf("]");
}

void	tuple_print(t_tuple a, char *name)
{
	if (eq(1, a.w))
		printf("%spoint:\t", name);
	else if (eq(0, a.w))
		printf("%svector:\t", name);
	else
		printf("%stuple:\t", name);
	tuple_raw_print(a);
	printf("\n");
}
