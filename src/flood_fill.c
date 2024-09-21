/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:40 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/21 15:57:18 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_char(char *c)
{
	// if (*c != 'F' && *c != '1' && *c != 'E')
	if (*c != 'F' && *c != '1')
	{
		*c = 'F';
		return (1);
	}
	return (0);
}

void	flood_fill(t_vec2 p_pos, char **arr)
{
	t_vec2	new_pos;

	if (handle_char(&(arr[p_pos.y][p_pos.x])) == 0)
		return ;
	new_pos = (t_vec2){p_pos.x, p_pos.y - 1, 0};
	flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.x, p_pos.y + 1, 0};
	flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.x - 1, p_pos.y, 0};
	flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.x + 1, p_pos.y, 0};
	flood_fill(new_pos, arr);
}


void	verif_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == 'C'
				|| map[i][j] == 'P')
				{
					clear_map(map);
					ft_putstr_red("Error\nIntouchable empty\n");
				}
			j++;
		}
		i++;
		j = 0;
	}
}

char	**get_filled_map(t_vec2 p_pos, char **arr)
{
	int		i;
	int		column;
	char	**filled_arr;

	i = 0;
	column = 0;
	while (arr[column])
		column++;
	filled_arr = (char **)malloc(sizeof(char *) * (column + 1));
	if (!filled_arr)
		clear_map(arr);
	while (i < column)
	{
		filled_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	filled_arr[i] = NULL;
	print_map(filled_arr);
	flood_fill(p_pos, filled_arr);
	print_map(filled_arr);
	verif_flood(filled_arr);
	print_map(filled_arr);
	return (filled_arr);
}
