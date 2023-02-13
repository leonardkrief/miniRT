/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/13 14:13:11 by lkrief           ###   ########.fr       */
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
# define WINDOW_HEIGHT			500
# define WINDOW_WIDTH			800
# if __APPLE__
typedef enum	e_input
{
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 124,
	KEY_RIGHT = 123,
	KEY_Z = 13,
	KEY_S = 1,
	KEY_Q = 0,
	KEY_D = 2,
	KEY_W = 6,
	KEY_X = 7,
	KEY_SLASH = 47,
	KEY_PLUS = 44,
	MOUSE_ZOOM_IN = 5,
	MOUSE_ZOOM_OUT = 4,
	CLOSE_WINDOW_BUTTON_EVENT = 17,
}	t_input;
# elif __linux__
typedef enum	e_input
{
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_Z = -1,
	KEY_S = -1,
	KEY_Q = -1,
	KEY_D = -1,
	KEY_W = -1,
	KEY_X = -1,
	KEY_SLASH = -1,
	KEY_PLUS = -1,
	MOUSE_ZOOM_IN = -1,
	MOUSE_ZOOM_OUT = -1,
	CLOSE_WINDOW_BUTTON_EVENT = 17,
}	t_input;
# endif

# define TMP_PIXEL_BLACK	0, 0, 0
# define TMP_PIXEL_WHITE	1, 1, 1
# define PIXEL_BLACK		0, 0, 0
# define PIXEL_WHITE		255, 255, 255

// core/graphics/display.c
void	all(t_all *args, t_canvas *cvs, t_camera *c, t_world *w);
void	display_loop(t_all *args);
void	render(const t_canvas *cvs, const t_camera *c, const t_world *w);

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
// devra prendre plus qu'un canvas plus tard mais ok pour l'instant
int	exit_program(t_all *args);

// core/graphics/mlx_basics.c
t_window	*window(t_window *window);
t_image	*image(t_image *image, void *mlx);
t_canvas	*canvas(t_canvas *canvas);
void	put_pixel(t_image *img, int x, int y, t_pixel pixel);

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

// core/graphics/camera.c
t_camera	camera(double camera_width, double camera_height, double fov);
void	pixel_size(t_camera *c);
void	view_transform(t_camera *c, t_tuple from, t_tuple to, t_tuple up);
t_ray	ray_for_pixel(const t_camera *c, const int i, const int j);
void	camera_transform(t_camera *c, const t_matrix transform);

// core/graphics/inputs/inputs.c
void	input_key_camera_movements(t_input keysym, t_all *args);
void	input_key_close_window(t_input keysym, t_all *args);
int	input_key(t_input keysym, t_all *args);
int	input_mouse(t_input mousesym, int i, int j, t_all *args);

#endif
