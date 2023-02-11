/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 12:40:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIXES_H
# define MATRIXES_H

# include <stdio.h>
# include "libft.h"
# include "tuples.h"
# include "error_handler.h"
# include "structs_all.h"

// geometry/matrixes/transformations/transformations2.c
t_matrix	matrix_shearing(double x[2], double y[2], double z[2]);

// geometry/matrixes/transformations/transformations1.c
t_matrix	matrix_translation(const double x, const double y, const double z);
t_matrix	matrix_scaling(const double x, const double y, const double z);
t_matrix	matrix_rotation_x(const double r);
t_matrix	matrix_rotation_y(const double r);
t_matrix	matrix_rotation_z(const double r);

// geometry/matrixes/print.c
// This function does not entirely depends on MATRIX_DIM
void	matrix_print_row_padding(t_matrix m, int n, int padding);
// This function does not entirely depends on MATRIX_DIM
void	matrix_print_padding(t_matrix m, char *name, int padding);
void	matrix_print(t_matrix m, char *name);

// geometry/matrixes/init.c
// This function does not entirely depends on MATRIX_DIM
void	matrix_insert_col(t_matrix *m, t_tuple a, int n);
// This function does not entirely depends on MATRIX_DIM
t_matrix	matrix(t_tuple a, t_tuple b, t_tuple c, t_tuple d);
t_matrix	matrix_identity(void);

// geometry/matrixes/ops.c
// This function does not entirely depends on MATRIX_DIM
t_tuple	matrix_vect(t_matrix m, t_tuple t);
t_matrix	matrix_matrix(t_matrix m, t_matrix n, int dim);
t_matrix	matrix_transpose(t_matrix m);

// geometry/matrixes/linear_ops.c
int	matrix_null_row_forward(t_matrix m, int row, int dim);
t_matrix	matrix_swap_cols(t_matrix m, int col1, int col2);
t_matrix	matrix_row_transmutation(t_matrix m, int row, double q, int to_add);

// geometry/matrixes/invert.c
t_matrix	matrix_submatrix(t_matrix a, int row, int col);
t_matrix	matrix_pivot(t_matrix m, int col, int dim, int *row_is_null);
double	det(t_matrix m, int dim);
double	matrix_cofactor(t_matrix m, int row, int col, int dim);
t_matrix	matrix_invert(t_matrix m, int dim);

#endif
