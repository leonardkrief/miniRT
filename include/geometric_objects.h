/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_objects.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:14:24 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 15:07:51 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRIC_OBJECTS_H
# define GEOMETRIC_OBJECTS_H

#include "tuples.h"
#include "rays.h"

typedef struct s_sphere{
	t_tuple	origin;
	double	radius;
} t_sphere;

typedef union u_geometric_object
{
	t_sphere	sphere;
} t_geometric_object;


#endif