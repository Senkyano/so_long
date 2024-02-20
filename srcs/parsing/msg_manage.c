/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:24:58 by rihoy             #+#    #+#             */
/*   Updated: 2024/02/20 14:49:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_so_long.h"
#include <stdlib.h>

void	how_use(int n)
{
	if (n == 1)
		print_error("need 1 argument\n");
	else if (n == 2)
		print_error("map need to be '*.ber'\n");
	exit(ERROR);
}

void	error_file(void)
{
	print_error("Can't access to this map, it doesn't exist\n");
	exit(ERROR);
}

void	invalid_map(t_map *map, int n)
{
	if (n == 0)
		print_error("Invalid map : map is not a rectangle\n");
	else if (n == 1)
		print_error("Invalid map : wall isn't complete around the map\n");
	else if (n == 2)
		print_error("Invalid map : the map have 2 exit or start player\n");
	else if (n == 3)
		print_error("Invalid map : other caractere find than :-P-E-C-1-0-\n");
	else if (n == 4)
		print_error("Invalid map : collectible or exit can't be access\n");
	free_map(map);
	exit(ERROR);
}
