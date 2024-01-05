/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:45:21 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 15:24:00 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_free_strs(char *s1, char *s2)
{
	free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static char	*ft_find_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i--] = 0;
	while (i >= 0)
	{
		line[i] = str[i];
		i--;
	}
	return (line);
}

static char	*ft_cut(char *str)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		return (ft_free_strs(str, 0));
	res = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!res)
		return (ft_free_strs(str, 0));
	j = 0;
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = 0;
	free(str);
	return (res);
}

static char	*ft_get_line(int fd, char *str)
{
	char	*buff;
	char	*temp;
	int		rd;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free_strs(str, 0));
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (ft_free_strs(str, buff));
		buff[rd] = 0;
		temp = ft_strjoin(str, buff);
		free(str);
		str = temp;
		if (!str)
			return (ft_free_strs(buff, 0));
		if (ft_strchr(str, '\n') != 0)
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (b == NULL)
		b = ft_calloc(1, sizeof(char));
	if (!b)
		return (NULL);
	b = ft_get_line(fd, b);
	if (!b)
		return (NULL);
	line = ft_find_line(b);
	if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
		free(b);
		b = 0;
		return (NULL);
	}
	b = ft_cut(b);
	return (line);
}
