/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:16:57 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/09 14:17:32 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_light	light_point(const t_tuple position, const t_tmp_pixel intensity)
{
	t_light	light;

	light.position = position;
	light.intensity = intensity;
	return (light);
}