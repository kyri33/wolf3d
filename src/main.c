/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:23:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/15 11:10:18 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void	turn_left(t_env *e)
{
	t_vect	old_dir;

	old_dir.x = e->dir.x;
	e->dir.x = e->dir.x * cos(-1 * e->rot_speed)
		- e->dir.y * sin(-1 * e->rot_speed);
	e->dir.y = old_dir.x * sin(-1 * e->rot_speed) + e->dir.y
		* cos(-1 * e->rot_speed);
	old_dir.y = e->plane.x;
	e->plane.x = e->plane.x * cos(-1 * e->rot_speed) - e->plane.y
		* sin(-1 * e->rot_speed);
	e->plane.y = old_dir.y * sin(-1 * e->rot_speed) + e->plane.y
		* cos(-1 * e->rot_speed);
}

void	turn_right(t_env *e)
{
	t_vect	old_dir;

	old_dir.x = e->dir.x;
	e->dir.x = e->dir.x * cos(e->rot_speed) - e->dir.y
		* sin(e->rot_speed);
	e->dir.y = old_dir.x * sin(e->rot_speed) + e->dir.y
		* cos(e->rot_speed);
	old_dir.y = e->plane.x;
	e->plane.x = e->plane.x * cos(e->rot_speed) - e->plane.y
		* sin(e->rot_speed);
	e->plane.y = old_dir.y * sin(e->rot_speed) + e->plane.y
		* cos(e->rot_speed);
}

int		quit_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		get_key_event(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
	{
		if (e->map[(int)(e->pos.x + e->dir.x * e->move_speed)]
				[(int)e->pos.y] == 0)
			e->pos.x += e->dir.x * e->move_speed;
		if (e->map[(int)e->pos.x]
				[(int)(e->pos.y + e->dir.y * e->move_speed)] == 0)
			e->pos.y += e->dir.y * e->move_speed;
	}
	else if (keycode == 125)
	{
		e->pos.x -= e->dir.x * e->move_speed;
		e->pos.y -= e->dir.y * e->move_speed;
	}
	else if (keycode == 124)
		turn_left(e);
	else if (keycode == 123)
		turn_right(e);
	game_loop(e);
	return (1);
}

int		main(void)
{
	t_env	e;

	if (malloc_map(&e) == 0)
		ft_putstr("Error with map malloc\n");
	else if (get_map(&e) == 0)
		ft_putstr("Error reading map\n");
	else
	{
		init_vars(&e);
		game_loop(&e);
		mlx_key_hook(e.win, get_key_event, &e);
		mlx_hook(e.win, 17, 0L, quit_win, &e);
		mlx_loop(e.mlx);
		return (1);
	}
}
