/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:10:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/13 00:20:44 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	ray_coords_print_padding(const t_ray *ray, const char *name, const int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%sray:   origin:%*s", padding, "", name, 5, "");
	tuple_raw_print(ray->origin);
	printf(",\n%*sdirection:%*s", len + 7, "", 2, "");
	tuple_raw_print(ray->direction);
	printf("\n");
}

void	ray_coords_print(const t_ray *ray, const char *name)
{
	ray_coords_print_padding(ray, name, 0);
}

void	ray_print(const t_ray *rt, const char *name)
{
	int	len;

	len = ft_strlen(name);
	ray_coords_print(rt, name);
	if (rt->itr_front)
		intersection_print_padding(*(rt->itr_front), "itr_front: ", len + 6);
	if (rt->itr_back)
		intersection_print_padding(*(rt->itr_back), "itr_back:  ", len + 6);
}
