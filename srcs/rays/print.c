/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:10:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 17:18:44 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	ray_print_padding(const t_ray ray, const char *name, const int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%sray: { origin:%*s", padding, "", name, 8, "");
	tuple_raw_print(ray.origin);
	printf(",\n%*sdirection:%*s", len + 7, "", 5, "");
	tuple_raw_print(ray.direction);
	printf("\n%*s}\n", padding + len + 5, "");
}

void	ray_print(const t_ray ray, const char *name)
{
	ray_print_padding(ray, name, 0);
}


void	intersection_print_padding(const t_intersection itr, const char *name, const int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%s%*s", padding + 1, "", name, 5, "");
	if (itr.sp)
	{
		printf("t = " TUPLE_FORMAT_SINGLE ",\n", itr.t);
		if (itr.id == SPHERE_ID)
			sphere_print_padding(*itr.sp, "", len + padding + 7);
	}
	else
		printf("no intersection\n\n");
}

void	intersection_print(const t_intersection itr, const char *name)
{
	intersection_print_padding(itr, name, 0);
}

void	raytracer_print(const t_raytracer rt, const char *name)
{
	int	len;

	len = ft_strlen(name);
	printf("%sraytracer: { origin:%*s", name, 9, "");
	tuple_raw_print(rt.ray.origin);
	printf(",\n%*sdirection:%*s", len + 13, "", 6, "");
	tuple_raw_print(rt.ray.direction);
	printf(",\n");
	intersection_print_padding(rt.itr_front, "itr_front: ", 16);
	intersection_print_padding(rt.itr_back, "itr_back:  ", 16);
	printf("%*s}\n", len + 11, "");
}