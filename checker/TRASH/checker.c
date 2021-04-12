#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(const char *str);
void	fadeout();
int	ft_isnumeric(int c);
int	ft_isint(char *num);

typedef struct	s_in
{
	int		sz;
	int		*a;
	int		*b;

}				t_in;

int		main(int argc, char **argv)
{
	t_in	in;
	int		i;
	int		num;
		
	if (argc == 1)
		return (0);
	else
		in.sz = argc - 1;
	in.a = malloc(sizeof(int) * in.sz);
	in.b = malloc(sizeof(int) * in.sz);
	i = 0;
	while (i < in.sz)
	{
		if (!(ft_isint(argv[i + 1])))
		{
//			printf("ARGV OK\n");
			fadeout();
		}
		else
		{
//			num = ft_atoi(argv[i + 1]);
//			printf("NUM: %d\n", num);
			in.a[i] = ft_atoi(argv[i + 1]);
			in.b[i] = 0;
		}
		i++;
	}

	i = 0;
	while (i < in.sz)
	{
		printf("%d\t%d\n", in.a[i], in.b[i]);
		i++;
	}

	return (0);
}
