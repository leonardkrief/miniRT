/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 00:58:34 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# if __APPLE__
#  include <mlx.h>
#  define FREE_DISPLAY(X)
# elif __linux__
#  include "mlx.h"
#  define FREE_DISPLAY(X) mlx_destroy_display(X)
# endif

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "structs_all.h"
# include "tuples.h"
# include "world.h"

# define WINDOW_NAME	"miniRT"
# define WINDOW_HEIGHT			700
# define WINDOW_WIDTH			700

# if __APPLE__
#  define KEY_ESC			53
#  define KEY_UP			126
#  define KEY_DOWN			125
#  define KEY_LEFT			124
#  define KEY_RIGHT			123
#  define KEY_Z				13
#  define KEY_S				1
#  define KEY_Q				0
#  define KEY_D				2
#  define MOUSE_ZOOM_IN		5
#  define MOUSE_ZOOM_OUT	4
# elif __linux__
#  define KEY_ESC			65307
#  define KEY_UP			65362
#  define KEY_DOWN			65364
#  define KEY_LEFT			65361
#  define KEY_RIGHT			65363
#  define KEY_Z				-1
#  define KEY_S				-1
#  define KEY_Q				-1
#  define KEY_D				-1
#  define MOUSE_ZOOM_IN		-1
#  define MOUSE_ZOOM_OUT	-1
# endif

# define CLOSE_WINDOW_BUTTON_EVENT	17

# define TMP_PIXEL_BLACK	0, 0, 0
# define TMP_PIXEL_WHITE	1, 1, 1
# define PIXEL_BLACK		0, 0, 0
# define PIXEL_WHITE		255, 255, 255

// core/graphics/graphics.c
t_window	*window(t_window *window);
t_image	*image(t_image *image, void *mlx);
t_canvas	*canvas(t_canvas *canvas);
void	put_pixel(t_image *img, int x, int y, t_pixel pixel);

// core/graphics/conversions.c
t_tuple	pixel_to_point(const t_image *img, const int i, const int j);
t_tuple	point_to_pixel(const t_image *img, const double x, const double y);

// core/graphics/tmp_pixels/tmp_pixels.c
t_tmp_pixel	tmp_pixel(const float r, const float g, const float b,
				const float a);
t_pixel	tmp_pixel_to_pixel(const t_tmp_pixel p);

// core/graphics/tmp_pixels/print.c
void	tmp_pixel_print(const t_tmp_pixel p, const char *name);

// core/graphics/tmp_pixels/ops.c
t_tmp_pixel	tmp_pixel_add(const t_tmp_pixel p, const t_tmp_pixel q);
t_tmp_pixel	tmp_pixel_sub(const t_tmp_pixel p, const t_tmp_pixel q);
t_tmp_pixel	tmp_pixel_scal(const double q, const t_tmp_pixel p);
t_tmp_pixel	tmp_pixel_mul(const t_tmp_pixel p, const t_tmp_pixel q);

// core/graphics/free.c
void	free_window(const t_window *window);
void	free_image(const t_image *image);
int	free_canvas(const t_canvas *canvas);
int	exit_program(t_all *args);

// core/graphics/pixels/print.c
void	pixel_print(const t_pixel p, const char *name);

// core/graphics/pixels/pixels.c
t_pixel	pixel(const t_pixel_color r, const t_pixel_color g,
		const t_pixel_color b, const t_pixel_color a);
t_pixel_color	pixel_get_a(const t_pixel pixel);
t_pixel_color	pixel_get_r(const t_pixel pixel);
t_pixel_color	pixel_get_g(const t_pixel pixel);
t_pixel_color	pixel_get_b(const t_pixel pixel);

// core/graphics/pixels/ops.c
t_pixel	pixel_add(const t_pixel p, const t_pixel q);
t_pixel	pixel_sub(const t_pixel p, const t_pixel q);
t_pixel	pixel_scal(const double q, const t_pixel p);
t_pixel	pixel_mul(const t_pixel p, const t_pixel q);

// core/graphics/inputs/inputs.c
void	input_key_camera_movements(int keysym, t_all *args);
void	input_key_close_window(int keysym, t_all *args);
int	input_key(int keysym, t_all *args);
int	input_mouse(int mousesym, int i, int j, t_all *args);

#endif
