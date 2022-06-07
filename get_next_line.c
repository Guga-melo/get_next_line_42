/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:11:56 by gussoare          #+#    #+#             */
/*   Updated: 2022/06/07 10:53:44 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(char *backup)
{
	int		count;
	char	*str;

	count = 0;
	if (!backup[count])
		return (NULL);
	while (backup[count] && backup[count] != '\n')
		count++;
	str = malloc((count + 2) * sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (backup[count] && backup[count] != '\n')
	{
		str[count] = backup[count];
		count++;
	}
	if (backup[count] == '\n')
	{
		str[count] = backup[count];
		count++;
	}
	str[count] = 0;
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
	str[j] = 0;
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
	while (n_bytes != 0 && !ft_strchr(backup, '\n'))
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_bytes] = 0;
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read_and_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_find_line(backup);
	backup = ft_backup(backup);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*buf;
	char	*buf2;
	int		fd;

	fd = open("teste.txt", O_RDONLY);
	
	buf = get_next_line(fd);
	buf2 = get_next_line(fd);
	close(fd);
	printf("%s", buf);
	printf("%s", buf2);
	return (0);
}
