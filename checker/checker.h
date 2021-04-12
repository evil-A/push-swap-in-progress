/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:02:05 by evila-ro          #+#    #+#             */
/*   Updated: 2021/04/07 11:12:50 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_CHECKER_H
# define _FT_CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct			s_lst
{
	int					content;
	struct s_lst		*next;
}						t_lst;

typedef struct	s_in
{
	int		sz;
	t_lst	*a;
	t_lst	*b;
}				t_in;

int		ft_isdigit(int c);
void	fadeout(void);
void	ft_isint(t_in *in, char *num, int pos);
int		ft_atoi(const char *str);
int		init(t_in *in, int size);
void	iseq(t_lst *lst);
void	ft_lst_add_back(t_lst **alst, t_lst *new);
void	ft_lstiter(t_lst *lst);
void	isok(t_lst *lst);
int	ft_atoi(const char *str);
void	save(t_in *in, char *num, int pos);

#endif
