/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/12 12:16:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object_list	*ft_lstnew(void *ob, int id)
{
	t_object_list	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (ft_puterror(FAILED_MALLOC, (char *)__func__), NULL);
	elem->ob = ob;
	elem->id = id;
	elem->next = NULL;
	return (elem);
}

int	ft_lstsize(t_object_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

void	ft_lstadd_back(t_object_list **lst, t_object_list *new)
{
	t_object_list	*begin;

	begin = *lst;
	if (!begin)
		*lst = new;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}

void	ft_lstadd_front(t_object_list **lst, t_object_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstdelone(t_object_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->ob);
		free(lst);
	}
}
