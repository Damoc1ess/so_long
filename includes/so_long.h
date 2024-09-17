/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:03:50 by fflamion          #+#    #+#             */
/*   Updated: 2024/09/17 10:37:24 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "mlx.h"
# include "../libft/includes/libft.h"

/* Textures */
# define WALL_TEXTURE "./textures/wall.xpm"
# define GROUND_TEXTURE "./textures/ground.xpm"
# define PLAYER_TEXTURE "./textures/guts.xpm"
# define COLLECTIBLE_TEXTURE "./textures/collectibles.xpm"
# define EXIT_TEXTURE "./textures/exit.xpm"

/* Booleans */
# define TRUE 1
# define FALSE 0

/* Directions */
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

/* Structures */
typedef struct s_vec2
{
	int	x;
	int	y;
	int	collected;
}	t_vec2;

typedef struct s_collectibles
{
	int		count;
	int		collected;
	t_vec2	*values;
}	t_collectibles;

typedef struct s_map_data
{
	t_vec2			player_pos;
	t_vec2			exit_pos;
	t_collectibles	collectibles;
	int				height;
	int				width;
	char			**map;
	char			**filled_map;
}	t_map_data;

typedef enum e_tex_name
{
	WALL,
	GROUND,
	PLAYER,
	COLLECTIBLE,
	EXIT
}	t_tex_name;

typedef struct s_texture
{
	int		id;
	int		height;
	int		width;
	void	*data;
}	t_texture;

typedef struct s_game
{
	int			movement_count;
	void		*mlx;
	void		*window;
	t_texture	*textures;
	t_map_data	*map_data;
}	t_game;

/* Function Prototypes */
t_map_data		*get_data(char **map);
t_vec2			find_pos(char **map, char c);
t_vec2			find_next_pos(char **map, char c, int reset);
t_collectibles	get_all_collectibles(char **map, int reset);
t_texture		init_texture(t_game *ctx, char *texture_path);
int				init_textures(t_game *ctx);
int				render_tiles(t_game *ctx);
int				move_to_direction(t_game *ctx, int direction);
int				move_player(int kc, t_game *ctx);
int				handle_keypress(int keycode, t_game *ctx);
int				free_exit(t_game *ctx);
void			debug(t_map_data *map);
void			verif_ber(char *arg);
char			**get_map(char *path);
int				get_height(char *path);
void			clear_map(char **array);
int				count_char(char *str, char c);
void			check_map(char **arr);
int				check_if_closed(char **arr);
char			**get_filled_map(t_vec2 p_pos, char **arr);
int				slstrchr(char *str, int c);
void			print_map(char **map);
int				check_required_elements(char **map, char c);
int				check_if_path(t_vec2 pos, char **filled_map);
int				next_strchr(char *str, int c);
int				print_mov_count(t_game *ctx);

#endif
