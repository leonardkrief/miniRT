/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:27:54 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/08 09:27:51 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrixes.h"

t_matrix	matrix_translation(const double x, const double y, const double z)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	a = tuple(1, 0, 0, 0);
	b = tuple(0, 1, 0, 0);
	c = tuple(0, 0, 1, 0);
	d = tuple(x, y, z, 1);
	return (matrix(a, b, c, d));
}

// reflection can be obtained by scaling by a negative value
// over the appropriate axis
// eg. reflection across the y axis: scaling(1, -1, 1)
t_matrix	matrix_scaling(const double x, const double y, const double z)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	a = tuple(x, 0, 0, 0);
	b = tuple(0, y, 0, 0);
	c = tuple(0, 0, z, 0);
	d = tuple(0, 0, 0, 1);
	return (matrix(a, b, c, d));
}

t_matrix	matrix_x_rotation(const double r)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	a = tuple(1, 0, 0, 0);
	b = tuple(0, cos(r), sin(r), 0);
	c = tuple(0, -sin(r), cos(r), 0);
	d = tuple(0, 0, 0, 1);
	return (matrix(a, b, c, d));
}

t_matrix	matrix_y_rotation(const double r)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	a = tuple(cos(r), 0, -sin(r), 0);
	b = tuple(0, 1, 0, 0);
	c = tuple(sin(r), 0, cos(r), 0);
	d = tuple(0, 0, 0, 1);
	return (matrix(a, b, c, d));
}

t_matrix	matrix_z_rotation(const double r)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	a = tuple(cos(r), -sin(r), 0, 0);
	b = tuple(sin(r), cos(r), 0, 0);
	c = tuple(0, 0, 1, 0);
	d = tuple(0, 0, 0, 1);
	return (matrix(a, b, c, d));
}
