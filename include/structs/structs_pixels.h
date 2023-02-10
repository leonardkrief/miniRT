/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:29:27 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/10 23:46:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_PIXELS_H
# define STRUCTS_PIXELS_H

// Splitting these files into structs.h was necessary to avoid circular
// dependecies between header files...

# include <stdint.h>

typedef struct s_tmp_pixel{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_tmp_pixel;

typedef unsigned char	t_pixel_color;
typedef uint32_t		t_pixel;

#endif