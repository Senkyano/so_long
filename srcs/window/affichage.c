/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:35:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/27 11:52:21 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <unistd.h>
#include <stdio.h>

void	print_num(int i);
void	ft_putchar(char c);

static void	aff_win_loop(t_game *game, int x, int y)
{
	if (game->map.env[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->texture.coin, x * 50, y * 50);
	if (game->map.env[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->texture.player, x * 50, y * 50);
	if (game->map.env[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->texture.wall, x * 50, y * 50);
	if (game->map.env[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->texture.ground, x * 50, y * 50);
	if (game->map.env[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->texture.exit, x * 50, y * 50);
}

void	aff_win(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.env[++y])
	{
		x = -1;
		while (game->map.env[y][++x])
			aff_win_loop(game, x, y);
	}
}

void	check_player(t_game *game, int x, int y)
{
	if (game->map.env[y][x] == '1')
	{
		print_error("I can't move here,please choose an other direction\n");
		return ;
	}
	if (game->player.under_exit == false)
		game->map.env[game->player.pos_y][game->player.pos_x] = '0';
	else if (game->player.under_exit == true)
	{
		game->player.under_exit = false;
		game->map.env[game->player.pos_y][game->player.pos_x] = 'E';
	}
	game->player.pos_x = x;
	game->player.pos_y = y;
	game->player.player_move++;
	if (game->map.env[y][x] == 'E' && game->player.under_exit != true)
		game->player.under_exit = true;
	else if (game->map.env[y][x] == 'C')
		game->player.coin++;
	game->map.env[y][x] = 'P';
	aff_win(game);
	print_num(game->player.player_move);
	print_c('\n');
}

void	print_num(int i)
{
	if (i > 9)
		print_num(i / 10);
	print_c('0' + (i % 10));
}

int	free_game(t_game *game)
{
	clear_game(game);
	free_map(&game->map);
	return (1);
}
