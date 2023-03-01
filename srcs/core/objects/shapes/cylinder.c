/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:09:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/01 02:17:19 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere	*cylinder(void)
{
	t_cylinder	*cy;

	cy = ft_calloc(1, sizeof (*cy));
	if (cy == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return (NULL);
	}
	cy->m = matrix_identity();
	cy->t_m = cy->m;
	cy->mat = material();
	return (cy);
}

void	transform_sp(t_sphere *sp, const t_matrix m)
{
	sp->m = matrix_matrix(matrix_invert(m, 4), sp->m, 4);
	sp->t_m = matrix_transpose(sp->m);
}

void	sphere_print_padding(const t_sphere *sphere, const char *name,
			const int padding)
{
	(void)sphere;
	(void)name;
	(void)padding;
	// int		len;
	// t_tuple	t;

	// len = ft_strlen(name);
	// printf("%*s%ssph: { origin:\t", padding, "", name);
	// t = matrix_vect(matrix_invert(sphere.m, 4), sphere.origin);
	// tuple_raw_print(t);
	// printf(",\n%*s", padding, "");
	// printf("%*sradius:\t% .2f\n%*s", len + 7, "", sphere.radius, padding, "");
	// printf("%*s}\n", len + 5, "");
}

void	sphere_print(const t_sphere *sphere, const char *name)
{
	sphere_print_padding(sphere, name, 0);
}