#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include "gnl/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int				i;
	unsigned char	*string;

	string = (unsigned char *)s;
	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (c == *s)
		return ((char*)s);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	if (!(copy = (char*)malloc(len + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (&copy[0]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chain;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (!(chain = (char*)malloc(len)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		chain[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		chain[i + j] = s2[j];
		j++;
	}
	chain[i + j] = '\0';
	return (chain);
}

int main(void)
{
	int	r;
	char	*buf;

	while (get_next_line(0, &buf))
	{
		if (strcmp(buf, "pa") == 0)
			printf("push a\n");
		else if (strcmp(buf, "pb") == 0)
			printf("push b\n");
		else if (strcmp(buf, "sa") == 0)
			printf("swap a\n");
		else if (strcmp(buf, "sb") == 0)
			printf("swap b\n");
		else if (strcmp(buf, "ss") == 0)
			printf("swap double\n");
		else if (strcmp(buf, "ra") == 0)
			printf("reverse a\n");
		else if (strcmp(buf, "rb") == 0)
			printf("reverse b\n");
		else if (strcmp(buf, "rr") == 0)
			printf("reverse double\n");
		else if (strcmp(buf, "rra") == 0)
			printf("rotate a\n");
		else if (strcmp(buf, "rrb") == 0)
			printf("rotate b\n");
		else if (strcmp(buf, "rrr") == 0)
			printf("rotate double\n");
		else if (strlen(buf) > 0)
			printf("Instrucción de mierda\n");
	}
	printf("Fin de programa\n");
	return (0);
}

/*
int main(void)
{
	int	r;
	char	buf[4];
	_Bool fin;

	fin = 0;
	while (!fin)
	{
		r = read(0, buf, 4);
		buf[r - 1] = '\0';
		if (r == 0)
			fin = !fin;
		else if (strcmp(buf, "pa") == 0)
			printf("push a\n");
		else if (strcmp(buf, "pb") == 0)
			printf("push b\n");
		else if (strlen(buf) > 0)
			printf("Instrucción de mierda\n");
	}
	printf("Fin de programa\n");
	return (0);
}
*/
