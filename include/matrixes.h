/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/11 12:43:29 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIXES_H
# define MATRIXES_H

# include "error_handler.h"
# include "libft.h"
# include "structs_all.h"
# include "tuples.h"
# include <stdio.h>

// geometry/matrixes/transformations/transformations2.c
t_matrix	matrix_shearing(const double x[2], const double y[2],
				const double z[2]);

// geometry/matrixes/transformations/transformations1.c
t_matrix	matrix_translation(const double x, const double y, const double z);
t_matrix	matrix_scaling(const double x, const double y, const double z);
t_matrix	matrix_rotation_x(const double r);
t_matrix	matrix_rotation_y(const double r);
t_matrix	matrix_rotation_z(const double r);

// geometry/matrixes/print.c
void		matrix_print_row_padding(const t_matrix m, const int n,
				const int padding);
void		matrix_print_padding(const t_matrix m, const char *name,
				const int padding);
void		matrix_print(const t_matrix m, const char *name);

// geometry/matrixes/init.c
void		matrix_insert_col(t_matrix *m, const t_tuple a, const int n);
t_matrix	matrix(const t_tuple a, const t_tuple b, const t_tuple c,
				const t_tuple d);
t_matrix	matrix_identity(void);

// geometry/matrixes/ops.c
t_tuple		matrix_vect(const t_matrix m, const t_tuple t);
t_matrix	matrix_matrix(const t_matrix m, const t_matrix n, const int dim);
t_matrix	matrix_transpose(t_matrix m);

// geometry/matrixes/linear_ops.c
int			matrix_null_row_forward(const t_matrix m, const int row,
				const int dim);
t_matrix	matrix_swap_cols(t_matrix m, const int col1, const int col2);
t_matrix	matrix_row_transmutation(t_matrix m, const int row, const double q,
				const int to_add);

// geometry/matrixes/invert.c
t_matrix	matrix_submatrix(t_matrix a, const int row, const int col);
t_matrix	matrix_pivot(t_matrix m, const int col, const int dim,
				int *row_is_null);
double		det(t_matrix m, const int dim);
double		matrix_cofactor(const t_matrix m, const int row, const int col,
				const int dim);
t_matrix	matrix_invert(const t_matrix m, const int dim);

#endif
