/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 16:58:52 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "libft.h"
# include "tuples.h"
# include "matrixes.h"
# include "error_handler.h"

# define SPHERE_ID		UINT32_C(1)
# define CYLINDER_ID	UINT32_C(2)
# define TRIANGLE_ID	UINT32_C(3)
# define MAX_ID			TRIANGLE_ID

typedef uint32_t t_geometric_figure;

typedef struct s_sphere{
	t_tuple		origin;
	double		radius;
	t_matrix	m;
} t_sphere;

typedef struct s_cylinder{
	t_tuple		origin;
	double		height;
	double		radius;
	t_matrix	m;
} t_cylinder;

typedef struct s_triangle{
	t_tuple		A;
	t_tuple		B;
	t_tuple		C;
	t_matrix	m;
} t_triangle;

static const t_geometric_figure	fig_size[MAX_ID + 1] = {
		[SPHERE_ID]   = sizeof(t_sphere), 
		[CYLINDER_ID] = sizeof(t_cylinder), 
		[TRIANGLE_ID] = sizeof(t_triangle)
	};

# define MAX_INTERSECTIONS 10
typedef struct	s_intersection{
	double					t;
	t_geometric_figure		id;
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

typedef struct	s_raytracer{
	t_ray			ray;
	t_intersection	itr_front;
	t_intersection	itr_back;
} t_raytracer;

// rays/print.c
void	ray_print_padding(const t_ray ray, const char *name, const int padding);
void	ray_print(const t_ray ray, const char *name);
void	sphere_print_padding(const t_sphere sphere, const char *name, const int padding);
void	sphere_print(const t_sphere sphere, const char *name);
void	intersection_print_padding(const t_intersection itr, const char *name, const int padding);
void	intersection_print(const t_intersection itr, const char *name);
void	raytracer_print(const t_raytracer rt, const char *name);

// rays/rays.c
t_raytracer	raytracer(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);
t_intersection intersection(t_geometric_figure geometric_figure_id, double t, void * figure);
t_ray	matrix_ray(const t_matrix *m, const t_ray *ray);
t_ray	ray_translation(const t_ray *ray, const t_tuple ts);
t_ray	ray_scaling(const t_ray *ray, const t_tuple ts);

// rays/sphere.c
t_sphere	*sphere(t_tuple origin, double radius);
void	transform_sp(t_sphere *sp, const t_matrix *m);
void	intersection_sp(t_raytracer *rt, const t_sphere *sp);

// void (*intersection_function[MAX_ID + 1])() = {
// 		[SPHERE_ID] = sp_intersection
// 	};

#endif
