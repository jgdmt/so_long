/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:36:26 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/06 20:41:59 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	ft_init_map_data(void)
{
	t_map	map_data;

	map_data.collectible = 0;
	map_data.start = 0;
	map_data.exit = 0;
	map_data.x = 0;
	map_data.exitx = 0;
	map_data.y = 0;
	map_data.exity = 0;
	map_data.height = 0;
	map_data.width = 0;
	map_data.map = 0;
	map_data.to_reset = 0;
	return (map_data);
}

t_player	ft_make_player(int x, int y)
{
	t_player	player;

	player.x = x;
	player.y = y;
	player.items = 0;
	player.moves = 0;
	return (player);
}

t_data	ft_init_data(t_map *map_data, void *mlx)
{
	t_data	game_data;

	game_data.mdata = map_data;
	game_data.mlx = mlx;
	game_data.win = 0;
	game_data.player_img = 0;
	game_data.floor_img = 0;
	game_data.wall_img = 0;
	game_data.items_img = 0;
	game_data.exit_img = 0;
	game_data.freeze = 0;
	game_data.speed = 30;
	return (game_data);
}

t_enemy	ft_init_enemy(t_data *data)
{
	int		i;
	int		j;
	t_enemy	enemy;

	i = 0;
	enemy.exist = 1;
	while (data->mdata->map[i])
	{
		j = 0;
		while (data->mdata->map[i][j])
		{
			if (data->mdata->map[i][j] == '0')
			{
				enemy.x = j;
				enemy.y = i;
				return (enemy);
			}
			j++;
		}
		i++;
	}
	enemy.exist = 0;
	return (enemy);
}

void	ft_make_img(t_data *data)
{
	int		height;
	int		width;

	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"textures/mc.xpm", &width, &height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &width, &height);
	data->items_img = mlx_xpm_file_to_image(data->mlx,
			"textures/item.xpm", &width, &height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &width, &height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy.xpm", &width, &height);
	data->anim2 = mlx_xpm_file_to_image(data->mlx,
			"textures/anim2.xpm", &width, &height);
	data->anim3 = mlx_xpm_file_to_image(data->mlx,
			"textures/anim3.xpm", &width, &height);
	if (!data->player_img || !data->floor_img || !data->items_img
		|| !data->wall_img | !data->exit_img || !data->enemy_img
		|| !data->anim2 || !data->anim3)
		ft_free_img(data, 1);
}
