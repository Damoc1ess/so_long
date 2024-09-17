/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:02 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/16 17:42:33 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_map_data	*parse_map(char **map)
{
	t_map_data	*map_data;
	int			i;

	i = 0;
	map_data = NULL;
	while (map[i] != NULL)
	{
		count_char(map[i], 'C');
		i++;
	}
	return (map_data);
}
