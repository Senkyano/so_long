/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:11:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/26 14:55:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lib_so_long.h"
#include "lib_utils.h"
#include <stdio.h>

char	*keep_to(char *str, char c);

void	map_creator(t_map *map, char *file_map)
{
	size_t	i;
	char	*str;

	map->fd = open(file_map, O_RDONLY);
	if (map->fd == -1)
		error_file();
	i = 0;
	str = get_next_line(map->fd);
	if (str == NULL)
		free_map(map);
	while (str)
	{
		if (str == NULL)
			free_map(map);
		i++;
		if (lib_srch(str, '\n') != -1)
			str = keep_to(str, '\n');
		map->env = sentup_n(map->env, str, i);
		if (map->env == NULL)
			free_map(map);
		free(str);
		str = get_next_line(map->fd);
	}
}

char	*keep_to(char *str, char c)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(sizeof(char *) * (lib_srch(str, c) + 1));
	i = 0;
	if (!new_str)
		return (NULL);
	while (str[i] && str[i] != c)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

void	free_map(t_map *map)
{
	if (map->fd != -1)
		close(map->fd);
	free_split(map->env);
	free_split(map->cp_map);
	exit(ERROR);
}
