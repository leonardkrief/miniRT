/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:27:54 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 15:04:11 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

# include "matrixes.h"

// transformations/transformations1.c
t_matrix	translation(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	x_rotation(double r);
t_matrix	y_rotation(double r);
t_matrix	z_rotation(double r);

// transformations/transformations2.c
t_matrix	shearing(double x[2], double y[2], double z[2]);

#endif