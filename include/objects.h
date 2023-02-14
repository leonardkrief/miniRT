/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:16:52 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 03:01:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "structs_geometry.h"
# include "structs_objects.h"
# include "tuples.h"
# include "matrixes.h"
# include "graphics.h"

// core/objects/patterns/patterns_basics.c
t_pattern	pattern(const t_tmp_pixel a, const t_tmp_pixel b, const t_pattern_id id);
t_tmp_pixel	pattern_at(const t_object *obj, const t_object_id id,
					const t_material *mat, const t_computations *c);
void	transform_pattern(t_pattern *pat, const t_matrix m);

// core/objects/patterns/patterns.c
t_tmp_pixel	stripe_at(const t_tuple p, const t_pattern *pat);
t_tmp_pixel	gradient_at(const t_tuple p, const t_pattern *pat);
t_tmp_pixel	ring_at(const t_tuple p, const t_pattern *pat);
t_tmp_pixel	threed_checker_at(const t_tuple p, const t_pattern *pat);
t_tmp_pixel	platinium_striped_at(const t_tuple p, const t_pattern *pat);
t_tmp_pixel	master_at(const t_tuple p, const t_pattern *pat);
t_tmp_pixel	test_at(const t_tuple p, const t_pattern *pat);

// core/objects/shapes/sphere.c
t_sphere	*sphere(void);
void	transform_sp(t_sphere *sp, const t_matrix m);
void	sphere_print_padding(const t_sphere sphere, const char *name,
			const int padding);
void	sphere_print(const t_sphere sphere, const char *name);

// core/objects/shapes/plane.c
t_plane	*plane(void);
void	transform_pl(t_plane *pl, const t_matrix m);

// core/objects/lights/print.c
void	light_print_padding(const t_light *light, const char *name,
			const int padding);
void	light_print(const t_light *light, const char *name);

// core/objects/lights/lights.c
t_light	light_point(const t_tuple position, const t_tmp_pixel intensity);

// core/objects/object_lists/basics.c
t_object_list	*ft_lstnew(void *ob, int id);
int	ft_lstsize(t_object_list *lst);
void	ft_lstadd_back(t_object_list **lst, t_object_list *new);
void	ft_lstadd_front(t_object_list **lst, t_object_list *new);
void	ft_lstdelone(t_object_list *lst, void (*del)(void*));

// core/objects/object_lists/more.c
void	ft_lstclear(t_object_list **lst, void (*del)(void*));
void	ft_lstiter(t_object_list *lst, void (*f)(void *));
t_object_list	*ft_lstlast(t_object_list *lst);
void	ft_lstprint(t_object_list *lst);

// core/objects/objects.c
t_material	material(void);
void	transform_object(const t_object *obj, const t_object_id id,
				const t_matrix m);

#endif