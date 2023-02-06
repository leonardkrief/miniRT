/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:32 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 03:27:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "libft.h"
# include "tuples.h"
# include "error_handler.h"

# define SPHERE_ID		UINT32_C(1)
# define CYLINDER_ID	UINT32_C(2)
# define TRIANGLE_ID	UINT32_C(3)
# define MAX_ID			TRIANGLE_ID

typedef uint32_t t_geometric_figure;

typedef struct s_sphere{
	t_tuple	origin;
	double	radius;
} t_sphere;

typedef struct s_cylinder{
	t_tuple	origin;
	double	height;
	double	radius;
} t_cylinder;

typedef struct s_triangle{
	t_tuple	A;
	t_tuple	B;
	t_tuple	C;
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
	t_intersection	itr_front;
	t_intersection	itr_back;
} t_ray;

// rays/print.c
void	ray_print(t_ray ray, char *name);
void	sphere_print_padding(t_sphere sphere, char *name, int padding);
void	sphere_print(t_sphere sphere, char *name);
void	intersection_print_padding(t_intersection itr, char *name, int padding);
void	intersection_print(t_intersection itr, char *name);

// rays/rays.c
t_ray	ray(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);
t_intersection intersection(t_geometric_figure geometric_figure_id, double t, void *figure);

// rays/sphere.c
t_sphere	*sphere(t_tuple origin, double radius);
void	intersection_sp(t_ray *ray, const t_sphere *sp);

// void (*intersection_function[MAX_ID + 1])() = {
// 		[SPHERE_ID] = sp_intersection
// 	};

#endif
