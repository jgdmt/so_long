/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:54 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/06 21:16:07 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_lose(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->mdata->width * 64 / 2,
		data->mdata->height * 64 / 2, 0xff0000, "LOSER");
}

void	ft_draw_enemy(t_data *data, int k, int l)
{
	static int	anim = 0;

	if (anim <= 10)
		mlx_put_image_to_window(data->mlx, data->win, data->enemy_img, k, l);
	else if (anim > 10 && anim <= 20)
		mlx_put_image_to_window(data->mlx, data->win, data->anim2, k, l);
	else if (anim > 20)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->anim3, k, l);
		if (anim > 30)
			anim = 0;
	}
	anim++;
}

static void	ft_check_meeting(t_data *data)
{
	if (data->mc->x == data->enemy->x && data->enemy->y == data->mc->y)
		data->freeze = 1;
}

static void	ft_move_enemy(t_data *dt)
{
	static int	last = 0;

	if (dt->mdata->map[dt->enemy->y][dt->enemy->x + 1] != '1' && last != 3)
	{
		dt->enemy->x += 1;
		last = 1;
	}
	else if (dt->mdata->map[dt->enemy->y + 1][dt->enemy->x] != '1' && last != 4)
	{
		dt->enemy->y += 1;
		last = 2;
	}
	else if (dt->mdata->map[dt->enemy->y][dt->enemy->x - 1] != '1' && last != 1)
	{
		dt->enemy->x -= 1;
		last = 3;
	}
	else if (dt->mdata->map[dt->enemy->y - 1][dt->enemy->x] != '1' && last != 2)
	{
		dt->enemy->y -= 1;
		last = 4;
	}
	else
		last = 0;
	ft_check_meeting(dt);
}

void	ft_enemy(t_data *data)
{
	static int	move = 0;

	if (data->freeze)
		return ;
	if (move == data->speed)
	{
		if (data->enemy)
			ft_move_enemy(data);
		move = 0;
	}
	else if (move > data->speed)
		move = 0;
	move++;
}
