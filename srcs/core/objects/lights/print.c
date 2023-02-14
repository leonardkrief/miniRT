/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:55:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 00:47:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	light_print_padding(const t_light *light, const char *name,
			const int padding)
{
	int		len;
	t_tuple	intensity;

	intensity.x = light->intensity.r;
	intensity.y = light->intensity.g;
	intensity.z = light->intensity.b;
	intensity.w = light->intensity.a;
	len = ft_strlen(name);
	printf("%*s%slight: { position:%*s", padding, "", name, 8, "");
	tuple_raw_print(light->position);
	printf(",\n%*sintensity:%*s", padding + len + 9, "", 7, "");
	tuple_raw_print(intensity);
	printf("\n%*s}\n", padding + len + 7, "");
}

void	light_print(const t_light *light, const char *name)
{
	light_print_padding(light, name, 0);
}
