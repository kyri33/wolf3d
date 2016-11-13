/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:25:08 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/13 18:14:08 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>

# define MAP_W 24
# define MAP_H 24
# define PLANE_W 800
# define PLANE_H 800

typedef struct	s_vect
{
	double x;
	double y;
}				t_vect;

typedef struct	s_env
{
	int		**map;
	void	*mlx;
	void	*img;
	void	*win;
	char	*data;
	int		bpp;
	int		s;
	int		end;
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;
	double	camera_x;
	t_vect	ray_pos;
	t_vect	ray_dir;
	double	move_speed;
	double	rot_speed;
}				t_env;

typedef struct	s_game
{
	int		map_x;
	int		map_y;
	t_vect	side_dist;
	t_vect	delta_dist;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}				t_game;

typedef struct	s_draw
{
	int	start;
	int	end;
	int	red;
	int	green;
	int	blue;
}				t_draw;

int				malloc_map(t_env *e);
int				get_map(t_env *e);
void			init_vars(t_env *e);
void			game_loop(t_env *e);
void			draw_game(t_env *e, t_game *game, int x);

#endif
