/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/27 11:43:03 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	init_texture(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(int keycode, t_game *game);

void	init_display(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		invalid_map(&game->map, 6);
	game->window = mlx_new_window(game->mlx, game->map.width * 50, \
	game->map.high * 50, "Plebis");
	if (game->window == NULL)
	{
		clear_game(game);
		invalid_map(&game->map, 6);
	}
	init_texture(game);
	aff_win(game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, free_game, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, handle_key, game);
	mlx_loop(game->mlx);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		clear_game(game);
		free_map(&game->map);
	}
	move_player(keycode, game);
	if (game->player.coin == game->map.n_coin && \
	game->player.under_exit == true)
	{
		clear_game(game);
		free_map(&game->map);
	}
	return (0);
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
		check_player(game, game->player.pos_x, game->player.pos_y - 1);
	if (keycode == 115 || keycode == 65364)
		check_player(game, game->player.pos_x, game->player.pos_y + 1);
	if (keycode == 97 || keycode == 65361)
		check_player(game, game->player.pos_x - 1, game->player.pos_y);
	if (keycode == 100 || keycode == 65363)
		check_player(game, game->player.pos_x + 1, game->player.pos_y);
}

void	init_texture(t_game *game)
{
	int	i;

	i = 10;
	game->texture.player = mlx_xpm_file_to_image(game->mlx, \
	"srcs/texture/plebis_player.xpm", &i, &i);
	game->texture.ground = mlx_xpm_file_to_image(game->mlx, \
	"srcs/texture/grass.xpm", &i, &i);
	game->texture.wall = mlx_xpm_file_to_image(game->mlx, \
	"srcs/texture/arbre.xpm", &i, &i);
	game->texture.coin = mlx_xpm_file_to_image(game->mlx, \
	"srcs/texture/circuit-coin.xpm", &i, &i);
	game->texture.exit = mlx_xpm_file_to_image(game->mlx, \
	"srcs/texture/boeuf_finish.xpm", &i, &i);
	if (game->texture.player == NULL || game->texture.ground == NULL || \
		game->texture.wall == NULL || game->texture.coin == NULL || \
		game->texture.exit == NULL)
	{
		clear_game(game);
		free_map(&game->map);
		exit(0);
	}
}

void	clear_game(t_game *game)
{
	if (game->texture.player != NULL)
		mlx_destroy_image(game->mlx, game->texture.player);
	if (game->texture.ground != NULL)
		mlx_destroy_image(game->mlx, game->texture.ground);
	if (game->texture.wall != NULL)
		mlx_destroy_image(game->mlx, game->texture.wall);
	if (game->texture.coin != NULL)
		mlx_destroy_image(game->mlx, game->texture.coin);
	if (game->texture.exit != NULL)
		mlx_destroy_image(game->mlx, game->texture.exit);
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
