/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:46 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/16 17:42:33 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("line: %s\n", map[i]);
		i++;
	}
}

void	debug(t_map_data *map)
{
	int	i;

	i = 0;
	ft_printf("pos_x: %d, pos_y: %d\n",
		map->player_pos.x, map->player_pos.y);
	ft_printf("Real map: \n");
	print_map(map->map);
	ft_printf("Filled map: \n");
	print_map(map->filled_map);
	while (i < map->collectibles.count)
	{
		ft_printf("collectible: %d -> x: %d, y: %d\n", i,
			map->collectibles.values[i].x,
			map->collectibles.values[i].y);
		i++;
	}
	ft_printf("player_pos -> x: %d, y: %d\n",
		map->player_pos.x, map->player_pos.y);
	ft_printf("exit_pos -> x: %d, y: %d\n",
		map->exit_pos.x, map->exit_pos.y);
	ft_printf("map info ->  height: %d, width: %d\n", map->height, map->width);
}

int	print_mov_count(t_game *ctx)
{
	ft_printf("Number of movement: %d\n", ctx->movement_count);
	return (0);
}
