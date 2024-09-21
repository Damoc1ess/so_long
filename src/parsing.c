/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:56 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/21 16:19:28 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_invalid_char(char **arr)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			c = arr[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E'
				&& c != 'P' && c != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_rectangular(char **arr)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(arr[i]);
	while (arr[i])
	{
		if (len != ft_strlen(arr[i]))
			return (1);
		i++;
	}
	if (len > 40 || i > 21)
		ft_putstr_red("Error\nMap to big\n");
	return (0);
}

int	check_max_char(char **arr)
{
	if (check_required_elements(arr, 'P') != 1)
		return (1);
	else if (check_required_elements(arr, 'E') != 1)
		return (1);
	else if (check_required_elements(arr, 'C') < 1)
		return (1);
	return (0);
}

int	check_available_path(char **arr)
{
	char			**filled_map;
	t_vec2			e_pos;
	int				invalid;
	t_collectibles	collec;
	int				i;

	i = 0;
	invalid = 0;
	e_pos = find_pos(arr, 'E');
	filled_map = get_filled_map(find_pos(arr, 'P'), arr);
	collec = get_all_collectibles(arr, TRUE);
	if (check_if_path(e_pos, filled_map) == 1)
		invalid = 1;
	while (i < collec.count)
	{
		if (check_if_path(collec.values[i], filled_map))
			invalid = 1;
		i++;
	}
	free(collec.values);
	clear_map(filled_map);
	return (invalid);
}

void	check_map(char **arr)
{
	if (check_invalid_char(arr) != 0)
	{
		clear_map(arr);
		ft_putstr_red("Error\nInvalid character in map.\n");
	}
	else if (check_rectangular(arr) != 0)
	{
		clear_map(arr);
		ft_putstr_red("Error\nMap is not rectangular.\n");
	}
	else if (check_if_closed(arr) != 0)
	{
		clear_map(arr);
		ft_putstr_red("Error\nMap is not closed by walls.\n");
	}
	else if (check_max_char(arr) != 0)
	{
		clear_map(arr);
		ft_putstr_red("Error\nMap invalid: requires 1 player, 1 exit, and at least 1 collectible.\n");
	}
	else if (check_available_path(arr) != 0)
	{
		clear_map(arr);
		ft_putstr_red("Error\nNo path found to exit/collectibles.\n");
	}
}
