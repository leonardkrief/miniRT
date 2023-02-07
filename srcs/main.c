/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 13:55:39 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(void)
{
	//************************LIGHTING**********************//
	
	printf("\n********************TEST 1**********************\n");
	t_material	m = material();
	t_tuple		position = point(0, 0, 0);
	t_tuple		eyev = vector(0, 0, -1);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(point(0, 0, -10), tmp_pixel(TMP_PIXEL_WHITE, 0));
	t_tmp_pixel	result = lighting(m, light, position, eyev, normalv);
	t_tmp_pixel	exp = tmp_pixel(1.9, 1.9, 1.9, 0);
	tmp_pixel_print(result, "p1:   ");
	tmp_pixel_print(exp, "exp1: ");

	printf("\n********************TEST 2**********************\n");
	m = material();
	position = point(0, 0, 0);
	eyev = vector(0, sqrt(2)/2, -sqrt(2)/2);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 0, -10), tmp_pixel(TMP_PIXEL_WHITE, 0));
	result = lighting(m, light, position, eyev, normalv);
	exp = tmp_pixel(1, 1, 1, 0);
	tmp_pixel_print(result, "p2:   ");
	tmp_pixel_print(exp, "exp1: ");

	printf("\n********************TEST 3**********************\n");
	m = material();
	position = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 10, -10), tmp_pixel(TMP_PIXEL_WHITE, 0));
	result = lighting(m, light, position, eyev, normalv);
	exp = tmp_pixel(0.7364, 0.7364, 0.7364, 0);
	tmp_pixel_print(result, "p3:   ");
	tmp_pixel_print(exp, "exp1: ");

	printf("\n********************TEST 4**********************\n");
	m = material();
	position = point(0, 0, 0);
	eyev = vector(0, -sqrt(2)/2, -sqrt(2)/2);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 10, -10), tmp_pixel(TMP_PIXEL_WHITE, 0));
	result = lighting(m, light, position, eyev, normalv);
	exp = tmp_pixel(1.6364, 1.6364, 1.6364, 0);
	tmp_pixel_print(result, "p4:   ");
	tmp_pixel_print(exp, "exp1: ");

	printf("\n********************TEST 5**********************\n");
	m = material();
	position = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 0, 10), tmp_pixel(TMP_PIXEL_WHITE, 0));
	result = lighting(m, light, position, eyev, normalv);
	exp = tmp_pixel(0.1, 0.1, 0.1, 0);
	tmp_pixel_print(result, "p5:   ");
	tmp_pixel_print(exp, "exp1: ");
}