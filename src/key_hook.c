/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:49:56 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/24 13:22:32 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		move_backward(int keycode, t_env *e)
{
	if ((keycode == 125 || keycode == 1) && e->mapon == 1)
	{
		if (e->map[(int)(e->play.pos.x - e->play.dir.x *
				e->play.speed_move)][(int)(e->play.pos.y)] == 0 ||
				(e->map[(int)(e->play.pos.x + e->play.dir.x *
				e->play.speed_move)][(int)(e->play.pos.y)] == 9 &&
				e->space == 1))
			e->play.pos.x -= e->play.dir.x * e->play.speed_move;
		if (e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y -
				e->play.dir.y * e->play.speed_move)] == 0 || (
				e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y -
				e->play.dir.y * e->play.speed_move)] == 9 &&
				e->space == 1))
			e->play.pos.y -= e->play.dir.y * e->play.speed_move;
	}
}

int			e_mouse_move(int x, int y, t_env *e)
{
	static int		oldx = 600;

	if (e->mouse == 1)
	{
		if ((x < e->width && x > 0) && (y > 0 && y < e->height))
		{
			if (x < 20 || x > e->width - 20)
			{
				if (x < 20)
					move_left(e);
				else
					move_right(e);
			}
			else if (x > oldx)
				move_right(e);
			else
				move_left(e);
		}
	}
	oldx = x;
	return (0);
}

int			key_press(int keycode, t_env *e)
{
	key_move(keycode, e);
	return (0);
}

int			key_hook_2(int keycode, t_env *e)
{
	if (keycode == 46)
		e->mouse = e->mouse == 0 ? 1 : 0;
	if (keycode == 6)
		e->weapon += e->weapon == 3 ? -3 : 1;
	if (keycode == 257)
		e->play.sprint = !e->play.sprint;
	if (keycode == 34)
		e->wallcolor = e->wallcolor == 0 ? 1 : 0;
	if (keycode == 49 && e->mapon == 1)
		e->space = e->space == 0 ? 1 : 0;
	if (keycode == 53 && e->enter == 1 && e->mapon == 1)
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
	if (keycode == 53 && e->mapon == 0)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		ft_free(e);
		exit(0);
	}
	return (1);
}
