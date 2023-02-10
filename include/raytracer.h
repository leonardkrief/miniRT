/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 03:42:39 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "libft.h"
# include "tuples.h"
# include "matrixes.h"
# include "objects.h"
# include "error_handler.h"

typedef struct s_intersection{
	double					t;
	t_object_id				id;
	t_object				*ob;
	struct s_intersection	*next;
}	t_intersection;

typedef struct s_ray{
	t_tuple			origin;
	t_tuple			direction;
	t_intersection	*itr_front;
	t_intersection	*itr_back;
}	t_ray;

// raytracer is the structure that both casts a ray while storing
// the closest intersection
// ray:				_origin: origin of the ray
//					_direction: direction of the ray
// intersection:	_t: shortest dist from ray's origin to an object
//					_id: id of the object intersected
//					_object: pointer to the object intersected

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
void	ray_coords_print_padding(const t_ray ray, const char *name, const int padding);
void	ray_coords_print(const t_ray ray, const char *name);
void	ray_print(const t_ray *rt, const char *name);

// raytracer/rays/lighting.c
t_tmp_pixel	lighting(const t_material material, const t_light light, const t_tuple hit, const t_tuple eyev, t_tuple normalv);

// raytracer/rays/rays.c
t_ray	ray(const t_tuple origin, const t_tuple direction);
t_tuple	position(const t_ray ray, const double t);
t_ray	matrix_ray(const t_matrix *m, const t_ray *ray);

#endif
