/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:17:38 by lkrief           ###   ########.fr       */
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

typedef	struct s_tmp_pixel
{
	float	r;
	float	g;
	float	b;
	float	a;
} t_tmp_pixel;

typedef uint32_t t_pixel;
typedef unsigned char t_pixel_color;

# define	TMP_PIXEL_BLACK 0, 0, 0
# define	TMP_PIXEL_WHITE 1, 1, 1
# define	PIXEL_BLACK 0, 0, 0
# define	PIXEL_WHITE 255, 255, 255

// graphics/graphics.c
t_window	*window(t_window *window);
t_image	*image(t_image *image, void *mlx);
t_canvas	*canvas(t_canvas *canvas);
void	put_pixel(t_image *img, int x, int y, t_pixel pixel);

// graphics/conversions.c
t_tuple	pixel_to_point(const t_image *img, const int i, const int j);
t_tuple	point_to_pixel(const t_image *img, const double x, const double y);

// graphics/tmp_pixels/tmp_pixels.c
t_tmp_pixel	tmp_pixel(const float r, const float g, const float b, const float a);

// graphics/tmp_pixels/print.c
void	tmp_pixel_print(const t_tmp_pixel p, const char *name);

// graphics/tmp_pixels/ops.c
t_tmp_pixel	tmp_pixel_add(const t_tmp_pixel p, const t_tmp_pixel q);
t_tmp_pixel	tmp_pixel_sub(const t_tmp_pixel p, const t_tmp_pixel q);
t_tmp_pixel	tmp_pixel_scal(const double q, const t_tmp_pixel p);
t_tmp_pixel	tmp_pixel_mul(const t_tmp_pixel p, const t_tmp_pixel q);

// graphics/free.c
void	free_window(const t_window *window);
void	free_image(const t_image *image);
void	free_canvas(const t_canvas *canvas);

// graphics/pixels/print.c
void	pixel_print(const t_pixel p, const char *name);

// graphics/pixels/pixels.c
t_pixel	pixel(const t_pixel_color r, const t_pixel_color g, const t_pixel_color b, const t_pixel_color a);
t_pixel_color	pixel_get_a(const t_pixel pixel);
t_pixel_color	pixel_get_r(const t_pixel pixel);
t_pixel_color	pixel_get_g(const t_pixel pixel);
t_pixel_color	pixel_get_b(const t_pixel pixel);

// graphics/pixels/ops.c
t_pixel	pixel_add(const t_pixel p, const t_pixel q);
t_pixel	pixel_sub(const t_pixel p, const t_pixel q);
t_pixel	pixel_scal(const double q, const t_pixel p);
t_pixel	pixel_mul(const t_pixel p, const t_pixel q);

#endif
