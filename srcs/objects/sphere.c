/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:09:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 20:52:34 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere	*sphere(t_tuple origin, double radius)
{
	t_sphere	*sp;

	if (!eq(origin.w, 1))
	{
		ft_puterror(ERROR_SPHERE, ": origin should be a point");
		return (NULL);
	}
	if (radius <= 0)
	{
		ft_puterror(ERROR_SPHERE, ": radius should be positive");
		return (NULL);
	}
	// should probably delete radius and origin attributes
	sp = ft_calloc(1, sizeof (*sp));
	if (sp == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return (NULL);
	}
	sp->origin = origin;
	sp->radius = radius;
	sp->m = matrix_identity();
	sp->t_m = sp->m;
	sp->mat = material();
	return (sp);
}

void	transform_sp(t_sphere *sp, const t_matrix *m)
{
	sp->m = matrix_matrix(sp->m, matrix_invert(*m, 4), 4);
	sp->t_m = matrix_transpose(sp->m);
}

t_tuple	normal_at_sp(const t_sphere *sp, t_tuple t)
{
	t = matrix_vect(sp->m, t);
	t.w = 0;
	t = matrix_vect(sp->t_m, t);
	t.w = 0;
	return (tuple_normalize(t));
}

void	sphere_print_padding(const t_sphere sphere, const char *name, const int padding)
{
	int	len;
	t_tuple	t;

	len = ft_strlen(name);
	printf("%*s%ssph: { origin:\t", padding, "", name);
	t = matrix_vect(matrix_invert(sphere.m, 4), sphere.origin);
	tuple_raw_print(t);
	printf(",\n%*s", padding, "");
	printf("%*sradius:\t% .2f\n%*s", len + 7, "", sphere.radius, padding, "");
	printf("%*s}\n", len + 5, "");
}

void	sphere_print(const t_sphere sphere, const char *name)
{
	sphere_print_padding(sphere, name, 0);
}
