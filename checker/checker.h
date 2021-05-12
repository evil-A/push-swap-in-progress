/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:02:05 by evila-ro          #+#    #+#             */
/*   Updated: 2021/04/21 21:56:14 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_CHECKER_H
# define _FT_CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>

typedef struct	s_list
{
	void		 	*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_data
{
	size_t	a_size;
	size_t	b_size;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_o;
}				t_data;

void	ft_bzero(void *s, size_t n);
int isnum(char *num);
int add_number(t_list **alst, long nb);
t_list	*f(t_list *lst, void *cnt, int (*cp)(void *cnt1, void *cnt2));
int	long_cmp(void *content1, void *content2);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstiter(t_list *lst, void (*f)(void *));
long	ft_atol(const char *str);
void	print_number(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstsort(t_list **alst, int (*cmp)());

#endif
