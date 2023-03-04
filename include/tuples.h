/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/04 00:34:27 by lkrief           ###   ########.fr       */
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

# define EPSILON	__DBL_EPSILON__ * 1e6
# define MAX_PRINT_LEN "8"
# define PRECISION "3"
# define TUPLE_FORMAT "%+-"MAX_PRINT_LEN"."PRECISION"lf"
# define TUPLE_FORMAT_SINGLE "%+-1."PRECISION"lf"

// geometry/tuples/ops2.c
t_tuple	tuple_reflect(const t_tuple ray, const t_tuple normal);

// geometry/tuples/print.c
void	tuple_raw_print(t_tuple a);
void	tuple_print(t_tuple a, char *name);

// geometry/tuples/init.c
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
t_tuple	tuple(double x, double y, double z, double w);

// geometry/tuples/ops1.c
t_tuple	tuple_add(const t_tuple a, const t_tuple b);
t_tuple	tuple_sub(const t_tuple a, const t_tuple b);
t_tuple	tuple_neg(const t_tuple a);
t_tuple	tuple_mul(const double q, const t_tuple a);
t_tuple	tuple_crossprod(const t_tuple a, const t_tuple b);

// geometry/tuples/scalar_ops.c
int	eq(double a, double b);
double	tuple_modulus(t_tuple a);
t_tuple	tuple_normalize(t_tuple a);
double	tuple_dotprod(const t_tuple a, const t_tuple b);

#endif
