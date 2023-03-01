/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:11:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/01 03:02:31 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_material	material(void)
{
	t_material	mat;

	ft_memset(&mat, 0, sizeof(mat));
	mat.color = tmp_pixel(1, 1, 1, 0);
	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200;
	return (mat);
}

void	transform_object(const t_object *obj, const t_object_id id,
				const t_matrix m)
{
	if (id == SPHERE_ID)
		transform_sp((t_sphere *)obj, m);
	else if (id == PLANE_ID)
		transform_pl((t_plane *)obj, m);
	else if (id == CYLINDER_ID)
		transform_cy((t_cylinder *)obj, m);
}
