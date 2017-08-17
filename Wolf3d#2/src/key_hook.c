/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:49:56 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/17 17:07:09 by mmartins         ###   ########.fr       */
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
	if (keycode == 13)
		e->weapon += e->weapon == 3 ? -3 : 1;
	if (keycode == 257)
		e->play.sprint = !e->play.sprint;
	key_move(keycode, e);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	return (1);
}

int			key_hook_1(int keycode, t_env *e)
{
	if (keycode == 49 && e->enter == 0 && e->mapon == 0)
	{
		e->enter += 1;
		set_menu(e);
	}
	if ((keycode == 125 || keycode == 126) && e->mapon == 0 && e->enter == 1)
	{
		e->select += keycode == 125 ? 1 : -1;
		e->select = e->select > 3 ? 3 : e->select;
		e->select = e->select < 1 ? 1 : e->select;
		set_menu(e);
	}
	if ((keycode == 36 || keycode == 76) && e->enter == 1)
		e->mapnb = e->select;
	if (e->mapnb != 0)
		map(e);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		ft_free(e);
		exit(0);
	}
	return (1);
}
