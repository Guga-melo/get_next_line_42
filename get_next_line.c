/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:11:56 by gussoare          #+#    #+#             */
/*   Updated: 2022/05/31 13:54:47 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{

}


#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd;
	char buf[57];

	fd = open("teste.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("erro para abrir e ler o arquivo");
		return (0);
	}
	read(fd, buf, 57);
	buf[56] = 0;

	close (fd);

	printf("%s", buf);
	return (0);
}
