/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:04:38 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/07 11:06:53 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa(int n, t_data *data)
{
	char	*str;
	int		i;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = ft_intlen(n);
	str = malloc((i + 1) * sizeof(char));
	if (str == 0)
		ft_free_all(data, -1);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (n % 10 * sign) + 48;
		n = n / 10; 
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

void	ft_draw(t_data *data, char c, int k, int l)
{
	if (data->freeze)
		ft_lose(data);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->items_img, k, l);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player_img, k, l);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit_img, k, l);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img, k, l);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->wall_img, k, l);
}

int	ft_render_next_frame(t_data *data)
{
	char	*moves;
	int		i;
	int		j;

	ft_enemy(data);
	mlx_clear_window(data->mlx, data->win);
	i = 0;
	while (data->mdata->map[i])
	{
		j = 0;
		while (data->mdata->map[i][j])
		{
			if (data->enemy && i == data->enemy->y && j == data->enemy->x)
				ft_draw_enemy(data, j * 64, i * 64);
			else
				ft_draw(data, data->mdata->map[i][j], j * 64, i * 64);
			j++;
		}
		i++;
	}
	moves = ft_itoa(data->mc->moves, data);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x0000ff, moves);
	free(moves);
	return (0);
}

void	ft_play(t_data *gdata, t_player *player, t_enemy *enemy)
{
	gdata->mc = player;
	gdata->enemy = enemy;
	mlx_hook(gdata->win, 2, 1L << 0, keypress, gdata);
	mlx_hook(gdata->win, 17, 0L, ft_exit, gdata);
	mlx_loop_hook(gdata->mlx, ft_render_next_frame, gdata);
	mlx_loop(gdata->mlx);
}
