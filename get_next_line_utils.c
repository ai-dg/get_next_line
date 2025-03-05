/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:11:37 by dagudelo          #+#    #+#             */
/*   Updated: 2024/01/09 15:29:00 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (!s)
		return (0);
	if (c == 0)
		return (str + ft_strlen(s));
	while (*(str + i))
	{
		if (c % 256 == *(str + i))
			return (str + i);
		i++;
	}
	return (NULL);
}

static void	ft_strjoin_while(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	ft_strjoin_while(dest, s1, s2);
	free(s1);
	return (dest);
}

// size_t x;
// 	size_t y;

// 	char *str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(sizeof(char)* 1);
// 		s1[0] = '\0';
// 	}
// 	if (!s1 ||!s2)
// 		return (NULL);
// 	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1- sizeof(char));

// 	if (str == NULL)
// 		return (NULL);

// 	x = -1;
// 	y = 0;
// 	if(s1)
// 	{
// 		while(s1[++x] != '\0')
// 			str[x] = s1[x];
// 	}
// 	while(s2[y] != '\0')
// 		str[x++] = s2[y++];

// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// char	*ft_strchr(char *s, int c)
// {
// 	int	x;

// 	x = 0;
// 	if (!s)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *)&s[ft_strlen(s)]);
// 	while (s[x] != '\0')
// 	{
// 		if (s[x] == (char)c)
// 			return ((char *)&s[x]);
// 		x++;
// 	}
// 	return (0);
// }
