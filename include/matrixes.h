/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 08:02:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIXES_H
# define MATRIXES_H

# include "miniRT.h"

typedef struct s_matrix{
	double	m[4][4];
} t_matrix;

// matrixes/print.c
void	print_row(t_matrix m, int n);
void	print_matrix(t_matrix m, char *name);

// matrixes/init.c
void	insert_col_in_matrix(t_matrix *m, t_tuple a, int n);
t_matrix	matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d);

// matrixes/ops.c
t_tuple	matrix_vect(t_matrix m, t_tuple t);
t_matrix	matrix_matrix(t_matrix m, t_matrix n);
t_matrix	transpose(t_matrix m);

// matrixes/invert.c
t_matrix	submatrix(t_matrix a, int n, int m);
double	det(t_matrix m, int dim);

#endif
