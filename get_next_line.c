/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:11:56 by gussoare          #+#    #+#             */
/*   Updated: 2022/06/03 14:25:53 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *str;
	int size; 

	if (fd <=0 || BUFFER_SIZE <= 0)
		return (0);
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	size = read(fd, str, BUFFER_SIZE);
	return (str);
}

#include <stdio.h>

int main()
{
	int	fd;
	char *buf;

	fd = open("teste.txt", O_RDONLY);
	buf = get_next_line(fd);
	close (fd);
	printf("%s", buf);
	return (0);
}
