/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:59:58 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdlib.h>
# include <mlx.h>
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_tuple	origin;
	t_tuple	extension;
}	t_image;

typedef struct s_canvas{
	t_window	window;
	t_image		image;
} t_canvas;

# include "pixels.h"

// graphics/graphics.c
t_window	*window(t_window *cvs);
t_image	*image(t_image *img, void *mlx);
t_canvas	*canvas(t_canvas *canvas);
void	put_pixel(t_image img, int x, int y, t_pixel pixel);

// graphics/free.c
void	free_window(t_window *window);
void	free_image(t_image *image);
void	free_canvas(t_canvas *canvas);

#endif
