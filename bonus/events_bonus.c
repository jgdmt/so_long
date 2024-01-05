/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:56:22 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/07 19:02:11 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "keys.h"

int	ft_exit(t_data *data)
{
	ft_free_all(data, 0);
	exit(0);
}

static void	ft_actions(t_data *data)
{
	int	x;
	int	y;
	int	ex;
	int	ey;

	x = data->mc->x;
	y = data->mc->y;
	ex = data->mdata->exitx;
	ey = data->mdata->exity;
	if (data->enemy && x == data->enemy->x && y == data->enemy->y)
		data->freeze = 1;
	if (data->mdata->map[y][x] == 'C')
		data->mc->items += 1;
	if (x == ex && y == ey)
	{
		if (data->mc->items == data->mdata->collectible)
			ft_exit(data);
		data->mdata->to_reset = 1;
	}
	else if ((x != ex || y != ey) && data->mdata->to_reset)
	{
		data->mdata->map[ey][ex] = 'E';
		data->mdata->to_reset = 0;
	}
	data->mdata->map[y][x] = 'P';
}

static void	move(int key, int dir, t_data *data)
{
	if (dir == 0)
	{
		if (data->mdata->map[data->mc->y][data->mc->x + key] != '1')
		{
			data->mdata->map[data->mc->y][data->mc->x] = '0';
			data->mc->x += key;
			data->mc->moves += 1;
			ft_printf("%i\n", data->mc->moves);
		}
	}
	else
	{
		if (data->mdata->map[data->mc->y + key][data->mc->x] != '1')
		{
			data->mdata->map[data->mc->y][data->mc->x] = '0';
			data->mc->y += key;
			data->mc->moves += 1;
			ft_printf("%i\n", data->mc->moves);
		}
	}
	ft_actions(data);
}

int	keypress(int key, t_data *vars)
{
	if (key == ESC)
	{
		ft_exit(vars);
		exit (0);
	}
	if (vars->freeze)
		return (0);
	else if (key == A)
		move(LEFT, 0, vars);
	else if (key == D)
		move(RIGHT, 0, vars);
	else if (key == W)
		move(UP, 1, vars);
	else if (key == S)
		move(DOWN, 1, vars);
	else
		if (vars->speed > 1)
			vars->speed--;
	return (0);
}
