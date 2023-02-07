/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:09:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:21:19 by lkrief           ###   ########.fr       */
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

