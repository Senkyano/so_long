/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:12:03 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/27 11:42:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SO_LONG_H
# define LIB_SO_LONG_H

# include <stdbool.h>
# include "lib_utils.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR 1
# define MLX_ERROR 1

typedef struct s_image
{
	void	*ground;
	void	*wall;
	void	*player;
	void	*coin;
	void	*exit;
}	t_image;

typedef struct s_player
{
	size_t	coin;
	bool	under_exit;
	size_t	pos_x;
	size_t	player_move;
	size_t	pos_y;
}	t_player;

typedef struct s_map
{
	int		fd;
	char	**env;
	char	**cp_map;
	int		high;
	int		width;
	bool	start;
	bool	exit;
	bool	coin;
	bool	access_exit;
	size_t	n_coin;
	size_t	access_coin;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_player	player;
	t_image		texture;
}	t_game;

void	how_use(int n);
void	error_file(void);
void	free_map(t_map *map);
void	invalid_map(t_map *map, int n);
void	fail_display(t_game *game);
void	clear_game(t_game *game);
int		free_game(t_game *game);
// creation
void	map_creator(t_map *map, char *file_map);
void	map_valid(t_map *map, t_player *player);
void	init_poslayer(t_map *map, t_player *player, size_t x, size_t y);
bool	flood_field(t_map *map, size_t x, size_t y);
void	init_display(t_game *game);
void	aff_win(t_game *game);
// move 
void	check_player(t_game *game, int x, int y);

#endif