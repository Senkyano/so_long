/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:48:06 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/25 02:06:22 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_so_long.h"
#include <stdbool.h>
#include <stdio.h>

static void	counteur_map(t_map *map, char c);

bool	flood_field(t_map *map, size_t x, size_t y)
{
	counteur_map(map, map->cp_map[y][x]);
	map->cp_map[y][x] = '1';
	if (map->cp_map[y][x - 1] != '1')
		flood_field(map, x - 1, y);
	if (map->cp_map[y][x + 1] != '1')
		flood_field(map, x + 1, y);
	if (map->cp_map[y + 1][x] != '1')
		flood_field(map, x, y + 1);
	if (map->cp_map[y - 1][x] != '1')
		flood_field(map, x, y - 1);
	if (map->access_coin == map->n_coin && map->access_exit == true)
		return (true);
	return (false);
}

void	counteur_map(t_map *map, char c)
{
	if (c == 'C')
		map->access_coin++;
	if (c == 'E')
		map->access_exit = true;
}
