/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:06:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/13 16:29:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "tuples.h"
# include "objects.h"
# include "rays.h"
# include "intersections.h"
# include "error_handler.h"
# include "structs_all.h"

// raytracer rendering limits
# define MAX_OBJECTS	100
# define MAX_LIGHTS		10

// default camera size settings
# define DEFAULT_CAMERA_HEIGHT_HI		WINDOW_HEIGHT
# define DEFAULT_CAMERA_HEIGHT_LO		WINDOW_HEIGHT / 2
# define DEFAULT_CAMERA_WIDTH_HI		WINDOW_WIDTH
# define DEFAULT_CAMERA_WIDTH_LO		WINDOW_WIDTH / 2
# define DEFAULT_CAMERA_FOV				M_PI / 2

# define DEFAULT_CAMERA_RES_HI			#DEFAULT_CAMERA_HEIGHT_HI, #DEFAULT_CAMERA_WIDTH_HI, #DEFAULT_CAMERA_FOV
# define DEFAULT_CAMERA_RES_LO			#DEFAULT_CAMERA_HEIGHT_LO, #DEFAULT_CAMERA_WIDTH_LO, #DEFAULT_CAMERA_FOV

// default camera position settings
# define DEFAULT_CAMERA_FROM			point(0,0,-5)
# define DEFAULT_CAMERA_TO				point(0,0,0)
# define DEFAULT_CAMERA_UP				vector(0,1,0)

// default camera movements settings
# define CAMERA_TRANSLATION_SENSITIVITY	0.4
# define CAMERA_ROTATION_SENSITIVITY	M_PI / 20

// *-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*-$-*

// core/world/print.c
void	world_print(t_world *world);

// core/world/hits.c
t_computations	prepare_computations(const t_ray *ray,
										const t_intersection *itr);
bool	is_shadowed(const t_world *w, const t_tuple point, const t_light *light);
t_tmp_pixel	shade_hit(const t_world *w, const t_computations *c);
t_tmp_pixel	lighting(const t_computations *c, const t_material *mat, 
									const t_light *light, bool in_shadow);
t_tmp_pixel	point_in_front_light(const t_computations *c, const t_material *mat,
				const t_light *light, t_tmp_pixel diffuse);
t_pixel	color_at(const t_world *w, const t_ray *ray);

// core/world/world.c
t_world	world(void);
void	intersect_world(const t_world *world, const t_ray *ray);
void	free_world(t_world *world);

// core/world/add_elements.c
void	world_add_light(t_world *world, t_light light);
void	world_add_sphere(t_world *world, t_sphere *sp);
void	world_add_plane(t_world *world, t_plane *pl);
t_object_list	*new_object(const int id);

#endif