/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:08:58 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 18:07:27 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_window(t_data *data, int to_exit)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	if (to_exit)
		exit (-1);
}

void	ft_free_img(t_data *data, int to_exit)
{
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->items_img)
		mlx_destroy_image(data->mlx, data->items_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx, data->floor_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->enemy_img)
		mlx_destroy_image(data->mlx, data->enemy_img);
	if (data->anim2)
		mlx_destroy_image(data->mlx, data->anim2);
	if (data->anim3)
		mlx_destroy_image(data->mlx, data->anim3);
	if (to_exit)
		ft_free_window(data, 1);
}

void	ft_free_board(char **board, int len, int ex)
{
	int	i;

	i = 0;
	if (!board)
		return ;
	while (i < len)
		free(board[i++]);
	free(board);
	if (ex)
		exit (-1);
}

void	ft_free_all(t_data *data, int exit_val)
{
	ft_free_img(data, 0);
	ft_free_window(data, 0);
	ft_free_board(data->mdata->map, data->mdata->height, 0);
	exit (exit_val);
}
