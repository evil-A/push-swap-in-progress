#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_in
{
	int	sz;
	int	*a;
	int	*b;
}				t_in;

int	ft_atoi(const char *str);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
void	fadeout(void)
{
	printf("Error\n");
	exit (0);
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
	in->a[pos] = ft_atoi(num);
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
		number = (number * 10) + (str[i++] - 48);
	if (number * sign > 2147483647 || number * sign < -2147483648)
		fadeout();
	return (number * sign);
}
