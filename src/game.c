/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:18:17 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/12 11:18:18 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    get_step(t_env *e, t_game *game)
{
    if (e->ray_dir.x < 0)
    {
        game->step_x = -1;
        game->side_dist.x = (e->ray_pos.x - game->map_x) * game->delta_dist.x;
    }
    else
    {
        game->step_x = 1;
        game->side_dist.x = (game->map_x + 1.0 - e->ray_pos.x) * game->delta_dist.x;
    }
    if (e->ray_dir.y < 0)
    {
        game->step_y = -1;
        game->side_dist.y = (e->ray_pos.y - game->map_y) * game->delta_dist.y;
    }
    else
    {
        game->step_y = 1;
        game->side_dist.y = (game->map_y + 1 - e->ray_pos.y) * game->delta_dist.y;
    }
}

void    perform_dda(t_env *e, t_game *game)
{
    while (game->hit == 0)
    {
        if (game->side_dist.x < game->side_dist.y)
        {
            game->side_dist.x += game->delta_dist.x;
            game->map_x += game->step_x;
            game->side = 0;
        }
        else
        {
            game->side_dist.y += game->delta_dist.y;
            game->map_y += game->step_y;
            game->side = 1;
        }
        if (e->map[game->map_x][game->map_y] > 0)
            game->hit = 1;
    }
    if (game->side == 0)
    {
        game->wall_dist = (int)(game->map_x - e->ray_pos.x +
            (1 - game->step_x) / 2) / e->ray_dir.x;
    }
    else
    {
        game->wall_dist = (int)(game->map_y - e->ray_pos.y +
            (1 - game->step_y) / 2) / e->ray_dir.y;
    }
}

void    cast_rays(t_env *e, int x)
{
    t_game  game;

    game.hit = 0;
    game.map_x = (int)e->ray_pos.x;
    game.map_y = (int)e->ray_pos.y;
    game.delta_dist.x = sqrt(1 + (e->ray_dir.y * e->ray_dir.y)
        / (e->ray_dir.x * e->ray_dir.x));
    game.delta_dist.y = sqrt(1 + (e->ray_dir.x * e->ray_dir.x)
        / (e->ray_dir.y * e->ray_dir.y));
    get_step(e, &game);
    perform_dda(e, &game);
    draw_game(e, &game, x);
}

void    game_loop(t_env *e)
{
    int x;

    x = 0;
    mlx_destroy_image(e->mlx, e->img);
    e->img = mlx_new_image(e->mlx, PLANE_W, PLANE_H);
    e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s), &(e->end));
    while (x < PLANE_W)
    {
        e->camera_x = 2 * x / (double)(PLANE_W - 1);
        e->ray_pos.x = e->pos.x;
        e->ray_pos.y = e->pos.y;
        e->ray_dir.x = e->dir.x + e->plane.x * e->camera_x;
        e->ray_dir.y = e->dir.y + e->plane.y * e->camera_x;
        cast_rays(e, x);
        x++;
    }
    mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}