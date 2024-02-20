/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/20 17:56:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_so_long.h"
#include 

void	init_display(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920, 1080, "Plebis deorum");
}
