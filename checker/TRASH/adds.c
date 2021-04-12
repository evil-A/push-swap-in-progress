#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	ft_isint(char *num);
int	ft_isnumeric(int c);
int	ft_atoi(const char *str);

void	fadeout()
{
	printf("Error\n");
	exit(0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(ft_isnumeric(num[i])))
		{
	//		printf("1\n");
			return (0);
		}
		i++;
	}
	if ((ft_atoi(num) < 0))
		return (0);
	return (1);
}

int	ft_isnumeric(int c)
{
	if (ft_isdigit(c) || c == '-')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;
	int	cypher;

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
	if (cypher > 19)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (number * sign);
}
