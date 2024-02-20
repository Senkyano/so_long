/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:07:03 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/20 14:09:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_so_long.h"

void	init_poslayer(t_map *map, t_player *player, size_t x, size_t y)
{
	map->start = true;
	player->pos_x = x;
	player->pos_y = y;
}
