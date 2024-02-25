/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/25 03:24:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	init_texture(t_game *game);
int	handle_key(int keycode, t_game *game);

void	init_display(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.width * 50, \
	game->map.high * 50, "Plebis");
	init_texture(game);
	aff_win(game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, handle_key, game);
	mlx_loop(game->mlx);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		clear_game(game);
	free_map(&game->map);
	return (0);
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
	if (game->texture.player == NULL || game->texture.ground == NULL || \
		game->texture.wall == NULL || game->texture.coin == NULL)
		clear_game(game);
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
	if (game->window != NULL)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
