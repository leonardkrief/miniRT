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

#ifndef STRUCTS_RAYTRACER_H
# define STRUCTS_RAYTRACER_H

// Splitting these files into structs.h was necessary to avoid circular
// dependecies between header files...

# include "structs_geometry.h"
# include "structs_objects.h"
# include "structs_mlx.h"

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

// This would go so smooth with classes and operators overloading...
// I store my objects inside an allocated list
// and my lights inside an array of defined max size
typedef struct s_world
{
	t_object_list	*objs;
	unsigned int	nb_lights;
	t_light			lights[10];
	t_tmp_pixel		ambient;
	bool			def_ambient;
	bool			def_camera;
	bool			def_light;
}	t_world;

typedef struct s_computations{
	t_world		*world;
	double			t;
	t_object_id		id;
	t_object		*ob;
	t_tuple			point;
	t_tuple			over_point;
	t_tuple			eye;
	t_tuple			normal;
	bool			inside;
}	t_computations;

// To make calculations faster, camera.transform is directly 
// stored as inverted matrix. IMPORTANT TO REMEMBER !
typedef struct s_camera{
	int			height;
	int			width;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transform;
	t_matrix	inv_transform;
}	t_camera;

typedef struct s_all{
	t_canvas	*canvas;
	t_world		*world;
	t_camera	*camera;
}	t_all;

#endif