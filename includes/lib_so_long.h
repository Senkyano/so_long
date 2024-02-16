/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:12:03 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/16 17:17:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SO_LONG_H
# define LIB_SO_LONG_H

# include <stdbool.h>
#include "lib_utils.h"

# define ERROR 1

typedef struct s_player
{
	size_t	coin;
	size_t	pos_x;
	size_t	pos_y;
} data_player;

typedef struct s_map
{
	int		fd;
	char	**env;
	bool	start;
	bool	exit;
	bool	coin;
	size_t	n_coin;
} data_map;

void	how_use(int n);
void	error_file(void);
void	free_map(data_map *map);
void	invalid_map(data_map *map, int n);
// creation
void	map_creator(data_map *map, char *file_map);
void	map_valid(data_map *map);

#endif