/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:25:47 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/27 15:34:17 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

void	intersection_print_padding(const t_intersection itr, const char *name,
			const int padding)
{
	int	len;

	len = ft_strlen(name);
	printf("%*s%s%*s", padding + 1, "", name, 1, "");
	if (itr.ob)
	{
		printf("t = %f\n", itr.t);
		if (itr.id == SPHERE_ID)
			sphere_print_padding((t_sphere *)itr.ob, "", len + padding + 7);
	}
	else
		printf("no intersection\n\n");
}

void	intersection_print(const t_intersection itr, const char *name)
{
	intersection_print_padding(itr, name, 0);
}
