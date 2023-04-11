/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:46:48 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/11 10:37:10 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define USAGE_MESSAGE "Usage: ./miniRT [scene_file.rt]\
    .rt file can contain the following elements:\
        A 0.2 255,255,255 (ambient light)\
        C 3,3,-5 0,1,0 90 (camera)\
        L 10,10,-10 0.8 255,255,255 (light)\
        pl 0,0,0 0,1.0,0 255,0,225 (plane)\
        sp 0,1,0 0.75 200,150,100 (sphere)\
        sp 0,2,0 1 125,150,175 \
        sp 0,3,0 1.25 150,200,250 \
        sp 0,4,0 1.5 200,150,100"

void	ft_usage(void)
{
	printf(USAGE_MESSAGE);
}
