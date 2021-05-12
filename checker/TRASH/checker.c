#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_in
{
	int	sz;
	int	*a;
	int	*b;
}				t_in;

int		ft_isdigit(int c);
void	fadeout(void);
void	ft_isint(t_in *in, char *num, int pos);
int		ft_atoi(const char *str);

int		init(t_in *in, int size)
{
	in->sz = size - 1;
	in->a = malloc(sizeof(int) * in->sz);
	in->b = malloc(sizeof(int) * in->sz);
//	listas...
	return (1);
}

void	iseq(t_in *in)
{
	int	i;
	int	j;

	j = 1;
	while (j < in->sz)
	{
		i = 0;
		while (i < j)
		{
			if (in->a[i] != in->a[j])
				i++;
			else
				fadeout();
		}
		j++;
	}	
}	

void	isok(t_in *in)
{
	int	i;

	i = 0;
	while (i + 1 < in->sz)
	{
		if (in->a[i] < in->a[i + 1])
			i++;
		else
		{
			printf("KO\n");
			exit  (0);
		}
	}
	printf("OK\n");
}

int	main(int ac, char **av)
{
	t_in	in;
	int	i;
	
	if (ac < 2)
		fadeout();
	init(&in, ac);
	i = 1;
	while (i < ac)
	{
		ft_isint(&in, av[i], i - 1);
		i++;
	}
	iseq(&in);
	i = 0;
	while (i < in.sz)
	{
		in.b[i] = 0;
		printf("%d\t\t%d\n", in.a[i], in.b[i]);
		i++;
	}
//	ordenar aqui
	isok(&in);		//Comprueba orden
	return (0);
}
