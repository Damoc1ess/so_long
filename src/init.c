/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:33 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 10:23:30 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	find_pos(char **map, char c)
{
	int		i;
	t_vec2	vec;

	i = 0;
	vec.x = 0;
	vec.y = 0;
	while (map[i])
	{
		if (slstrchr(map[i], c) != 0)
		{
			vec.x = slstrchr(map[i], c);
			vec.y = i;
			return (vec);
		}
		i++;
	}
	return (vec);
}

t_vec2	find_next_pos(char **map, char c, int reset)
{
	static int	i;
	static int	j;
	t_vec2		vec;

	vec = (t_vec2){0, 0, 0};
	if (reset == TRUE)
	{
		i = 0;
		return (vec);
	}
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				vec = (t_vec2){j, i, 0};
				return (j++, vec);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (vec);
}

t_map_data	*get_data(char **map)
{
	t_map_data	*map_data;
	char		**filled_arr;
	int			height;

	height = 0;
	map_data = ft_safe_malloc(sizeof(t_map_data));
	if (!map_data)
		clear_map(map);
	map_data->collectibles = get_all_collectibles(map, TRUE);
	map_data->player_pos = find_pos(map, 'P');
	map_data->exit_pos = find_pos(map, 'E');
	filled_arr = get_filled_map(map_data->player_pos, map);
	map_data->filled_map = filled_arr;
	map_data->map = map;
	while (map_data->map[height])
		height++;
	map_data->height = height;
	map_data->width = ft_strlen(map_data->map[0]);
	return (map_data);
}
