/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:16:52 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/09 22:40:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "tuples.h"
# include "graphics.h"
# include "matrixes.h"
# include "lights.h"

typedef struct s_material{
	t_tmp_pixel	color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef uint32_t	t_object_id;
typedef void		t_object;


# define SPHERE_ID		UINT32_C(1)
# define CYLINDER_ID	UINT32_C(2)
# define PLANE_ID		UINT32_C(3)
# define TRIANGLE_ID	UINT32_C(4)
# define MIN_ID			SPHERE_ID
# define MAX_ID			TRIANGLE_ID

typedef struct s_sphere{
	t_material	mat;
	t_matrix	m;
	t_matrix	t_m;
}	t_sphere;

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

// static const t_object_id	fig_size[MAX_ID + 1] = {
// 		[SPHERE_ID]   = sizeof(t_sphere), 
// 		[CYLINDER_ID] = sizeof(t_cylinder), 
// 		[TRIANGLE_ID] = sizeof(t_triangle)
// 	};

// objects/material.c
t_material	material(void);

// objects/sphere.c
t_sphere	*sphere(void);
void	transform_sp(t_sphere *sp, const t_matrix *m);
t_tuple	normal_at_sp(const t_sphere *sp, t_tuple t);
void	sphere_print_padding(const t_sphere sphere, const char *name,
			const int padding);
void	sphere_print(const t_sphere sphere, const char *name);

#endif