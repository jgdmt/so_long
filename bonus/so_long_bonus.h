/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:19:18 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/06 21:55:19 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_map
{
	int		collectible;
	int		start;
	int		exit;
	int		x;
	int		y;
	int		exitx;
	int		exity;
	int		to_reset;
	int		height;
	int		width;
	char	**map;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		items;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	exist;
}	t_enemy;

typedef struct s_data
{
	int			freeze;
	int			speed;
	void		*mlx;
	void		*win;
	void		*player_img;
	void		*wall_img;
	void		*floor_img;
	void		*items_img;
	void		*exit_img;
	void		*enemy_img;
	void		*anim2;
	void		*anim3;
	t_map		*mdata;
	t_player	*mc;
	t_enemy		*enemy;
}	t_data;

// Init functions
t_map		ft_init_map_data(void);
t_data		ft_init_data(t_map *map_data, void *mlx);
t_player	ft_make_player(int x, int y);
void		ft_make_img(t_data *data);

// Create map
char		**ft_create_map(char *file_name, t_map *map);
char		**ft_map_copy(t_map *mdata);
void		ft_find_start(char **map, int *xy);

// Check functions
void		check_name(char *file_name);
void		ft_check_map(t_map *mdata);
void		ft_check_errors(t_map *mdata, char *err);

// Events
int			keypress(int key, t_data *vars);
int			ft_exit(t_data *vars);

// t_player	ft_make_player(int x, int y);
void		ft_play(t_data *gdata, t_player *player, t_enemy *enemy);

// Free functions
void		ft_free_img(t_data *data, int to_exit);
void		ft_free_all(t_data *data, int exit_val);
void		ft_free_board(char **board, int len, int ex);

// Enemy functions
t_enemy		ft_init_enemy(t_data *data);
void		ft_enemy(t_data *data);
void		ft_draw_enemy(t_data *data, int k, int l);
void		ft_lose(t_data *data);

char		*get_next_line(int fd);
int			ft_printf(const char *str, ...);
int			ft_strlen(char *str);

#endif