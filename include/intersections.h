/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:54:12 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 13:36:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "structs_raytracer.h"
# include "matrixes.h"
# include "objects.h"

// core/intersections/intersections.c
t_intersection	*intersection(t_object_id object_id, t_object *object);
t_tuple	normal_at(const t_object_id id, const t_object *obj, t_tuple point);
void	ft_lstadd_sort_intersection(t_intersection	**lst_addr,
			t_intersection *itr, int order);
void	add_intersection_to_ray(t_ray *ray, t_intersection *itr);
void	free_intersection(t_intersection *itr);

// core/intersections/print.c
void	intersection_print_padding(const t_intersection itr, const char *name,
			const int padding);
void	intersection_print(const t_intersection itr, const char *name);

// core/intersections/intersect_plane.c
t_tuple	normal_at_pl(const t_plane *pl, t_tuple point);
void	intersect_pl(const t_plane *pl, t_ray *ray0);

// core/intersections/intersect_sphere.c
t_tuple	normal_at_sp(const t_sphere *sp, t_tuple point);
void	intersect_sp(const t_sphere *sp, t_ray *ray0);

#endif