/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:13:08 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/26 18:58:25 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_utils.h"
#include "../includes/lib_so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdbool.h>
#include <stdlib.h>

static void	init_map_player(t_game *game);

int	main(int argc, const char **argv)
{
	t_game	game;

	if (argc != 2)
		how_use(1);
	if (!last_cmp((char *)argv[1], ".ber"))
		how_use(2);
	init_map_player(&game);
	map_creator(&game.map, (char *)argv[1]);
	map_valid(&game.map, &game.player);
	init_display(&game);
	clear_game(&game);
	free_map(&game.map);
	return (0);
}

static void	init_map_player(t_game *game)
{
	game->map.env = NULL;
	game->map.fd = -1;
	game->map.start = false;
	game->map.exit = false;
	game->map.coin = false;
	game->map.access_exit = false;
	game->map.cp_map = NULL;
	game->map.n_coin = 0;
	game->map.high = 0;
	game->map.width = 0;
	game->map.access_coin = 0;
	game->player.coin = 0;
	game->player.pos_x = -1;
	game->player.pos_y = -1;
	game->mlx = NULL;
	game->window = NULL;
	game->texture.ground = NULL;
	game->texture.wall = NULL;
	game->texture.player = NULL;
	game->texture.coin = NULL;
}
