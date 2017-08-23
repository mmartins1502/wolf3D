/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 13:07:22 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/23 16:41:54 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		move_right(t_env *e)
{
	double	oldx;
	double	oldpx;

	oldx = e->play.dir.x;
	e->play.dir.x = e->play.dir.x * cos(-(e->play.speed_turn)) -
		e->play.dir.y * sin(-(e->play.speed_turn));
	e->play.dir.y = oldx * sin(-(e->play.speed_turn)) +
		e->play.dir.y * cos(-(e->play.speed_turn));
	oldpx = e->play.pl.x;
	e->play.pl.x = e->play.pl.x * cos(-(e->play.speed_turn)) -
		e->play.pl.y * sin(-(e->play.speed_turn));
	e->play.pl.y = oldpx * sin(-(e->play.speed_turn)) +
		e->play.pl.y * cos(-(e->play.speed_turn));
}

void		move_left(t_env *e)
{
	double	oldx;
	double	oldpx;

	oldx = e->play.dir.x;
	e->play.dir.x = e->play.dir.x * cos(e->play.speed_turn) -
		e->play.dir.y * sin(e->play.speed_turn);
	e->play.dir.y = oldx * sin(e->play.speed_turn) +
		e->play.dir.y * cos(e->play.speed_turn);
	oldpx = e->play.pl.x;
	e->play.pl.x = e->play.pl.x * cos(e->play.speed_turn) -
		e->play.pl.y * sin(e->play.speed_turn);
	e->play.pl.y = oldpx * sin(e->play.speed_turn) +
		e->play.pl.y * cos(e->play.speed_turn);
}

static void	move_forward_backward(int keycode, t_env *e)
{
	if ((keycode == 126 || keycode == 13) && e->mapon == 1)
	{
		if (e->map[(int)(e->play.pos.x + e->play.dir.x *
				e->play.speed_move)][(int)(e->play.pos.y)] == 0 ||
				(e->map[(int)(e->play.pos.x + e->play.dir.x *
				e->play.speed_move)][(int)(e->play.pos.y)] == 9 &&
				e->space == 1))
			e->play.pos.x += e->play.dir.x * e->play.speed_move;
		if (e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y +
				e->play.dir.y * e->play.speed_move)] == 0 || (
				e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y +
				e->play.dir.y * e->play.speed_move)] == 9 &&
				e->space == 1))
			e->play.pos.y += e->play.dir.y * e->play.speed_move;
	}
	else if ((keycode == 125 || keycode == 1) && e->mapon == 1)
	{
		if (e->map[(int)(e->play.pos.x - e->play.dir.x *
				e->play.speed_move)][(int)(e->play.pos.y)] == 0 ||
				(e->map[(int)(e->play.pos.x + e->play.dir.x *
				e->play.speed_move)][(int)(e->play.pos.y)] == 9 &&
				e->space == 1))
			e->play.pos.x -= e->play.dir.x * e->play.speed_move;
		if (e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y -
				e->play.dir.y * e->play.speed_move)] == 0 || (
				e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y +
				e->play.dir.y * e->play.speed_move)] == 9 &&
				e->space == 1))
			e->play.pos.y -= e->play.dir.y * e->play.speed_move;
	}
}

static void	move_lateral(int keycode, t_env *e)
{
	if (keycode == 2 && e->mapon == 1)
	{
		if (e->map[(int)(e->play.pos.x + e->play.dir.y *
				e->play.speed_move)][(int)(e->play.pos.y)] == 0)
			e->play.pos.x += e->play.dir.y * e->play.speed_move;
		if (e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y -
				e->play.dir.x * e->play.speed_move)] == 0)
			e->play.pos.y -= e->play.dir.x * e->play.speed_move;
	}
	if (keycode == 0 && e->mapon == 1)
	{
		if (e->map[(int)(e->play.pos.x - e->play.dir.y *
				e->play.speed_move)][(int)(e->play.pos.y)] == 0)
			e->play.pos.x -= e->play.dir.y * e->play.speed_move;
		if (e->map[(int)(e->play.pos.x)][(int)(e->play.pos.y +
				e->play.dir.x * e->play.speed_move)] == 0)
			e->play.pos.y += e->play.dir.x * e->play.speed_move;
	}
}

void		key_move(int keycode, t_env *e)
{
	move_forward_backward(keycode, e);
	move_lateral(keycode, e);
	if (keycode == 123 && e->mapon == 1)
		move_left(e);
	if (keycode == 124 && e->mapon == 1)
		move_right(e);
	if (keycode == 7 && e->mapon == 1)
		e->play.jump = !e->play.jump;
}
