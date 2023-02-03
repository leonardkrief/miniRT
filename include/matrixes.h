/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 17:15:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIXES_H
# define MATRIXES_H

# include "miniRT.h"

# define MATRIX_DIM 4
typedef struct s_matrix{
	double	m[MATRIX_DIM][MATRIX_DIM];
} t_matrix;

// matrixes/print.c
void	print_row(t_matrix m, int n);
void	print_matrix(t_matrix m, char *name);

// matrixes/init.c
void	insert_col_in_matrix(t_matrix *m, t_tuple a, int n);
t_matrix	matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d);

// matrixes/ops.c
t_tuple	matrix_vect(t_matrix m, t_tuple t);
t_matrix	matrix_matrix(t_matrix m, t_matrix n, int dim);
t_matrix	transpose(t_matrix m);

// matrixes/linear_ops.c
int	null_row_forward(t_matrix m, int row);
t_matrix	swap_cols(t_matrix m, int col1, int col2);
t_matrix	row_transmutation(t_matrix m, int row, double q, int to_add);

// matrixes/invert.c
t_matrix	submatrix(t_matrix a, int row, int col);
t_matrix	pivot(t_matrix m, int col, int *row_is_null);
double	det(t_matrix m, int dim);
double	cofactor(t_matrix m, int row, int col, int dim);
t_matrix	invert(t_matrix m, int dim);


#endif
