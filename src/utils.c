/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:56:28 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 17:09:13 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_ber(char *arg)
{
	int		arg_size;

	arg_size = ft_strlen(arg);
	if (arg_size <= 4)
		ft_putstr_red("Error\nPlease enter a valid map.\n");
	if (ft_strncmp(arg + arg_size - 4, ".ber", 4) != 0)
		ft_putstr_red("Error\nWrong name extension.\n");
	return ;
}

void	clear_map(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

int	slstrchr(char *str, int c)
{
	int				i;
	unsigned char	cast;

	i = 0;
	cast = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == cast)
			return (i);
		i++;
	}
	if (str[i] == cast)
		return (i);
	return (0);
}

int	next_strchr(char *str, int c)
{
	static int		i;
	unsigned char	cast;

	cast = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == cast)
		{
			i++;
			return (i - 1);
		}
		i++;
	}
	if (str[i] == cast)
		return (i);
	return (0);
}
