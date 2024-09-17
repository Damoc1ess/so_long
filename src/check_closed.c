/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:58:10 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/16 19:27:08 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top(char **arr)
{
	int	i;

	i = 0;
	while (arr[0][i])
	{
		if (arr[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_bottom(int column, char **arr)
{
	int	i;

	i = 0;
	column -= 1;
	while (arr[column][i])
	{
		if (arr[column][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_left(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i][0])
	{
		if (arr[i][0] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_right(int row, char **arr)
{
	int	i;

	i = 0;
	row -= 1;
	while (arr[i] && arr[i][row])
	{
		if (arr[i][row] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_if_closed(char **arr)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (arr[column] != NULL)
		column++;
	while (arr[0][row])
		row++;
	if (check_top(arr) == 1)
		return (1);
	if (check_bottom(column, arr) == 1)
		return (1);
	if (check_left(arr) == 1)
		return (1);
	if (check_right(row, arr) == 1)
		return (1);
	return (0);
}
