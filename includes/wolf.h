/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:25:08 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/11 17:04:27 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"

# define MAP_W 24
# define MAP_H 24
# define PLANE_W 512
# define PLANE_H 384

typedef struct  s_vect
{
    int x;
    int y;
}               t_vect;

typedef struct  s_env
{
    int     **map;
    void    *mlx;
    void    *img;
    void    *win;
    t_vect  pos;
    t_vect  dir;
    t_vect  plane;
    double  time;
    double  old_time;
    t_vect  cam;
}               t_env;

int     malloc_map(t_env *e);
int     get_map(t_env *e);
void    init_vars(t_env *e);

#endif
