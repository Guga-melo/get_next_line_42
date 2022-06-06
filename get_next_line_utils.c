/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:13:00 by gussoare          #+#    #+#             */
/*   Updated: 2022/06/06 12:56:12 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	found;
	int		i;

	str = (char *) s;
	found = (char) c;
	i = 0;
	while (*str != found)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (0);
	result = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		result[i + j] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
