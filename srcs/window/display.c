/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/21 17:43:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	init_image(t_game *game, void *ptr, char *file);
void	init_texture(t_game *game);

void	init_display(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 50, 50, "Plebis deorum");
	// init_texture(game);
	// mlx_put_image_to_window(game->mlx, game->window, game->texture.player, 0*50, 0*50);
	// mlx_loop(game->mlx);
}

void	init_texture(t_game *game)
{
	init_image(game, game->texture.player, "../texture/plebis(1).xpm");
	// init_image(game, game->texture.wall, "../texture/");
	// init_image(game, game->texture.ground, "");
	// init_image(game, game->texture.coin, "");
}

void	init_image(t_game *game, void *ptr, char *file)
{
	int	width = 10;
	int	length = 10;
	ptr = mlx_xpm_file_to_image(game->mlx, file, \
	&width,&length );
	if (!ptr)
		fail_display(game);
}
