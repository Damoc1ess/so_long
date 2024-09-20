/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:10 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/20 13:43:27 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *ctx)
{
	if (keycode == XK_Escape)
		free_exit(ctx);
	move_player(keycode, ctx);
	return (0);
}

int	check_collectibles(t_game *ctx, t_vec2 player)
{
	int		i;

	i = 0;
	while (i < ctx->map_data->collectibles.count)
	{
		if (ctx->map_data->collectibles.values[i].collected == 0
			&& player.x == ctx->map_data->collectibles.values[i].x)
		{
			if (player.y == ctx->map_data->collectibles.values[i].y)
			{
				ctx->map_data->collectibles.values[i].collected = 1;
				ctx->map_data->collectibles.collected += 1;
			}
		}
		i++;
	}
	return (0);
}

int	can_exit(t_game *ctx, t_vec2 player)
{
	if (ctx->map_data->collectibles.collected
		== ctx->map_data->collectibles.count)
	{
		if (player.x == ctx->map_data->exit_pos.x
			&& player.y == ctx->map_data->exit_pos.y)
		{
			free_exit(ctx);
		}
	}
	return (0);
}

int	move_to_direction(t_game *ctx, int direction)
{
	t_vec2	*player_pos;
	char	**map;

	map = ctx->map_data->map;
	player_pos = &(ctx->map_data->player_pos);
	if (direction == UP
		&& map[player_pos->y - 1][player_pos->x] != '1')
		player_pos->y -= 1;
	else if (direction == DOWN
		&& map[player_pos->y + 1][player_pos->x] != '1')
		player_pos->y += 1;
	else if (direction == LEFT
		&& map[player_pos->y][player_pos->x - 1] != '1')
		player_pos->x -= 1;
	else if (direction == RIGHT
		&& map[player_pos->y][player_pos->x + 1] != '1')
		player_pos->x += 1;
	else
		return (0);
	check_collectibles(ctx, *player_pos);
	can_exit(ctx, *player_pos);
	render_tiles(ctx);
	ctx->movement_count += 1;
	print_mov_count(ctx);
	return (0);
}

int	move_player(int kc, t_game *ctx)
{
	if (kc == XK_w || kc == XK_W)
		move_to_direction(ctx, UP);
	if (kc == XK_a || kc == XK_A)
		move_to_direction(ctx, LEFT);
	if (kc == XK_s || kc == XK_S)
		move_to_direction(ctx, DOWN);
	if (kc == XK_d || kc == XK_D)
		move_to_direction(ctx, RIGHT);
	return (0);
}
