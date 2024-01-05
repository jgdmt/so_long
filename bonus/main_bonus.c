/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:19:13 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/06 18:48:22 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_free_triple(void *init, void *wind, char **map)
{
	int	i;

	i = 0;
	if (wind)
		mlx_destroy_window(init, wind);
	if (init)
		free(init);
	while (map && map[i])
		free(map[i++]);
	free(map);
	exit (-1);
}

static void	ft_find_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->mdata->map[y])
	{
		x = 0;
		while (data->mdata->map[y][x])
		{
			if (data->mdata->map[y][x] == 'E')
			{
				data->mdata->exitx = x;
				data->mdata->exity = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	ft_init_game(t_data *gdata)
{
	void		*mlx_win;
	int			i;
	t_player	player;
	t_enemy		enemy;

	i = 0;
	mlx_win = mlx_new_window(gdata->mlx, gdata->mdata->width * 64,
			gdata->mdata->height * 64, "so_long");
	if (!mlx_win)
		ft_free_triple(gdata->mlx, 0, gdata->mdata->map);
	gdata->win = mlx_win;
	player = ft_make_player(gdata->mdata->x, gdata->mdata->y);
	enemy = ft_init_enemy(gdata);
	ft_find_exit(gdata);
	ft_make_img(gdata);
	if (enemy.exist)
		ft_play(gdata, &player, &enemy);
	else
		ft_play(gdata, &player, 0);
}

int	main(int argv, char *argc[])
{
	void	*mlx;
	t_map	mapdata;
	t_data	gamedata;

	if (argv == 2)
	{
		mapdata = ft_init_map_data();
		check_name(argc[1]);
		ft_create_map(argc[1], &mapdata);
		mlx = mlx_init();
		if (!mlx)
			ft_free_triple(0, 0, mapdata.map);
		gamedata = ft_init_data(&mapdata, mlx);
		ft_init_game(&gamedata);
	}
	return (0);
}
