/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:23:34 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/01 19:46:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	*p_add(t_tuple *a, t_tuple *b)
{
	t_tuple	*r;

	r = malloc(sizeof(*r));
	if (r == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	r->x = a->x + b->x;
	r->y = a->y + b->y;
	r->z = a->z + b->z;
	r->w = a->w + b->w;
	return r;
}

t_tuple	*p_sub(t_tuple *a, t_tuple *b)
{
	t_tuple	*r;

	r = malloc(sizeof(*r));
	if (r == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	r->x = a->x - b->x;
	r->y = a->y - b->y;
	r->z = a->z - b->z;
	r->w = a->w - b->w;
	return r;
}

t_tuple	*p_neg(t_tuple *a)
{
	t_tuple	*r;

	r = malloc(sizeof(*r));
	if (r == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	r->x = -a->x;
	r->y = -a->y;
	r->z = -a->z;
	r->w = -a->w;
	return r;
}

t_tuple	*p_mul(double q, t_tuple *a)
{
	t_tuple	*r;

	r = malloc(sizeof(*r));
	if (r == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	r->x = q * a->x;
	r->y = q * a->y;
	r->z = q * a->z;
	r->w = q * a->w;
	return r;
}

t_tuple	*p_crossprod(t_tuple *a, t_tuple *b)
{
	t_tuple	*r;

	r = malloc(sizeof(*r));
	if (r == NULL)
	{
		ft_puterror(FAILED_MALLOC, (char *)__func__);
		return NULL;
	}
	r->x = a->y * b->z - a->z * b->y;
	r->y = a->z * b->x - a->x * b->z;
	r->z = a->x * b->y - a->y * b->x;
	return r;
}
