/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 17:19:16 by lkrief           ###   ########.fr       */
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

	t_matrix	m;
	t_matrix	n;
	t_tuple		a;
	t_tuple		b;
	t_tuple		c;
	t_tuple		d;
	int			dim = 4;

	a = tuple(1, 2, 3, 4);
	b = tuple(-2, 1, 3, 2);
	c = tuple(-1, 0, -4, 2);
	d = tuple(3, 2, 0, -2);

	m = matrix(a, b, c, d);
	m = transpose(m);
	print_matrix(m, "M");
	printf("det M = %f\n", det(m, dim));
	print_matrix(m, "M");
	n = invert(m, dim);
	print_matrix(n, "M^-1");
	print_matrix(matrix_matrix(m, n, dim), "MM^-1");
	// print_tuple(*p_matrix_vect(m, a), "M*X");
}
