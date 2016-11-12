/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:03:10 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/12 15:03:13 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    draw_column(t_env *e, int x, int start, int end)
{
    while (start <= end)
    {
        e->data[(x * 4) + (start * e->s) + 2] = 100;
        e->data[(x * 4) + (start * e->s) + 1] = 0;
        e->data[(x * 4) + (start * e->s)] = 0;
        start++;
    }
}

void    draw_game(t_env *e, t_game *game, int x)
{
    int height;
    int start;
    int end;

    height = (int)(PLANE_H / game->wall_dist);
    start = -1 * height / 2 + PLANE_H / 2;
    if (start < 0)
        start = 0;
    end = height / 2 + PLANE_H / 2;
    if (end > PLANE_H)
        end = PLANE_H - 1;
    draw_column(e, x, start, end);
}