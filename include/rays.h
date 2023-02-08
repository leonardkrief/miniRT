/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 23:44:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "libft.h"
# include "tuples.h"
# include "matrixes.h"
# include "objects.h"
# include "error_handler.h"

# define MAX_INTERSECTIONS 10
typedef struct	s_intersection{
	double		t;
	t_shape		id;
	union{
		t_sphere *sp;
		t_cylinder *cy;
		t_triangle *tr;
	};
} t_intersection;

typedef struct	s_ray{
	t_tuple			origin;
	t_tuple			direction;
} t_ray;

// raytracer is the main structure used to cast a ray and store the closest intersection
// ray:				-origin:	origin of the ray
//					-direction:	direction of the ray
// intersection:	-t:			shortest distance from the origin of the ray to an object
//					-id:		id of the object intersected
//					-object:	pointer to the object intersected
typedef struct	s_raytracer{
	t_ray			ray;
	t_intersection	itr_front;
	t_intersection	itr_back;
} t_raytracer;

// rays/print.c
void	ray_print_padding(const t_ray ray, const char *name, const int padding);
void	ray_print(const t_ray ray, const char *name);
void	intersection_print_padding(const t_intersection itr, const char *name, const int padding);
void	intersection_print(const t_intersection itr, const char *name);
void	raytracer_print(const t_raytracer rt, const char *name);

// rays/lighting.c
t_tmp_pixel	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv);

// rays/rays.c
t_raytracer	raytracer(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);
t_intersection intersection(t_shape geometric_figure_id, double t, void * figure);
t_ray	matrix_ray(const t_matrix *m, const t_ray *ray);
t_ray	ray_translation(const t_ray *ray, const t_tuple ts);
t_ray	ray_scaling(const t_ray *ray, const t_tuple ts);

// rays/sphere.c
void	intersection_sp(t_raytracer *rt, const t_sphere *sp);
t_tuple	normal_at_sp(const t_sphere *sp, t_tuple t);



// void (*intersection_function[MAX_ID + 1])() = {
// 		[SPHERE_ID] = sp_intersection
// 	};

#endif
