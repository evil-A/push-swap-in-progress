#include "checker.h"

void	fadeout(void)
{
	printf("Error\n");
	exit (0);
}

t_lst	*ft_lstnew(int num)
{
	t_lst	*newrdo;

	if (!(newrdo = malloc(sizeof(t_lst))))
		return (NULL);
	newrdo->next = NULL;
	newrdo->content = num;//(void*)content;
	return (newrdo);
}

void	ft_lst_add_back(t_lst **alst, t_lst *new)
{
	t_lst	*temp;

	if (alst)
	{
		temp = *alst;
		if (!*alst)
			*alst = new;
		else
		{
			while (temp->next != 0)
				temp = temp->next;
			temp->next = new;
			new->next = 0;
		}
	}
}

void	ft_lstiter(t_lst *lst)
{
	t_lst *temp;

	if (!lst)
	   return ;
	temp = lst;
	while (temp)
	{
		printf("%d\t\n", temp->content);//lista a y b
		temp = temp->next;
	}
}

int		init(t_in *in, int size)
{
	bzero(in, sizeof(t_in));
	in->sz = size - 1;
	return (1);
}

void	save(t_in *in, char *num, int pos)
{
	ft_lst_add_back(&in->a, ft_lstnew((int)ft_atoi(num)));
}

void	iseq(t_lst *lst)
{
	t_lst	*temp;
	t_lst	*tmp2;
	if (!lst)
		return ;
	temp = lst;
	tmp2 = lst->next;
	while (temp && tmp2)
	{
		while (temp && tmp2)
		{
			if (temp->content != tmp2->content)
				tmp2 = tmp2->next;
			else
				fadeout();
		}
		temp = temp->next;
		tmp2 = temp->next;
	}
}

void	isok(t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
		{
			printf("KO\n");
			exit (0);
		}
	}
	printf("OK\n");
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_isint(t_in *in, char *num, int pos)
{
	int	i;
	int	ret;

	i = 0;
	if (num[i] == '-' && num[i] == '+')
		i++;
	while (num[i] != '\0')
		i++;
	if (ft_isdigit(num[i - 1]))
		ft_atoi(num);
	else
		fadeout();
	save(in, num, pos);
	//in->a[pos] = ft_atoi(num);
}


int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;
	int		cypher;

	i = 0;
	sign = 1;
	number = 0;
	cypher = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && cypher++ != -2)
	{
		number = (number * 10) + (str[i++] - 48);
	}
	el resultado debe ser mayor al anterior. cualquier numero multiplciado por 10, es mayor al anterior


	if (number * sign > 2147483647 || number * sign < -2147483648)
		fadeout();
	return (number * sign);
}

 void	swapa(t_lst *lst)
{
	int tmp;

	if (!lst || !lst->next)
		return ;
	tmp = lst->next->content;
	lst->next->content = lst->content;
	lst->content = tmp;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	letro;
	unsigned char	*string;

	string = (unsigned char*)s;
	letro = 0;
	i = 0;
	while (i < n)
	{
		string[i] = letro;
		i++;
	}
}
