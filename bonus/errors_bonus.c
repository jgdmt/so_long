/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:04:39 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/04 15:08:11 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_write_str(int output, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(output, &str[i++], 1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_name(char *file_name)
{
	if (ft_strlen(file_name) < 4)
	{
		ft_write_str(2, "Error\nNot a valid file name\n");
		exit(-1);
	}
	if (ft_strcmp(&file_name[ft_strlen(file_name) - 4], ".ber"))
	{
		ft_write_str(2, "Error\nNot a valid file extension\n");
		exit(-1);
	}
}

void	ft_check_errors(t_map *mdata, char *err)
{
	if (!err)
		return ;
	ft_write_str(2, err);
	ft_free_board(mdata->map, mdata->height, 1);
	exit (-1);
}
