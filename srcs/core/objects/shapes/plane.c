/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:09:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 13:43:55 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_plane	*plane(void)
{
	t_plane	*pl;

	pl = ft_calloc(1, sizeof (*pl));
	if (pl == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return (NULL);
	}
	pl->m = matrix_identity();
	pl->t_m = pl->m;
	pl->mat = material();
	return (pl);
}

void	transform_pl(t_plane *pl, const t_matrix m)
{
	pl->m = matrix_matrix(matrix_invert(m, 4), pl->m, 4);
	pl->t_m = matrix_transpose(pl->m);
}
