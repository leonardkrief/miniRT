/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 15:00:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXELS_H
# define PIXELS_H

# include <stdio.h>
# include <math.h>
# include "tuples.h"

typedef uint32_t t_pixel;
typedef unsigned char t_pixel_color;

# include "graphics.h"

// pixels/conversions.c
t_tuple	pixel_to_point(t_image image, int i, int j);
t_tuple	point_to_pixel(t_image image, double x, double y);

// pixels/print.c
void	pixel_print(t_pixel p, char *name);

// pixels/pixels.c
t_pixel	pixel(t_pixel_color r, t_pixel_color g, t_pixel_color b, t_pixel_color a);
t_pixel_color	pixel_get_a(t_pixel pixel);
t_pixel_color	pixel_get_r(t_pixel pixel);
t_pixel_color	pixel_get_g(t_pixel pixel);
t_pixel_color	pixel_get_b(t_pixel pixel);

// pixels/ops.c
t_pixel	pixel_add(t_pixel p, t_pixel q);
t_pixel	pixel_sub(t_pixel p, t_pixel q);
t_pixel	pixel_scal(float q, t_pixel p);
t_pixel	pixel_mul(t_pixel p, t_pixel q);

#endif
