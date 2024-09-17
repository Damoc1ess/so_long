/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:40 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/16 19:28:37 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_char(char *c)
{
	if (*c != 'F' && *c != '1'
		&& *c != 'E')
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
	flood_fill(p_pos, filled_arr);
	return (filled_arr);
}
