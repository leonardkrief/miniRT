/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:09:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/02 17:47:31 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder	*cylinder(void)
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

void	transform_cy(t_cylinder *cy, const t_matrix m)
{
	cy->m = matrix_matrix(matrix_invert(m, 4), cy->m, 4);
	cy->t_m = matrix_transpose(cy->m);
}
