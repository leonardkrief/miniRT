/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:10:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/09 22:30:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ray_coords_print_padding(const t_ray ray, const char *name, const int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%sray: { origin:%*s", padding, "", name, 8, "");
	tuple_raw_print(ray.origin);
	printf(",\n%*sdirection:%*s", len + 7, "", 5, "");
	tuple_raw_print(ray.direction);
	printf("\n%*s}\n", padding + len + 5, "");
}

void	ray_coords_print(const t_ray ray, const char *name)
{
	ray_coords_print_padding(ray, name, 0);
}

void	ray_print(const t_ray *rt, const char *name)
{
	int	len;

	len = ft_strlen(name);
	printf("%sray: { origin:%*s", name, 9, "");
	tuple_raw_print(rt->origin);
	printf(",\n%*sdirection:%*s", len + 13, "", 6, "");
	tuple_raw_print(rt->direction);
	printf(",\n");
	intersection_print_padding(*(rt->itr_front), "itr_front: ", 16);
	intersection_print_padding(*(rt->itr_back), "itr_back:  ", 16);
	printf("%*s}\n", len + 11, "");
}
