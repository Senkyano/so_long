/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:13:08 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/16 17:21:28 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_utils.h"
#include "../includes/lib_so_long.h"
#include <stdbool.h>

void	init_map(data_map *map);

int	main(int argc, const char **argv)
{
	data_map	map;

	if (argc != 2)
		how_use(1);
	if (!last_cmp((char *)argv[1], ".ber"))
		how_use(2);
	init_map(&map);
	map_creator(&map, (char *)argv[1]);
	map_valid(&map);
	free_split(map.env);
	return (0);
}

void	init_map(data_map *map)
{
	map->env = NULL;
	map->fd = -1;
	map->start = false;
	map->exit = false;
	map->coin = false;
	map->n_coin = 0;
}
