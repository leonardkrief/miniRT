/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:50:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 23:19:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define B_PATTERN "%c%c%c%c%c%c%c%c"
#define B_PIXEL(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

void	print_pixel(t_pixel p, char *name)
{
	printf("%s: pixel:", name);
	printf("\t---------------------------------------------\n");
	printf("\t\t|    R     |    G     |    B     |    A     |\n");
	printf("\t\t---------------------------------------------\n");
	printf("\t\t|    %03u   |    %03u   |    %03u   |    %03u   |\n",
		get_r(p), get_g(p), get_b(p), get_a(p));
	printf("\t\t---------------------------------------------\n");
	printf("\t\t| " B_PATTERN " | " B_PATTERN " | " B_PATTERN " | " B_PATTERN
		" |\n", B_PIXEL(get_r(p)), B_PIXEL(get_g(p)), B_PIXEL(get_b(p)), B_PIXEL(get_a(p)));
	printf("\t\t---------------------------------------------\n");
}
