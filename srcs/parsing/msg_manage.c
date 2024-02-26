/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:24:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/26 18:34:51 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"
#include <stdio.h>

void	how_use(int n)
{
	if (n == 1)
		print_error("need 1 argument\n");
	else if (n == 2)
		print_error("map need to be '*.ber'\n");
	exit(ERROR);
}

void	error_file(void)
{
	print_error("Can't access to this map, it doesn't exist\n");
	exit(ERROR);
}

void	invalid_map(t_map *map, int n)
{
	if (n == 0)
		print_error("Invalid map : map is not a rectangle\n");
	else if (n == 1)
		print_error("Invalid map : wall isn't complete around the map\n");
	else if (n == 2)
		print_error("Invalid map : the map have 2 exit or start player\n");
	else if (n == 3)
		print_error("Invalid map : other caractere find than :-P-E-C-1-0-\n");
	else if (n == 4)
		print_error("Invalid map : collectible or exit can't be access\n");
	else if (n == 5)
		print_error("Invalid map : Position start, Exit or collectible\
 doesn't exist\n");
	else if (n == 6)
		print_error("Invalid mlx\n");
	free_map(map);
	exit(ERROR);
}

void	fail_display(t_game *game)
{
	if (game->texture.player != NULL)
		mlx_destroy_image(game->mlx, game->texture.player);
	if (game->texture.ground != NULL)
		mlx_destroy_image(game->mlx, game->texture.ground);
	if (game->texture.wall != NULL)
		mlx_destroy_image(game->mlx, game->texture.wall);
	if (game->texture.coin != NULL)
		mlx_destroy_image(game->mlx, game->texture.coin);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_map(&game->map);
	print_error("<Invalid image>\n");
	exit(ERROR);
}
