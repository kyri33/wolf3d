/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:17:24 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/13 16:31:49 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_vars(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, PLANE_W, PLANE_H, "WOLF");
	e->img = mlx_new_image(e->mlx, PLANE_W, PLANE_H);
	e->pos.x = 22;
	e->pos.y = 12;
	e->dir.x = -1;
	e->dir.y = 0;
	e->plane.x = 0;
	e->plane.y = 0.66;
	e->move_speed = 0.1;
	e->rot_speed = 0.03;
}
