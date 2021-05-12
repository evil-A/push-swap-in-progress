#include "checker.h"


void	print_number(void *content)
{
	long	*nb;

	nb = content;
	printf("%li\n", *nb);
}

int	long_cmp(void *content1, void *content2)
{
	long	*nb1;
	long	*nb2;

	nb1 = content1;
	nb2 = content2;
	if (*nb1 < *nb2)
		return (1);
	else if (*nb1 > *nb2)
		return (-1);
	return (0);
}

int	add_number(t_list **alst, long nb)
{
	long	*nbp;

	if (nb > INT_MAX || nb < INT_MIN)
		return (2);
	nbp = malloc(sizeof(long));
	*nbp = nb;
	if (!f(*alst, nbp, long_cmp))
	{
		ft_lstadd_back(alst, ft_lstnew(nbp));
		return (0);
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

void	init(int argc, char **argv, t_data *data)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
	while (i < argc && !res)
	{
		res = isnum(argv[i]);
		if (!res)
			res = add_number(&data->stack_a, ft_atol(argv[i]));
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
//		ft_lstiter(data->stack_a, print_number);
		if (ft_lst_sorted(data->stack_a, long_cmp))
			printf("La lista ya está ordenada\n");
	}
}
/* NO BORRAR //el int! 
void	swapa(t_list *lst)
{
	int tmp;

	if (!lst || !lst->next)
		return ;
	tmp = (int)lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp;
}
*/
void	swap(t_list *lst)
{
	int *tmp;

	if (!lst || !lst->next)
		return ;
	tmp = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp;
}

void	ft_lstsort(t_list **alst, int (*cmp)())
{
	t_list	*last;
	t_list	*current;
	void	*temp;

	last = NULL;
	while (*alst && (last == NULL || temp != NULL))
	{
		temp = NULL;
		current = *alst;
		while (current->next != last)
		{
			if (cmp(current->content, current->next->content) < 0)
			{
				temp = current->content;
				current->content = current->next->content;
				current->next->content = temp;
			}
			current = current->next;
		}
		last = current;
	}
}
void	ft_lstcp(t_list *a, t_list **o)
{
	if (!a)
		return;
	while (a)
	{
		ft_lstadd_back(o, ft_lstnew(a->content));
		a = a->next;
	}
}

void	push(t_list **src, t_list **dst)
{
	t_list	*node;

	if (!*src)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = NULL;
	ft_lstadd_front(dst, node);
}

void	rotate(t_list **lst)//the first element becomes the last
{
	t_list	*node;

	if (!*lst)
		return ;
	node = *lst;
	*lst = (*lst)->next;
	node->next = NULL;
	ft_lstadd_back(lst, node);
}

void	reverse(t_list **lst)//the last element becomes the first
{
	t_list	*node;
	t_list	*aux;

	if (!*lst)
		return ;
	node = *lst;
	while (node->next->next != 0)
	{
		node = node->next;
	}
	aux = node;
	ft_lstadd_front(lst, node->next);
	aux->next = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	long	*num;

	num = malloc(sizeof(long));

	*num = 333;
	
	bzero(&data, sizeof(t_data));
	if (argc == 1)
		return (1);
	else
		init(argc, argv, &data);

//	ft_lstcp(data.stack_a, &data.stack_o);
//	ft_lstsort(&data.stack_o, long_cmp);
//	swap(data.stack_a);
/*
	push(&data.stack_a, &data.stack_b);
//	ft_lstadd_back(&data.stack_b, ft_lstnew(num));
*/

//	printf("A --------------\n");
//	ft_lstiter(data.stack_a, print_number);
//	printf("Rotate A -------\n");
//	rotate(&data.stack_a);
//	ft_lstiter(data.stack_a, print_number);
	printf("A --------------\n");
	ft_lstiter(data.stack_a, print_number);
	printf("Rotate A -------\n");
	reverse(&data.stack_a);
	ft_lstiter(data.stack_a, print_number);

	return (0);
}
