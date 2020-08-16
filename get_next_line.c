/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:37:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2019/12/09 20:09:27 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_it(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	separate_lines(char **line, char **str, int fd)
{
	int		i;
	char	*rest;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	if (!(*line = ft_substr(str[fd], 0, i)))
	{
		free_it(&str[fd]);
		return (-1);
	}
	if (str[fd][i])
	{
		if (!(rest = ft_substr(str[fd], i + 1, ft_strlen(str[fd]) - (i + 1))))
		{
			free_it(&str[fd]);
			return (-1);
		}
		free_it(&str[fd]);
		str[fd] = rest;
		return (1);
	}
	free_it(&str[fd]);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0
		|| read(fd, buf, 0) < 0)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = (char*)ft_memalloc(sizeof(char) * 1)))
			return (-1);
	while (!ft_strchr(str[fd], '\n') && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buf)))
		{
			free_it(&str[fd]);
			return (-1);
		}
		free_it(&str[fd]);
		str[fd] = tmp;
	}
	return (separate_lines(line, str, fd));
}
