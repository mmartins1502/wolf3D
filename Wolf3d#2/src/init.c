/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:50:51 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/23 17:01:59 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		init_play(t_env *e)
{
	e->play.pos.x = 0;
	e->play.pos.y = 0;
	e->play.dir.x = -1;
	e->play.dir.y = 0;
	e->play.pl.x = 0;
	e->play.pl.y = 0.66;
	e->play.z = 0;
	e->play.speed_move = 0.10;
	e->play.speed_turn = 0.10;
	e->play.jump = 0;
	e->play.sprint = 0;
}

static void		init_mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.img = mlx_new_image(e->mlx.mlx, e->width, e->height);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
		&(e->mlx.ed));
}

int				init_env(t_env *e)
{
	e->width = WIDTH;
	e->height = HEIGHT;
	init_play(e);
	init_mlx(e);
	e->weapon = 0;
	e->mapnb = 0;
	e->enter = 0;
	e->mapon = 0;
	e->select = 1;
	e->wallcolor = 0;
	e->mouse = 0;
	e->space = 0;
	return (1);
}
