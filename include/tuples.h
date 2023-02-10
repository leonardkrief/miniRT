/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 00:15:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "structs_geometry.h"
# include "libft.h"
# include "error_handler.h"

# define EPSILON	__DBL_EPSILON__
# define MAX_PRINT_LEN "8"
# define PRECISION "3"
# define TUPLE_FORMAT "%+-"MAX_PRINT_LEN"."PRECISION"lf"
# define TUPLE_FORMAT_SINGLE "%+-1."PRECISION"lf"

// tuples/print.c
void	tuple_raw_print(t_tuple a);
void	tuple_print(t_tuple a, char *name);

// tuples/init.c
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
t_tuple	tuple(float x, float y, float z, float w);

// tuples/ops1.c
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);
t_tuple	tuple_neg(t_tuple a);
t_tuple	tuple_mul(double q, t_tuple a);
t_tuple	tuple_crossprod(t_tuple a, t_tuple b);

// tuples/ops2.c
t_tuple	tuple_reflect(const t_tuple r, const t_tuple n);

// tuples/scalar_ops.c
int		eq(double a, double b);
double	tuple_modulus(t_tuple a);
t_tuple	tuple_normalize(t_tuple a);
double	tuple_dotprod(t_tuple a, t_tuple b);

#endif
