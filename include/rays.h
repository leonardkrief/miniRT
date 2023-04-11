/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/11 10:45:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "error_handler.h"
# include "intersections.h"
# include "libft.h"
# include "matrixes.h"
# include "objects.h"
# include "structs_all.h"
# include "tuples.h"

// core/rays/print.c
void	ray_coords_print_padding(const t_ray *ray, const char *name,
			const int padding);
void	free_ray(t_ray r);
void	ray_coords_print(const t_ray *ray, const char *name);
void	ray_print(const t_ray *rt, const char *name);

// core/rays/rays.c
t_ray	ray(const t_tuple origin, const t_tuple direction);
t_tuple	position(const t_ray ray, const double t);
t_ray	matrix_ray(const t_matrix *m, const t_ray *ray);

#endif
