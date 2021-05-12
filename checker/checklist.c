/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:50:07 by evila-ro          #+#    #+#             */
/*   Updated: 2021/04/21 20:17:21 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*newrdo;

	newrdo = malloc(sizeof(t_list));
	if (!(newrdo))
		return (NULL);
	newrdo->next = NULL;
	newrdo->content = (void *)content;
	return (newrdo);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		temp = *alst;
		if (!*alst)
			*alst = new;
		else
		{
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = new;
			new->next = NULL;
		}
	}
}

t_list	*f(t_list *lst, void *cnt, int (*cp)(void *cnt1, void *cnt2))
{
	while (lst)
	{
		if (!cp(cnt, lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
