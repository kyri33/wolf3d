/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:23:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/11 14:24:27 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(void)
{
	t_env	e;

	if (malloc_map(&e) == 0)
		ft_putstr("Error with map malloc\n");
	else if (get_map(&e) == 0)
		ft_putstr("Error reading map\n");
	else
	{
		
	}
}
