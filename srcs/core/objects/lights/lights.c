/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:16:57 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:12:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_light	light_point(const t_tuple position, const t_tmp_pixel intensity)
{
	t_light	light;

	light.position = position;
	light.intensity = intensity;
	light.intensity.r = (float) fmax(fmin(((double)light.intensity.r), 255), 0);
	light.intensity.g = (float) fmax(fmin(((double)light.intensity.g), 255), 0);
	light.intensity.b = (float) fmax(fmin(((double)light.intensity.b), 255), 0);
	light.intensity.a = (float) fmax(fmin(((double)light.intensity.a), 255), 0);
	return (light);
}
