/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:23:13 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 12:38:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPM_H
# define PPM_H

# include <sys/stat.h>
# include "libft.h"
# include "graphics.h"
# include "error_handler.h"

# define SCREENSHOT() get_ppm(cvs.image)

// utils/ppm/ppm.c
int		open_ppm(char *file);
void	ppm_header(const int fd);
void	ppm_data(const int fd, const t_image i);
void	close_ppm(const int fd);
void	get_ppm(const t_image image);

#endif
