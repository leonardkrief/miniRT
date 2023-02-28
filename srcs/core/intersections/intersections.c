/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:21:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 23:20:08 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

t_intersection	*intersection(t_object_id object_id, t_object *object)
{
	t_intersection	*itr;

	if (object_id < MIN_ID || object_id > MAX_ID)
	{
		ft_puterror(ERROR_INTERSECTION, ": unknown object");
		return (NULL);
	}
	itr = ft_calloc(1, sizeof (*itr));
	if (!itr)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__), NULL);
	itr->id = object_id;
	if (itr->id == SPHERE_ID)
		itr->ob = (t_sphere *)object;
	else if (itr->id == PLANE_ID)
		itr->ob = (t_sphere *)object;
	return (itr);
}

t_tuple	normal_at(const t_object_id id, const t_object *obj, t_tuple point)
{
	if (id == SPHERE_ID)
		return (normal_at_sp((t_sphere *)obj, point));
	else if (id == PLANE_ID)
		return (normal_at_pl((t_plane *)obj, point));
	// else if (id == CYLINDER_ID)
	// 	return (normal_at_cy((t_cylinder *)obj, point));
	// else if (id == TRIANGLE_ID)
	// 	return (normal_at_co((t_triangle *)obj, point));
	ft_puterror(UNKNOWN_OBJECT, (char *)__func__);
	return (tuple(0, 0, 0, 0));
}

void	ft_lstadd_sort_intersection(t_intersection	**lst_addr,
			t_intersection *itr, int order)
{
	t_intersection	*lst;

	lst = *lst_addr;
	if (lst == NULL)
		*lst_addr = itr;
	else
	{
		if (order * lst->t > order * itr->t)
		{
			itr->next = lst;
			*lst_addr = itr;
		}
		else
		{
			while (lst->next && order * lst->next->t < order * itr->t)
				lst = lst->next;
			itr->next = lst->next;
			lst->next = itr;
		}
	}
}

void	add_intersection_to_ray(t_ray *ray, t_intersection *itr)
{
	if (itr->t > 0)
		ft_lstadd_sort_intersection(&ray->itr_front, itr, 1);
	else if (itr->t < 0)
		ft_lstadd_sort_intersection(&ray->itr_back, itr, -1);
	else
		free(itr);
}

void	free_intersection(t_intersection *itr)
{
	t_intersection	*tmp;

	while (itr)
	{
		tmp = itr;
		itr = itr->next;
		free(tmp);
	}
}
