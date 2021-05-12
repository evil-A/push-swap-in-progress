#include <stdlib.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>

long	ft_atol(char *str);
int		ft_atoi(char *str);

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("own int      %15i\n", ft_atoi(argv[1]));
	printf("own int      %15li\n", ft_atol(argv[1]));
	printf("own int cast %15i\n", (int)ft_atol(argv[1]));
	printf("sys int      %15i\n", atoi(argv[1]));
	printf("sys int      %15llu\n", (unsigned long long)atoll(argv[1]));
//	printf("sys int cast %15i\n", (int)atoll(argv[1]));
	printf("errno %s\n", strerror(errno));
	return (0);
}

