/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:10:56 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:30:03 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_tmp_pixel	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
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

// combine the surface color with the light's color/intensity
	effective_color = tmp_pixel_mul(material.color, light.intensity);
// find the direction to the light source
	lightv = tuple_normalize(tuple_sub(light.position, point));
// compute the ambient contribution
	ambient = tmp_pixel_scal(material.ambient, effective_color);
// light_dot_normal represents the cosine of the angle between the
// light vector and the normal vector. A negative number means the
// light is on the other side of the surface.
	light_dot_normal = tuple_dotprod(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = tmp_pixel(TMP_PIXEL_BLACK, 0);
		specular = tmp_pixel(TMP_PIXEL_BLACK, 0);
	}
	else
	{
	// compute the diffuse contribution
		diffuse = tmp_pixel_scal(material.diffuse * light_dot_normal, effective_color);
	// reflect_dot_eye represents the cosine of the angle between the
	// reflection vector and the eye vector. A negative number means the
	// light reflects away from the eye.
		reflectv = tuple_reflect(tuple_neg(lightv), normalv);
		reflect_dot_eye = tuple_dotprod(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = tmp_pixel(TMP_PIXEL_BLACK, 0);
		else
		{
			// compute the specular contribution
			factor = pow(reflect_dot_eye, material.shininess);
			specular = tmp_pixel_scal(material.specular * factor, light.intensity);
		}
	}
// Add the three contributions together to get the final shading
	return (tmp_pixel_add(tmp_pixel_add(ambient, diffuse), specular));
}
