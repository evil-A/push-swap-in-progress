#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

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

void	print_number(void *content)
{
	long	*nb;

	nb = content;
	printf("%li\n", *nb);
}


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

	if (!(newrdo = malloc(sizeof(t_list))))
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
			new->next = 0;
		}
	}
}

int	long_cmp(void *content1, void *content2)
{
	long	*nb1;
	long	*nb2;

	nb1 = content1;
	nb2 = content2;
	if (*nb1 < *nb2)
		return (1);
	else if (*nb1 == *nb2)
		return (0);
	return (-1);
}

t_list	*ft_lstfind(t_list *lst, void *content, int (*cmp)(void *content1, void *content2))//////////
{
	while (lst)
	{
		if (!cmp(content, lst->content))
			return (lst);//node
		lst = lst->next;
	}
	return (NULL);
}

int add_number(t_list **alst, long nb)//**alst
{
	long	*nbp;//nbp vs nb

	if (nb > INT_MAX || nb < INT_MIN)
		return (2);
	nbp = malloc(sizeof(long));
	*nbp = nb;
	if (!ft_lstfind(*alst, nbp, long_cmp))//long cmp
	{
		ft_lstadd_back(alst, ft_lstnew(nbp));
		return (0);//return isnum / is_sorted
	}
	return (1);
}

int	ft_lst_sorted(t_list *lst, int (*cmp)(void *content1, void *content2))
{
	while (lst && lst->next)
	{
		if (cmp(lst->content, lst->next->content) == -1)
			return (0);
		lst = lst->next;
	}
	return (4);
}

int isnum(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
	if (*num == '\0')
		return (3);
	while (*num >= '0' && *num <= '9')
		num++;
	if (*num != '\0')
		return (3);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		res;

	i = 1;
	res = 0;
	bzero(&data, sizeof(t_data));
	if (argc == 1)
		return (1);
	while (i < argc && !res)
	{
		res = isnum(argv[i]);
		if (!res)
			res = add_number(&data.stack_a, atol(argv[i]));
		i++;
	}
	if (res == 1)
		printf("Numero duplicado\n");
	else if (res == 2)
		printf("Numero fuera de limite.\n");
	else if (res == 3)
		printf("No es un numero\n");
	else
	{
		ft_lstiter(data.stack_a, print_number);
		if (ft_lst_sorted(data.stack_a, long_cmp))
			printf("La lista ya está ordenada\n");
	}
	return (0);
}

