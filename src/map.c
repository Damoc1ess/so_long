/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:17 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/20 14:08:36 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *path)
{
	int		fd;
	char	buf;
	int		height;
	int		char_count;

	height = 1;
	char_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_putstr_red("Error\nMap not found!\n");
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			height++;
		char_count++;
	}
	close(fd);
	if (char_count == 0)
		return (-1);
	else if(buf == '\n')
		return (-2);
	return (height + 1);
}

char	**fill_table(int fd, int height)
{
	char	*line;
	char	**table;
	int		i;

	i = 0;
	table = ft_safe_malloc(sizeof(char *) * (height));
	while (1)
	{
		line = get_next_line(fd);
		table[i] = line;
		if (i + 1 == height && table[i] == NULL)
			break ;
		else if (i + 1 != height && table[i] == NULL)
			clear_map(table);
		i++;
	}
	i = 0;
	while (table[i] && table[i][ft_strlen(table[i]) - 1] == '\n')
	{
		table[i][ft_strlen(table[i]) - 1] = '\0';
		i++;
	}
	return (table);
}

char	**get_map(char *path)
{
	int		fd;
	char	**table;
	int		height;

	height = get_height(path);
	if (height == -1)
		ft_putstr_red("Error\nMap doesn't have enough characters\n");
	else if (height == -2)
		ft_putstr_red("Error\nMap contain a newline character in the last line\n");
	fd = open(path, O_RDONLY);
	table = fill_table(fd, height);
	close(fd);
	return (table);
}
