/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/08 04:31:59 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# if __APPLE__
#  include <mlx.h>
# elif __linux__
#  include "mlx.h"
# endif

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "tuples.h"

# define WINDOW_NAME	"miniRT"
# define HEIGHT			1000
# define WIDTH			1000

# if __APPLE__
#  define KEY_ESC			53
#  define KEY_UP			53
#  define KEY_DOWN			53
#  define KEY_LEFT			53
#  define KEY_RIGHT			53
#  define MOUSE_ZOOM_IN		53
#  define MOUSE_ZOOM_OUT	53
# elif __linux__
#  define KEY_ESC			65307
#  define KEY_UP			65362
#  define KEY_DOWN			65364
#  define KEY_LEFT			65361
#  define KEY_RIGHT			65363
#  define MOUSE_ZOOM_IN		53
#  define MOUSE_ZOOM_OUT	53
# endif

# define CLOSE_WINDOW_KEY_EVENT		17

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

// graphics/conversions.c
t_tuple	pixel_to_point(const t_image *img, const int i, const int j);
t_tuple	point_to_pixel(const t_image *img, const double x, const double y);

// graphics/tmp_pixels/print.c
void	tmp_pixel_print(const t_tmp_pixel p, const char *name);

// graphics/tmp_pixels/tmp_pixels.c
t_tmp_pixel	tmp_pixel(const float r, const float g, const float b, const float a);

// graphics/tmp_pixels/ops.c
t_tmp_pixel	tmp_pixel_add(const t_tmp_pixel p, const t_tmp_pixel q);
t_tmp_pixel	tmp_pixel_sub(const t_tmp_pixel p, const t_tmp_pixel q);
t_tmp_pixel	tmp_pixel_scal(const double q, const t_tmp_pixel p);
t_tmp_pixel	tmp_pixel_mul(const t_tmp_pixel p, const t_tmp_pixel q);

// graphics/mlx_hooks/input.c
void	input_key_camera_translation(int keysym, t_canvas *cvs);
void	input_key_close_window(int keysym, t_canvas *cvs);
int		input_key(int keysym, t_canvas *cvs);

int		input_mouse(int mousesym, int x, int y, t_canvas *cvs);

// graphics/graphics.c
t_window	*window(t_window *window);
t_image	*image(t_image *image, void *mlx);
t_canvas	*canvas(t_canvas *canvas);
void	put_pixel(t_image *img, int x, int y, t_pixel pixel);

// graphics/free.c
void	free_window(const t_window *window);
void	free_image(const t_image *image);
int		free_canvas(const t_canvas *canvas);

#endif
