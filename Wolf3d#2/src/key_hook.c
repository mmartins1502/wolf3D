/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:49:56 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 16:21:22 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int			key_hook(int keycode, t_env *e)
{
	ft_printf("keycode = %d\n", keycode);
	if (keycode == 83)
		e->mapnb = 1;
	// if (keycode == 84)
	// 	e->mapnb = 2;
	// if (keycode == 85)
	// 	e->mapnb = 3;
	map(e);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	return (1);
}
