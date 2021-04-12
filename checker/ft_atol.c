#include <stdio.h>
#include <limits.h>

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
