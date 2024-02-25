/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:35:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/25 03:24:40 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_so_long.h"
#include <stdio.h>

void	aff_win(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.env[y])
	{
		x = 0;
		while (game->map.env[y][x])
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
			if (game->map.env[y][x] == '0' || game->map.env[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->texture.ground, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
