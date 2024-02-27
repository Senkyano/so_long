/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:17:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/27 11:51:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_so_long.h"
#include "../../includes/lib_utils.h"
#include <stdio.h>

static bool	same_length(char **sent);
static bool	wall_around(char **sent);
static void	inside_wall(t_map *map, t_player *player);

void	map_valid(t_map *map, t_player *player)
{
	if (!same_length(map->env))
		invalid_map(map, 0);
	if (!wall_around(map->env))
		invalid_map(map, 1);
	inside_wall(map, player);
	if (map->exit == false || map->start != true || map->coin != true)
		invalid_map(map, 5);
	map->cp_map = copy_sent(map->env);
	if (flood_field(map, player->pos_x, player->pos_y) == false)
		invalid_map(map, 4);
}

static bool	in_data_map(char c)
{
	if (c == 'E')
		return (true);
	else if (c == 'P')
		return (true);
	else if (c == 'C')
		return (true);
	else if (c == '0' || c == '1')
		return (true);
	return (false);
}

static void	inside_wall(t_map *map, t_player *player)
{
	map->high = -1;
	while (map->env[++map->high])
	{
		map->width = -1;
		while (map->env[map->high][++map->width])
		{
			if (map->env[map->high][map->width] == 'E' && map->exit == false)
				map->exit = true;
			else if (map->env[map->high][map->width] == 'P' && \
			map->start == false)
				init_poslayer(map, player, map->width, map->high);
			else if (map->env[map->high][map->width] == 'E' || \
			map->env[map->high][map->width] == 'P')
				invalid_map(map, 2);
			if (map->env[map->high][map->width] == 'C')
			{
				map->coin = true;
				map->n_coin++;
			}
			if (!in_data_map(map->env[map->high][map->width]))
				invalid_map(map, 3);
		}
	}
}

static bool	wall_around(char **sent)
{
	size_t	x;
	size_t	y;
	size_t	high;

	high = sent_len(sent);
	x = 0;
	y = 0;
	while (sent[y][x])
	{
		if (sent[y][x] != '1' || sent[high - 1][x] != '1')
			return (false);
		x++;
	}
	x--;
	while (sent[y])
	{
		if (sent[y][0] != '1' || sent[y][x] != '1')
			return (false);
		y++;
	}
	return (true);
}

static bool	same_length(char **sent)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = str_len(sent[0]);
	while (sent[i])
	{
		if (str_len(sent[i]) != n)
			return (false);
		i++;
	}
	if (i == 1)
		return (false);
	return (true);
}
