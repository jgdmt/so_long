/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:04:38 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 19:55:31 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_data *data, char c, int k, int l)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player_img, k, l);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->items_img, k, l);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img, k, l);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img, k, l);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img, k, l);
}

int	ft_render_next_frame(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->mdata->map[i])
	{
		j = 0;
		while (data->mdata->map[i][j])
		{
			ft_draw(data, data->mdata->map[i][j], j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_play(t_data *gdata, t_player *player)
{
	gdata->mc = player;
	mlx_hook(gdata->win, 17, 0, ft_exit, gdata);
	mlx_key_hook(gdata->win, keypress, gdata);
	mlx_loop(gdata->mlx);
}
