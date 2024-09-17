/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:58:03 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/16 19:28:37 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_required_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_if_path(t_vec2 pos, char **filled_map)
{
	if (filled_map[pos.y][pos.x + 1] != 'F'
		&& filled_map[pos.y][pos.x - 1] != 'F'
		&& filled_map[pos.y + 1][pos.x] != 'F'
		&& filled_map[pos.y - 1][pos.x] != 'F')
		return (1);
	return (0);
}

t_collectibles	get_all_collectibles(char **map, int reset)
{
	int				i;
	int				max_collectible;
	t_vec2			*values;
	t_collectibles	collectibles;

	if (reset == TRUE)
		find_next_pos(map, 'C', TRUE);
	i = 0;
	max_collectible = check_required_elements(map, 'C');
	values = (t_vec2 *)malloc(sizeof(t_vec2) * (max_collectible));
	if (values == NULL)
		clear_map(map);
	collectibles.collected = 0;
	while (i < max_collectible)
	{
		values[i] = find_next_pos(map, 'C', FALSE);
		values[i].collected = 0;
		i++;
	}
	collectibles.count = max_collectible;
	collectibles.values = values;
	return (collectibles);
}
