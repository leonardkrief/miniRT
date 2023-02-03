/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 17:58:54 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	// t_canvas	cvs;
	// 
	// canvas(&cvs);
	// int	i = -1;
	// while (++i <= WIDTH)
	// {
	// 	int	j = -1;
	// 	while (++j <= HEIGHT)
	// 		put_pixel(cvs.image, i, j, pixel(255, 0, 255, 0));
	// }
	// mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	// get_ppm(cvs.image);
	// get_ppm(cvs.image);
	// mlx_loop(cvs.window.mlx);

	t_tuple		a;
	t_tuple		b;
	t_tuple		c;
	t_tuple		d;
	int			dim = 4;

	(void)a;
	(void)b;
	(void)c;
	(void)d;
	a = tuple(8, -5, 9, 2);
	b = tuple(7, 5, 6, 1);
	c = tuple(-6, 0, 9, 6);
	d = tuple(-3, 0, -9, -4);

	t_matrix t;
	t = translation(1, 2, 3);
	print_matrix(t, "trans");
	print_matrix(invert(t, 4), "t^-1");
	print_matrix(matrix_matrix(t, invert(t, dim), dim), "tt^-1");
	print_tuple(matrix_vect(t, point(5, 4, 3)), "vect");
	print_tuple(matrix_vect(invert(t, 4), point(5, 4, 3)), "vect");
	// print_tuple(*p_matrix_vect(m, a), "M*X");
}
