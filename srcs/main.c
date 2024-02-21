/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:13:08 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/21 17:44:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_utils.h"
#include "../includes/lib_so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdbool.h>
#include <stdlib.h>

static void	init_map_player(t_game *game);
static void	clear_game(t_game *game);

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

static void	clear_game(t_game *game)
{
	if (game->texture.wall != NULL)
		mlx_destroy_image(game->mlx, game->texture.wall);
	if (game->texture.player != NULL)
		mlx_destroy_image(game->mlx, game->texture.player);
	if (game->texture.ground != NULL)
		mlx_destroy_image(game->mlx, game->texture.ground);
	if (game->texture.coin != NULL)
		mlx_destroy_image(game->mlx, game->texture.coin);
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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
