/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:27:54 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 18:35:06 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	shearing(double x[2], double y[2], double z[2])
{
	t_tuple a;
	t_tuple b;
	t_tuple c;
	t_tuple d;

	a = tuple(1, x[0], x[1], 0);
	b = tuple(y[0], 1, y[1], 0);
	c = tuple(z[0], z[1], 1, 0);
	d = tuple(0, 0, 0, 1);
	return (matrix(a, b, c, d));
}
