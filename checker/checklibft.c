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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	letro;
	unsigned char	*string;

	string = (unsigned char *)s;
	letro = 0;
	i = 0;
	while (i < n)
	{
		string[i] = letro;
		i++;
	}
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	number;
	long	last;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		last = number;
		number = (number * 10) + (str[i++] - '0');
		if (sign == 1 && number < last)
			return (LONG_MAX);
		else if (sign == -1 && number < last)
			return (LONG_MIN);
	}
	return (number * sign);
}

int	isnum(char *num)
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
