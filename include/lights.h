/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:18 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/09 16:05:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include "tuples.h"
# include "graphics.h"

typedef struct s_light{
	t_tuple		position;
	t_tmp_pixel	intensity;
}	t_light;

// lights/print.c
void	light_print_padding(const t_light *light, const char *name,
			const int padding);
void	light_print(const t_light *light, const char *name);

// lights/lights.c
t_light	light_point(const t_tuple position, const t_tmp_pixel intensity);

#endif