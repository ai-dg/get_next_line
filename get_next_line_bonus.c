/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:59:50 by dagudelo          #+#    #+#             */
/*   Updated: 2024/01/10 12:21:01 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// char	*ft_line(char *tmp);
// char	*ft_tmp(char *tmp);
// char	*ft_read(int fd, char *tmp);
// char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static char	*tmp[257];
	char		*str;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd >= 256)
		return (NULL);
	tmp[fd] = ft_read(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	str = ft_line(tmp[fd]);
	tmp[fd] = ft_tmp(tmp[fd]);
	return (str);
}

char	*ft_read(int fd, char *tmp)
{
	char	*buffer;
	int		read_nbr;

	read_nbr = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		free(tmp);
		return (NULL);
	}
	while (!ft_strchr(tmp, '\n') && read_nbr != 0)
	{
		read_nbr = read(fd, buffer, BUFFER_SIZE);
		if (read_nbr == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_nbr] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*ft_line(char *tmp)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	if (!tmp || !*tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = tmp[j];
		j++;
	}
	if (tmp[i] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*ft_tmp(char *tmp)
{
	int		len;
	char	*str;
	int		x;
	int		y;

	len = 0;
	if (!tmp)
		return (NULL);
	while (tmp[len] && tmp[len] != '\n')
		len++;
	if (!tmp[len])
	{
		free(tmp);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - len));
	if (!str)
		return (NULL);
	x = len + 1;
	y = 0;
	while (tmp[x])
		str[y++] = tmp[x++];
	str[y] = '\0';
	free(tmp);
	return (str);
}

// int main(void)
// {
//     int fd1, fd2;
//     char *line1, *line2;

//     fd1 = open("test1.txt", O_RDONLY);
//     if (fd1 == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier1");
//         return (1);
//     }

//     fd2 = open("test2.txt", O_RDONLY);
//     if (fd2 == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier2");
//         close(fd1);
//         return (1);
//     }
//     printf("Lecture du test1:\n");
//     line1 = get_next_line(fd1);
//     while (line1 != NULL)
//     {
//         printf("%s", line1);
//         free(line1);
//         line1 = get_next_line(fd1);
//     }

//     printf("\nLecture du test2:\n");
//     line2 = get_next_line(fd2);
//     while (line2 != NULL)
//     {
//         printf("%s", line2);
//         free(line2);
//         line2 = get_next_line(fd2);
//     }

//     close(fd1);
//     close(fd2);
//     return (0);
// }