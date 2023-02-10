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

#ifndef STRUCTS_MLX_H
# define STRUCTS_MLX_H

// Splitting these files into structs.h was necessary to avoid circular
// dependecies between header files...

# include "structs_geometry.h"

typedef struct s_window{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_image{
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
}	t_canvas;

#endif