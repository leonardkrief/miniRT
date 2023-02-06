/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:10:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 03:31:56 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

void	ray_print(t_ray ray, char *name)
{
	int	len;

	len = ft_strlen(name);
	printf("%sray: { origin:\t", name);
	tuple_raw_print(ray.origin);
	printf(",\n%*sdirection:\t", len + 7, "");
	tuple_raw_print(ray.direction);
	printf("\n");
	intersection_print_padding(ray.itr_front, "itr_front: ", 10);
	intersection_print_padding(ray.itr_back, "itr_back:  ", 10);
	printf("%*s}\n", len + 5, "");
}

void	sphere_print_padding(t_sphere sphere, char *name, int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%ssph: { origin:\t", padding, "", name);
	tuple_raw_print(sphere.origin);
	printf(",\n%*s", padding, "");
	printf("%*sradius:\t% .2f\n%*s", len + 7, "", sphere.radius, padding, "");
	printf("%*s}\n", len + 5, "");
}

void	sphere_print(t_sphere sphere, char *name)
{
	sphere_print_padding(sphere, name, 0);
}

void	intersection_print_padding(t_intersection itr, char *name, int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%s\t", padding, "", name);
	printf("t = " TUPLE_FORMAT_SINGLE ",\n", itr.t);
	if (itr.id == SPHERE_ID)
		sphere_print_padding(*itr.sp, "", len + 17);
}

void	intersection_print(t_intersection itr, char *name)
{
	intersection_print_padding(itr, name, 0);
}