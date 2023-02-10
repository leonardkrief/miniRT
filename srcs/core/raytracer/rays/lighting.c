/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:10:56 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 03:52:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

// Il faudra reduire le nombre de variables de cette fonction
// Ca va car elle n'est utilisee qu'a un seul autre endroit
// Dans world/hits.c dans shade_hit()
t_tmp_pixel	lighting(const t_material material, const t_light light, const t_tuple hit, const t_tuple eyev, t_tuple normalv)
{
	t_tmp_pixel	effective_color;
	t_tuple	lightv;
	t_tmp_pixel	ambient;
	double	light_dot_normal;

	t_tmp_pixel	diffuse;
	t_tmp_pixel	specular;

	double	factor;
	t_tuple	reflectv;
	double	reflect_dot_eye;

	effective_color = tmp_pixel_mul(material.color, light.intensity);
	lightv = tuple_normalize(tuple_sub(light.position, hit));
	ambient = tmp_pixel_scal(material.ambient, effective_color);
	light_dot_normal = tuple_dotprod(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = tmp_pixel(TMP_PIXEL_BLACK, 0);
		specular = tmp_pixel(TMP_PIXEL_BLACK, 0);
	}
	else
	{
		diffuse = tmp_pixel_scal(material.diffuse * light_dot_normal, effective_color);
		reflectv = tuple_reflect(tuple_neg(lightv), normalv);
		reflect_dot_eye = tuple_dotprod(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = tmp_pixel(TMP_PIXEL_BLACK, 0);
		else
		{
			factor = powf(reflect_dot_eye, material.shininess);
			specular = tmp_pixel_scal(material.specular * factor, light.intensity);
		}
	}
	return (tmp_pixel_add(tmp_pixel_add(ambient, diffuse), specular));
}
