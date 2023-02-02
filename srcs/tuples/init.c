/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:34:33 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/01 18:38:54 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	v_point(t_tuple *a, float x, float y, float z)
{
	a->x = x;
	a->y = y;
	a->z = z;
	a->w = 1;
}

t_tuple	*p_point(float x, float y, float z)
{
	t_tuple	*a;

	a = malloc(sizeof(*a));
	if (a == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	a->x = x;
	a->y = y;
	a->z = z;
	a->w = 1;
	return a;
}

void	v_vector(t_tuple *a, float x, float y, float z)
{
	a->x = x;
	a->y = y;
	a->z = z;
	a->w = 0;
}

t_tuple	*p_vector(float x, float y, float z)
{
	t_tuple	*a;

	a = malloc(sizeof(*a));
	if (a == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	a->x = x;
	a->y = y;
	a->z = z;
	a->w = 0;
	return a;
}
