/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 21:52:12 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "structs_all.h"
# include "libft.h"
# include "tuples.h"
# include "matrixes.h"
# include "objects.h"
# include "error_handler.h"

// raytracer/intersections/intersections.c
t_intersection	*intersection(t_object_id object_id, t_object *object);
t_tuple	normal_at(const t_object_id id, const t_object *obj, t_tuple point);
void	ft_lstadd_sort_intersection(t_intersection	**lst_addr,
			t_intersection *itr, int order);
void	add_intersection_to_ray(t_ray *ray, t_intersection *itr);
void	free_intersection(t_intersection *itr);

// raytracer/intersections/print.c
void	intersection_print_padding(const t_intersection itr, const char *name,
			const int padding);
void	intersection_print(const t_intersection itr, const char *name);

// raytracer/intersections/intersect_objects.c
void	intersect_sp(const t_sphere *sp, t_ray *ray0);

// raytracer/rays/print.c
void	ray_coords_print_padding(const t_ray *ray, const char *name, const int padding);
void	ray_coords_print(const t_ray *ray, const char *name);
void	ray_print(const t_ray *rt, const char *name);

// raytracer/rays/rays.c
t_ray	ray(const t_tuple origin, const t_tuple direction);
t_tuple	position(const t_ray ray, const double t);
t_ray	matrix_ray(const t_matrix *m, const t_ray *ray);

#endif
