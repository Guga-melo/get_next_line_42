/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:11:56 by gussoare          #+#    #+#             */
/*   Updated: 2022/06/14 11:23:05 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_find_line(char *backup)
{
	int		size;
	char	*str;

	size = 0;
	if (!backup[size])
		return (NULL);
	while (backup[size] && backup[size] != '\n')
		size++;
	str = malloc((size + 2) * sizeof(char));
	if (!str)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
	{
		str[size] = backup[size];
		size++;
	}
	if (backup[size] == '\n')
		str[size++] = '\n';
	str[size] = '\0';
	return (str);
}	

char	*ft_backup(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = malloc((ft_strlen(backup) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

char	*ft_read_and_backup(int fd, char *backup)
{
	char	*buff;
	int		n_bytes;

	n_bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (n_bytes && !ft_strchr(backup, '\n'))
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_bytes] = '\0';
		if (!backup)
		{
			backup = malloc(1 * sizeof(char));
			backup[0] = '\0';
		}
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = ft_read_and_backup(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = ft_find_line(backup[fd]);
	backup[fd] = ft_backup(backup[fd]);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s"\n, i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
