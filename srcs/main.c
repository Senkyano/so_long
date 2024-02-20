/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:13:08 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/20 14:49:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_utils.h"
#include "../includes/lib_so_long.h"
#include <stdbool.h>
#include <stdlib.h>

static void	init_map_player(t_map *map, t_player *player);

int	main(int argc, const char **argv)
{
	t_map		map;
	t_player	player;

	if (argc != 2)
		how_use(1);
	if (!last_cmp((char *)argv[1], ".ber"))
		how_use(2);
	init_map_player(&map, &player);
	map_creator(&map, (char *)argv[1]);
	map_valid(&map, &player);
	free_map(&map);
	return (0);
}

static void	init_map_player(t_map *map, t_player *player)
{
	map->env = NULL;
	map->fd = -1;
	map->start = false;
	map->exit = false;
	map->coin = false;
	map->access_exit = false;
	map->cp_map = NULL;
	map->n_coin = 0;
	map->access_coin = 0;
	player->coin = 0;
	player->pos_x = -1;
	player->pos_y = -1;
}
