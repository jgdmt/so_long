/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:56:22 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 20:10:21 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
	ft_render_next_frame(data);
}

int	keypress(int key, t_data *vars)
{
	if (key == ESC)
	{
		ft_exit(vars);
		exit (0);
	}
	else if (key == A || key == LARROW)
		move(LEFT, 0, vars);
	else if (key == D || key == RARROW)
		move(RIGHT, 0, vars);
	else if (key == W || key == UARROW)
		move(UP, 1, vars);
	else if (key == S || key == DARROW)
		move(DOWN, 1, vars);
	return (1);
}
