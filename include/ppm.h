/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 00:20:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPM_H
# define PPM_H

# include <sys/stat.h>
# include "libft.h"
# include "graphics.h"
# include "error_handler.h"

# define SCREENSHOT() get_ppm(cvs.image)

// ppm/ppm.c
int		open_ppm(char *file);
void	ppm_header(int fd);
void	ppm_data(int fd, t_image image);
void	close_ppm(int fd);
void	get_ppm(t_image image);

#endif
