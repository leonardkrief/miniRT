/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:06:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 05:48:46 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "tuples.h"
# include "objects.h"
# include "object_lists.h"
# include "raytracer.h"
# include "error_handler.h"

# define MAX_OBJECTS	100
# define MAX_LIGHTS		10

// This would go so smooth with classes and operators overloading...
// I store my objects inside an allocated list
// and my lights inside an array of defined max size
typedef struct s_world
{
	t_object_list	*objs;
	unsigned int	nb_lights;
	t_light			lights[10];
}	t_world;

typedef struct s_computations{
	double			t;
	t_object_id		id;
	t_object		*ob;
	t_tuple			point;
	t_tuple			eye;
	t_tuple			normal;
	bool			inside;
}	t_computations;

// world/print.c
void	world_print(t_world *world);

// world/hits.c
t_computations	prepare_computations(const t_ray *ray, const t_intersection *itr);
t_tmp_pixel	shade_hit(const t_world *w, const t_computations *c);
t_pixel	color_at(const t_world *w, const t_ray *ray);

// world/world.c
t_object_list	*new_object(const int id);
t_world	world(void);
void	intersect_world(const t_world *world, const t_ray *ray);
void	free_world(t_world *world);

// world/add_elements.c
void	world_add_light(t_world *world, t_light *light);
void	world_add_sphere(t_world *world, t_sphere *sp);

// world/transformations.c
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

// world/object_lists/basics.c
t_object_list	*ft_lstnew(void *ob, int id);
int	ft_lstsize(t_object_list *lst);
void	ft_lstadd_back(t_object_list **lst, t_object_list *new);
void	ft_lstadd_front(t_object_list **lst, t_object_list *new);
void	ft_lstdelone(t_object_list *lst, void (*del)(void*));

// world/object_lists/more.c
void	ft_lstclear(t_object_list **lst, void (*del)(void*));
void	ft_lstiter(t_object_list *lst, void (*f)(void *));
t_object_list	*ft_lstlast(t_object_list *lst);
void	ft_lstprint(t_object_list *lst);

#endif