/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:34:33 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:45:13 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	point(float x, float y, float z)
{
	t_tuple a; 

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 1;
	return (a);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 0;
	return (a);
}

t_tuple	tuple(float x, float y, float z, float w)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = w;
	return (a);
}
