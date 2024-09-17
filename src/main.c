/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:25 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 10:34:33 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_exit_helper(t_game *ctx)
{
	int	i;
	int	nbr_texture;

	i = 0;
	nbr_texture = 5;
	if (ctx->textures)
	{
		while (i < nbr_texture)
		{
			mlx_destroy_image(ctx->mlx, ctx->textures[i].data);
			i++;
		}
		free(ctx->textures);
	}
	return (0);
}

int	free_exit(t_game *ctx)
{
	if (ctx->map_data)
	{
		clear_map(ctx->map_data->filled_map);
		clear_map(ctx->map_data->map);
		free(ctx->map_data->collectibles.values);
		free(ctx->map_data);
	}
	if (ctx->mlx)
	{
		free_exit_helper(ctx);
		mlx_loop_end(ctx->mlx);
		if (ctx->window)
			mlx_destroy_window(ctx->mlx, ctx->window);
		mlx_destroy_display(ctx->mlx);
		free(ctx->mlx);
	}
	exit(0);
}

t_map_data	*get_map_data(char *path)
{
	char		**map;
	t_map_data	*map_data;

	verif_ber(path);
	map = get_map(path);
	check_map(map);
	map_data = get_data(map);
	return (map_data);
}

t_game	init_game(void)
{
	t_game	new_ctx;

	new_ctx.map_data = NULL;
	new_ctx.mlx = NULL;
	new_ctx.window = NULL;
	new_ctx.textures = NULL;
	new_ctx.movement_count = 0;
	return (new_ctx);
}

int	main(int ac, char **av)
{
	t_game	ctx;

	if (ac != 2)
		ft_putstr_red("Error\nWrong number of arguments\n");
	ctx = init_game();
	ctx.map_data = get_map_data(av[1]);
	ctx.mlx = mlx_init();
	if (!ctx.mlx)
		free_exit(&ctx);
	ctx.window = mlx_new_window(ctx.mlx, ctx.map_data->width * 48,
			ctx.map_data->height * 48, "Error\not_so_long");
	if (init_textures(&ctx) < 0)
		free_exit(&ctx);
	render_tiles(&ctx);
	mlx_key_hook(ctx.window, handle_keypress, &ctx);
	mlx_hook(ctx.window, DestroyNotify,
		StructureNotifyMask, free_exit, &ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
