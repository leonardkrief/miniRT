/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/07 02:52:38 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPM_H
# define PPM_H

# include <sys/stat.h>
# include "graphics.h"

# define SCREENSHOT(image) get_ppm(image)

// ppm/ppm.c
int		open_ppm(char *file);
void	ppm_header(int fd);
void	ppm_data(int fd, t_image image);
void	close_ppm(int fd);
void	get_ppm(t_image image);

#endif
