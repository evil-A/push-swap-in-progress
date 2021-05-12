/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:55:15 by evila-ro          #+#    #+#             */
/*   Updated: 2019/12/25 23:55:30 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (c == *s)
		return ((char*)s);
	else
		return (0);
}
