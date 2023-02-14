/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:29:27 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 23:46:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_GEOMETRY_H
# define STRUCTS_GEOMETRY_H

// Splitting these files into structs.h was necessary to avoid circular
// dependecies between header files...

typedef struct s_tuple{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

# define MATRIX_DIM 4

typedef struct s_matrix{
	double	m[MATRIX_DIM][MATRIX_DIM];
}	t_matrix;

#endif