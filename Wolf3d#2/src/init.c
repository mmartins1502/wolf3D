/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:50:51 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 18:24:16 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		init_play(t_env *e)
{
	e->play.pos.x = 5;
	e->play.pos.y = 2;
	e->play.dir.x = 1;
	e->play.dir.y = 1;
	e->play.pl.x = 0;
	e->play.pl.y = 0.66;
	e->play.z = 0;
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
	e->color1 = COLOR1;
	e->color2 = COLOR2;
	e->color3 = COLOR3;
	e->color4 = COLOR4;
	e->color_sky = COLORSK;
	e->color_ground = COLORGR;
	e->mapnb = 0;
	return (1);
}