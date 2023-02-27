/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:34:33 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/26 08:08:34 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	point(double x, double y, double z)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 1;
	return (a);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 0;
	return (a);
}

t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = w;
	return (a);
}
