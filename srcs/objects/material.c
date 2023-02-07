/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:31:45 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:45:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_light	point_light(const t_tuple position, const t_tmp_pixel intensity)
{
	t_light	light;

	light.position = position;
	light.intensity = intensity;
	return (light);
}

t_material	material(void)
{
	t_material	mat;

	mat.color = tmp_pixel(1, 1, 1, 0);
	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200;
	return (mat);
}