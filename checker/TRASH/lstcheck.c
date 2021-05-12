#include "checker.h"

int	main(int ac, char **av)
{
	t_in	in;
	t_lst	a;
	t_lst	b;
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
	iseq(in.a);
	i = 0;
//	ordenar aqui
	ft_lstiter(in.a);
	isok(in.a);		//Comprueba orden
	return (0);
}
