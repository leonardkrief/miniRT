/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 06:39:10 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "error_handler.h"

# define EPSILON	__DBL_EPSILON__
#define MAX_PRINT_LEN "8"
#define PRECISION "3"
#define TUPLE_FORMAT "%+-"MAX_PRINT_LEN"."PRECISION"lf"
#define TUPLE_FORMAT_SINGLE "%+-1."PRECISION"lf"

typedef struct s_tuple{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

// tuples/print.c
void	tuple_raw_print(t_tuple a);
void	tuple_print(t_tuple a, char *name);

// tuples/init.c
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
t_tuple	tuple(float x, float y, float z, float w);

// tuples/ops.c
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);
t_tuple	tuple_neg(t_tuple a);
t_tuple	tuple_mul(double q, t_tuple a);
t_tuple	crossprod(t_tuple a, t_tuple b);

// tuples/scalar_ops.c
int		eq(double a, double b);
double	modulus(t_tuple a);
t_tuple	normalize(t_tuple a);
double	dotprod(t_tuple a, t_tuple b);

#endif
