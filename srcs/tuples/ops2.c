/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:23:34 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 23:59:44 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple_reflect(const t_tuple ray, const t_tuple normal)
{
	return (tuple_sub(ray, tuple_mul(2 * tuple_dotprod(ray, normal), normal)));
}