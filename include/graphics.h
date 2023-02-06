/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/05 20:05:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "tuples.h"

# define WINDOW_NAME	"miniRT"
# define HEIGHT			500
# define WIDTH			500
typedef struct s_window{
	void	*mlx;
	void	*win;
} t_window;

typedef struct s_image {
	void	*mlx;
	void	*img;
	char	*addr;
	t_tuple	origin;
	t_tuple	extension;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_canvas{
	t_window	window;
	t_image		image;
} t_canvas;

typedef uint32_t t_pixel;
typedef unsigned char t_pixel_color;

// graphics//graphics.c
t_window	*window(t_window *window);
t_image	*image(t_image *image, void *mlx);
t_canvas	*canvas(t_canvas *canvas);
void	put_pixel(t_image img, int x, int y, t_pixel pixel);

// graphics//free.c
void	free_window(t_window *window);
void	free_image(t_image *image);
void	free_canvas(t_canvas *canvas);

// graphics//pixels/print.c
void	pixel_print(t_pixel p, char *name);

// graphics//pixels/pixels.c
t_pixel	pixel(t_pixel_color r, t_pixel_color g, t_pixel_color b, t_pixel_color a);
t_pixel_color	pixel_get_a(t_pixel pixel);
t_pixel_color	pixel_get_r(t_pixel pixel);
t_pixel_color	pixel_get_g(t_pixel pixel);
t_pixel_color	pixel_get_b(t_pixel pixel);

// graphics//pixels/ops.c
t_pixel	pixel_add(t_pixel p, t_pixel q);
t_pixel	pixel_sub(t_pixel p, t_pixel q);
t_pixel	pixel_scal(float q, t_pixel p);
t_pixel	pixel_mul(t_pixel p, t_pixel q);

// graphics//pixels/conversions.c
t_tuple	pixel_to_point(t_image *img, int i, int j);
t_tuple	point_to_pixel(t_image *img, double x, double y);

#endif
