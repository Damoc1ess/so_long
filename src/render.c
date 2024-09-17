/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:56:48 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 10:34:33 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	init_texture(t_game *ctx, char *texture_path)
{
	t_texture	new_texture;

	new_texture.data = mlx_xpm_file_to_image(ctx->mlx, texture_path,
			&(new_texture.width), &(new_texture.height));
	return (new_texture);
}

int	init_textures(t_game *ctx)
{
	ctx->textures = ft_safe_malloc(sizeof(t_texture) * 5);
	ctx->textures[WALL] = init_texture(ctx, WALL_TEXTURE);
	ctx->textures[GROUND] = init_texture(ctx, GROUND_TEXTURE);
	ctx->textures[PLAYER] = init_texture(ctx, PLAYER_TEXTURE);
	ctx->textures[COLLECTIBLE] = init_texture(ctx, COLLECTIBLE_TEXTURE);
	ctx->textures[EXIT] = init_texture(ctx, EXIT_TEXTURE);
	return (0);
}

void	render_collectibles(t_game *ctx, int i, int j)
{
	int	k;
	int	x;
	int	y;

	k = 0;
	x = j * 48;
	y = i * 48;
	while (k < ctx->map_data->collectibles.count)
	{
		if (ctx->map_data->collectibles.values[k].x == j
			&& ctx->map_data->collectibles.values[k].y == i
			&& ctx->map_data->collectibles.values[k].collected == 0)
		{
			mlx_put_image_to_window(ctx->mlx,
				ctx->window, ctx->textures[COLLECTIBLE].data, x, y);
		}
		k++;
	}
}

void	render_single(t_game *ctx, int i, int j, int track)
{
	int		x;
	int		y;

	x = j * 48;
	y = i * 48;
	if (ctx->map_data->map[i][j] != '1'
		&& ctx->map_data->map[i][j] != 'E')
		mlx_put_image_to_window(ctx->mlx,
			ctx->window, ctx->textures[GROUND].data, x, y);
	if (track == 0)
	{
		if (ctx->map_data->map[i][j] == '1')
			mlx_put_image_to_window(ctx->mlx,
				ctx->window, ctx->textures[WALL].data, x, y);
	}
	if (ctx->map_data->map[i][j] == 'E')
		mlx_put_image_to_window(ctx->mlx,
			ctx->window, ctx->textures[EXIT].data, x, y);
	render_collectibles(ctx, i, j);
	if (ctx->map_data->player_pos.x == j
		&& ctx->map_data->player_pos.y == i)
		mlx_put_image_to_window(ctx->mlx,
			ctx->window, ctx->textures[PLAYER].data, x, y);
}

int	render_tiles(t_game *ctx)
{
	int			i;
	int			j;
	static int	track_render;

	i = 0;
	while (i < ctx->map_data->height)
	{
		j = 0;
		while (j < ctx->map_data->width)
		{
			render_single(ctx, i, j, track_render);
			j++;
		}
		i++;
	}
	track_render = 1;
	return (0);
}
