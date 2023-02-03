/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 08:08:59 by lkrief           ###   ########.fr       */
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
	t_tuple		a;
	t_tuple		b;
	t_tuple		c;
	t_tuple		d;

	a = tuple(1, 10, 3, 2);
	b = tuple(0, 10, 3, 0);
	c = tuple(7, 8, 21, 14);
	d = tuple(-1, 0, -3, -2);
	m = matrix(a, b, c, d);
	m = transpose(m);
	print_matrix(m, "M");
	printf("det (M) = %f\n", det(m, 4));
	printf("det (M) = %f, det (M) = %f, det (M) = %f, det (M) = %f\n",
		det(submatrix(m, 0, 0), 3), det(submatrix(m, 0, 1), 3),
		det(submatrix(m, 0, 2), 3), det(submatrix(m, 0, 3), 3));
	// print_tuple(*p_matrix_vect(m, a), "M*X");
}
