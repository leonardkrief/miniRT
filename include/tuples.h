/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 07:33:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include "miniRT.h"

typedef struct s_tuple{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

// tuples/print.c
void	print_tuple(t_tuple a, char *name);

// tuples/init.c
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
t_tuple	tuple(float x, float y, float z, float w);

// tuples/ops.c
t_tuple	add(t_tuple a, t_tuple b);
t_tuple	sub(t_tuple a, t_tuple b);
t_tuple	neg(t_tuple a);
t_tuple	mul(double q, t_tuple a);
t_tuple	crossprod(t_tuple a, t_tuple b);

// tuples/scalar_ops.c
int	eq(double a, double b);
double	modulus(t_tuple a);
t_tuple	normalize(t_tuple a);
double	dotprod(t_tuple a, t_tuple b);

#endif
