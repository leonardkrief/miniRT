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

typedef struct s_light{
	t_tuple		position;
	t_tmp_pixel	intensity;
}	t_light;

typedef struct s_material{
	t_tmp_pixel	color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

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

typedef uint32_t	t_object_id;
typedef void		t_object;

typedef struct s_object_list
{
	t_object_id				id;
	t_object				*ob;
	struct s_object_list	*next;
}	t_object_list;

#endif