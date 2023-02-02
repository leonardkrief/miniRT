/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 19:24:42 by lkrief           ###   ########.fr       */
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
void	print_tuple(t_tuple *a, char *name);

// tuples/init.c
void	v_point(t_tuple *a, float x, float y, float z);
t_tuple	*p_point(float x, float y, float z);
void	v_vector(t_tuple *a, float x, float y, float z);
t_tuple	*p_vector(float x, float y, float z);

// tuples/scalar_ops.c
int	eq(double a, double b);
double	modulus(t_tuple *a);
void	normalize(t_tuple *a);
double	dotprod(t_tuple *a, t_tuple *b);

// tuples/ops/p_ops.c
t_tuple	*p_add(t_tuple *a, t_tuple *b);
t_tuple	*p_sub(t_tuple *a, t_tuple *b);
t_tuple	*p_neg(t_tuple *a);
t_tuple	*p_mul(double q, t_tuple *a);
t_tuple	*p_crossprod(t_tuple *a, t_tuple *b);

// tuples/ops/v_ops.c
void	v_add(t_tuple *a, t_tuple *b);
void	v_sub(t_tuple *a, t_tuple *b);
void	v_neg(t_tuple *a);
void	v_mul(double q, t_tuple *a);
void	v_crossprod(t_tuple *a, t_tuple *b);

#endif
