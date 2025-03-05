/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:59:57 by dagudelo          #+#    #+#             */
/*   Updated: 2024/01/03 11:50:53 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
