/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:03:10 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/13 18:23:00 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_column(t_env *e, int x, t_draw draw)
{
	while (draw.start <= draw.end)
	{
		e->data[(x * 4) + (draw.start * e->s) + 2] = draw.red;
		e->data[(x * 4) + (draw.start * e->s) + 1] = draw.green;
		e->data[(x * 4) + (draw.start * e->s)] = draw.blue;
		draw.start++;
	}
}

void	get_color(t_game *game, t_env *e, t_draw *draw)
{
	draw->red = 0;
	draw->green = 0;
	draw->blue = 0;
	if (game->side == 0)
	{
		if (e->ray_dir.x < 0)
			draw->green = 100;
		draw->red = 100;
	}
	else
	{
		if (e->ray_dir.y < 0)
			draw->green = 100;
		draw->blue = 100;
	}
}

void	draw_game(t_env *e, t_game *game, int x)
{
	int		height;
	t_draw	draw;

	height = (int)(PLANE_H / game->wall_dist);
	draw.start = -1 * height / 2 + PLANE_H / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = height / 2 + PLANE_H / 2;
	if (draw.end > PLANE_H)
		draw.end = PLANE_H - 1;
	get_color(game, e, &draw);
	draw_column(e, x, draw);
}
