/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:06:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 00:13:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_LISTS_H
# define OBJECTS_LISTS_H

# include <stdio.h>
# include "libft.h"
# include "objects.h"
# include "structs_all.h"
# include "error_handler.h"

// lists/basics.c
t_object_list	*ft_lstnew(void *ob, int id);
int	ft_lstsize(t_object_list *lst);
void	ft_lstadd_back(t_object_list **lst, t_object_list *new);
void	ft_lstadd_front(t_object_list **lst, t_object_list *new);
void	ft_lstdelone(t_object_list *lst, void (*del)(void*));

// lists/more.c
void	ft_lstclear(t_object_list **lst, void (*del)(void*));
void	ft_lstiter(t_object_list *lst, void (*f)(void *));
t_object_list	*ft_lstlast(t_object_list *lst);
void	ft_lstprint(t_object_list *lst);

#endif