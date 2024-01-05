/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:19:05 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/06 18:30:04 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_check_contains(t_map *mdata, int i, int j)
{
	while (mdata->map[j])
	{
		i = 0;
		while (mdata->map[j][i])
		{
			if (mdata->map[j][i] == 'C')
				mdata->collectible += 1;
			else if (mdata->map[j][i] == 'E')
				mdata->exit += 1;
			else if (mdata->map[j][i] == 'P')
			{
				mdata->x = i;
				mdata->y = j;
				mdata->start += 1;
			}
			else if (mdata->map[j][i] != '0' && mdata->map[j][i] != '1')
				return ("Error\nMap contains forbidden characters.\n");
			i++;
		}
		j++;
	}
	if (mdata->exit != 1 || mdata->start != 1 || mdata->collectible == 0)
		return ("Error\nMap doesn't meet requirements.\n");
	return (0);
}

static char	*ft_check_dim(t_map *mdata)
{
	int	i;
	int	j;

	mdata->width = ft_strlen(mdata->map[0]);
	i = 0;
	while (mdata->map[i])
	{
		if (ft_strlen(mdata->map[i]) != mdata->width)
			return ("Error\nMap has wrong dimensions.\n");
		j = 0;
		while (mdata->map[i][j])
		{
			if (j == 0 || j == mdata->width - 1
				|| i == 0 || i == mdata->height - 1)
				if (mdata->map[i][j] != '1')
					return ("Error\nMap is not closed.\n");
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_check_path_rec(char **copy, int x, int y)
{
	if (!copy[y] || !copy[y][x] || copy[y][x] == '1')
		return ;
	else
		copy[y][x] = '1';
	ft_check_path_rec(copy, x + 1, y);
	ft_check_path_rec(copy, x - 1, y);
	ft_check_path_rec(copy, x, y + 1);
	ft_check_path_rec(copy, x, y - 1);
}

static char	*ft_check_path(char **copy, int x, int y)
{
	int	i;
	int	j;
	int	ret;

	if (!copy)
		return ("Error\nMalloc.\n");
	ft_check_path_rec(copy, x, y);
	i = 0;
	ret = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] != '1' && copy[i][j] != '0')
				ret = 1;
			j++;
		}
		free(copy[i]);
		i++;
	}
	free(copy);
	if (ret)
		return ("Error\nAll objects are not accessible.\n");
	return (0);
}

void	ft_check_map(t_map *mdata)
{
	char	*error;

	error = ft_check_contains(mdata, 0, 0);
	ft_check_errors(mdata, error);
	error = ft_check_dim(mdata);
	ft_check_errors(mdata, error);
	error = ft_check_path(ft_map_copy(mdata), mdata->x, mdata->y);
	ft_check_errors(mdata, error);
}
