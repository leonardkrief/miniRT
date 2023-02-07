/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:50:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:33:03 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	tmp_pixel_print(const t_tmp_pixel p, const char *name)
{
	printf("%s: pixel:", name);
	printf("\t-----------------------------\n");
	printf("\t\t|  R   |  G   |  B   |  A   |\n");
	printf("\t\t-----------------------------\n");
	printf("\t\t| %03.2f | %03.2f | %03.2f | %03.2f |\n", p.r, p.g, p.b, p.a);
	printf("\t\t-----------------------------\n");
}
