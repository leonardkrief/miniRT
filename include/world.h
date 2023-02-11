/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:06:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 17:21:14 by lkrief           ###   ########.fr       */
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
# include "object_lists.h"
# include "raytracer.h"
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

// default camera moves settings
# define CAMERA_TRANSLATION_SENSITIVITY	0.4
# define CAMERA_ROTATION_SENSITIVITY	M_PI / 20

typedef struct s_computations{
	double			t;
	t_object_id		id;
	t_object		*ob;
	t_tuple			point;
	t_tuple			eye;
	t_tuple			normal;
	bool			inside;
}	t_computations;

// core/world/display.c
void	all(t_all *args, t_canvas *cvs, t_camera *c, t_world *w);
void	display_loop(t_all *args);

// core/world/print.c
void	world_print(t_world *world);

// core/world/hits.c
t_computations	prepare_computations(const t_ray *ray, const t_intersection *itr);
t_tmp_pixel	shade_hit(const t_world *w, const t_computations *c);
t_pixel	color_at(const t_world *w, const t_ray *ray);

// core/world/world.c
t_object_list	*new_object(const int id);
t_world	world(void);
void	intersect_world(const t_world *world, const t_ray *ray);
void	free_world(t_world *world);

// core/world/add_elements.c
void	world_add_light(t_world *world, t_light light);
void	world_add_sphere(t_world *world, t_sphere *sp);

// core/world/camera.c
t_camera	camera(double camera_width, double camera_height, double fov);
void	pixel_size(t_camera *c);
t_ray	ray_for_pixel(const t_camera *c, const int i, const int j);
void	camera_transform(t_camera *c, const t_matrix transform);
void	render(const t_canvas *cvs, const t_camera *c, const t_world *w);

// core/world/transformations.c
void	view_transform(t_camera *c, t_tuple from, t_tuple to, t_tuple up);

// core/world/object_lists/basics.c
t_object_list	*ft_lstnew(void *ob, int id);
int	ft_lstsize(t_object_list *lst);
void	ft_lstadd_back(t_object_list **lst, t_object_list *new);
void	ft_lstadd_front(t_object_list **lst, t_object_list *new);
void	ft_lstdelone(t_object_list *lst, void (*del)(void*));

// core/world/object_lists/more.c
void	ft_lstclear(t_object_list **lst, void (*del)(void*));
void	ft_lstiter(t_object_list *lst, void (*f)(void *));
t_object_list	*ft_lstlast(t_object_list *lst);
void	ft_lstprint(t_object_list *lst);

#endif