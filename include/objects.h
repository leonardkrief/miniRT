/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:16:52 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 02:35:19 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "structs_geometry.h"
# include "structs_objects.h"
# include "tuples.h"
# include "matrixes.h"
# include "graphics.h"

# define SPHERE_ID		UINT32_C(1)
# define CYLINDER_ID	UINT32_C(2)
# define PLANE_ID		UINT32_C(3)
# define TRIANGLE_ID	UINT32_C(4)
# define MIN_ID			SPHERE_ID
# define MAX_ID			TRIANGLE_ID

// objects/material.c
t_material	material(void);

// objects/sphere.c
t_sphere	*sphere(void);
void	transform_sp(t_sphere *sp, const t_matrix m);
t_tuple	normal_at_sp(const t_sphere *sp, t_tuple t);
void	sphere_print_padding(const t_sphere sphere, const char *name,
			const int padding);
void	sphere_print(const t_sphere sphere, const char *name);

// lights/print.c
void	light_print_padding(const t_light *light, const char *name,
			const int padding);
void	light_print(const t_light *light, const char *name);

// lights/lights.c
t_light	light_point(const t_tuple position, const t_tmp_pixel intensity);

#endif