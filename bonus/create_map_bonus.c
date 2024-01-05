/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:47:03 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 15:22:05 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_count_lines(int fd)
{
	int		size;
	char	*str;

	size = 0;
	str = get_next_line(fd);
	if (str && ft_strlen(str) <= 2)
		return (free(str), -1);
	while (str)
	{
		size++;
		free(str);
		str = get_next_line(fd);
	}
	if (size <= 2)
		return (-1);
	return (size);
}

static char	**ft_make_board(int fd, int size)
{
	char	*line;
	char	**board;
	int		i;

	board = malloc((size + 1) * sizeof(char *));
	if (!board)
		return (0);
	i = 0;
	while (i < size)
	{
		line = get_next_line(fd);
		if (!line)
			ft_free_board(board, i, 1);
		board[i++] = line;
	}
	board[i] = 0;
	return (board);
}

char	**ft_create_map(char *file_name, t_map *mdata)
{
	int		fd;
	char	**map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (-1);
	}
	mdata->height = ft_count_lines(fd);
	close(fd);
	if (mdata->height < 0)
		ft_check_errors(mdata, "Error\nMap has wrong dimensions.\n");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (-1);
	}
	map = ft_make_board(fd, mdata->height);
	if (!map)
		ft_check_errors(mdata, "Error\nMalloc.\n");
	mdata->map = map;
	ft_check_map(mdata);
	return (map);
}
