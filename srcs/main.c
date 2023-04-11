/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:23:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/11 10:36:37 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <time.h>

#define USAGE_MESSAGE "Usage: ./miniRT [scene_file.rt]\n\n\
  .rt file can contain the following elements:\n\
    ambient_light  A 0.2 255,255,255\n\
    camera         C 3,3,-5 0,1,0 90\n\
    light          L 10,10,-10 0.8 255,255,255\n\
    sphere         sp 0,1,0 0.75 200,150,100\n\
    plane          pl 0,0,0 0,1.0,0 255,0,225\n\
    cylinder       cy 0,0,0 1,0,0 2 5 255,255,255\n"

void	ft_usage(void)
{
	printf(USAGE_MESSAGE);
}

int	main(int ac, char **av)
{
	t_world		w;
	t_camera	c;
	t_canvas	cvs;
	t_all		args;

	ft_memset(&w, 0, sizeof(t_world));
	ft_memset(&c, 0, sizeof(t_camera));
	if (ac != 2)
		return (ft_usage(), -1);
	if (parsing(av[1], &w, &c) == -1)
		return (-1);
	if (canvas(&cvs) == NULL)
	{
		free_world(&w);
		return (-1);
	}
	all(&args, &cvs, &c, &w);
	display_loop(&args);
}
