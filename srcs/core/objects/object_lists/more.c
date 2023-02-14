/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:21 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 00:47:32 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	ft_lstclear(t_object_list **lst, void (*del)(void*))
{
	t_object_list	*begin;
	t_object_list	*before;

	if (lst && *lst && del)
	{
		begin = *lst;
		while (begin)
		{
			before = begin;
			begin = begin->next;
			ft_lstdelone(before, *del);
		}
		*lst = NULL;
	}
}

void	ft_lstiter(t_object_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->ob);
		lst = lst->next;
	}
}

t_object_list	*ft_lstlast(t_object_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstprint(t_object_list *lst)
{
	if (lst == NULL)
		printf("(null)");
	while (lst)
	{
		printf("%d", lst->id);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf("\n");
}
