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

#ifndef STRUCTS_OBJECTS_H
# define STRUCTS_OBJECTS_H

// Splitting these files into structs.h was necessary to avoid circular
// dependecies between header files...

# include "structs_geometry.h"
# include "structs_pixels.h"
# include <stdbool.h>

typedef struct s_light{
	t_tuple		position;
	t_tmp_pixel	intensity;
}	t_light;

typedef void	t_object;

typedef enum e_pattern_id
{
	STRIPED_PATTERN,
	GRADIENT_PATTERN,
	RING_PATTERN,
	THREED_CHECKER_PATTERN,
	PLATINIUM_STRIPED_PATTERN,
	MASTER_PATTERN,
	TEST_PATTERN,
}	t_pattern_id;

// A pattern is null if f == NULL
typedef struct s_pattern{
	t_tmp_pixel	color1;
	t_tmp_pixel	color2;
	t_matrix	m;
	t_tmp_pixel	(*f)(const t_tuple p, const struct s_pattern *pat);
}	t_pattern;

typedef struct s_material{
	t_tmp_pixel	color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
	t_pattern	pattern;
}	t_material;

typedef void	t_object;
typedef enum e_object_id
{
	SPHERE_ID = 1,
	PLANE_ID = 2,
	CYLINDER_ID = 3,
	TRIANGLE_ID = 4,
	MIN_ID = SPHERE_ID,
	MAX_ID = TRIANGLE_ID
}	t_object_id;
// WARNING : in my objects structs, the m matrix is already inverted
// You dont have to always recalculate it that way
typedef struct s_sphere{
	t_material	mat;
	t_matrix	m;
	t_matrix	t_m;
}	t_sphere;

typedef struct s_plane{
	t_material	mat;
	t_matrix	m;
	t_matrix	t_m;
}	t_plane;

typedef struct s_cylinder{
	t_tuple		origin;
	double		height;
	double		radius;
	t_matrix	m;
}	t_cylinder;

typedef struct s_triangle{
	t_tuple		a;
	t_tuple		b;
	t_tuple		c;
	t_matrix	m;
}	t_triangle;

typedef struct s_object_list
{
	t_object_id				id;
	t_object				*ob;
	struct s_object_list	*next;
}	t_object_list;

#endif