/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:49:56 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/14 16:49:29 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int			key_press(int keycode, t_env *e)
{
	key_move(keycode, e);
	return (0);
}

int			key_hook_2(int keycode, t_env *e)
{
	key_move(keycode, e);
	if (keycode == 13)
		e->weapon += e->weapon == 3 ? -3 : 1;
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	return (1);
}

int			key_hook_1(int keycode, t_env *e)
{
	ft_printf("keycode = %d\n", keycode);
	key_move(keycode, e);
	if (keycode == 83 || keycode == 84)
		e->mapnb = keycode == 83 ? 1 : 2;
	if (keycode == 85 || keycode == 6)
		e->mapnb = keycode == 85 ? 3 : 0;
	if (e->mapnb != 0)
		map(e);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	return (1);
}
