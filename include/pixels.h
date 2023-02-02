/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 23:47:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXELS_H
# define PIXELS_H

# include "miniRT.h"

typedef uint32_t t_pixel;
typedef unsigned char t_color;

// pixels/print.c
void	print_pixel(t_pixel p, char *name);

// pixels/pixels.c
t_pixel	pixel(t_color r, t_color g, t_color b, t_color a);
t_color	get_a(t_pixel pixel);
t_color	get_r(t_pixel pixel);
t_color	get_g(t_pixel pixel);
t_color	get_b(t_pixel pixel);

// pixels/ops.c
t_pixel	add_pixel(t_pixel p, t_pixel q);
t_pixel	sub_pixel(t_pixel p, t_pixel q);
t_pixel	scal_pixel(float q, t_pixel p);
t_pixel	mul_pixel(t_pixel p, t_pixel q);

#endif
