/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:43:52 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/01 01:48:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_error_lst(t_list **lst, void (*del)(void*))
{
	ft_lstclear(lst, *del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**begin;
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	begin = &new;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
			return (free_error_lst(begin, *del));
		ft_lstadd_back(begin, tmp);
		lst = lst->next;
	}
	return (*begin);
}
