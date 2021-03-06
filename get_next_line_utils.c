/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:40:43 by jamrabhi          #+#    #+#             */
/*   Updated: 2019/11/22 01:30:09 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (NULL);
	while (i < size)
	{
		((char*)mem)[i] = 0;
		i++;
	}
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	str_len;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	str_len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(str = (char *)malloc(sizeof(*str) * (str_len + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == '\0' && ch == '\0')
		return ((char*)s + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rt;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (!(rt = (char *)malloc(sizeof(*rt) * (len + 1))))
		return (NULL);
	while (*s + start && i < len)
	{
		rt[i] = s[start];
		i++;
		start++;
	}
	rt[i] = '\0';
	return (rt);
}
