/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:50:51 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/14 15:06:57 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

// static void		set_weapon(t_env *e)
// {
// 	int		x;
// 	int		y;
//
// 	x = (e->win_x / 4);
// 	y = e->win_y - 250;
// 	if (e->weapon == 0)
// 	mlx_put_image_to_window(e->mlx, e->win, e->text[0].img_ptr, x + 100, y);
// 	else if (e->weapon == 1)
// 	{
// 		if (e->shot == 1)
// 		{
// 			mlx_put_image_to_window(e->mlx, e->win, e->text[3].img_ptr,
// 				x + 410, y);
// 				e->shot = 0;
// 			}
// 			mlx_put_image_to_window(e->mlx, e->win, e->text[1].img_ptr, x + 400, y);
// 			x = (e->win_x / 2) - 50;
// 			y = (e->win_y / 2) - 50;
// 			mlx_put_image_to_window(e->mlx, e->win, e->text[2].img_ptr, x, y);
// 		}
// 	}
// }
//
// static int		init_texture(t_env *e)
// {
// 	int		i;
// 	int		w;
// 	int		h;
//
// 	e->text = ft_memalloc(sizeof(t_img) * 11);
// 	e->texture = ft_memalloc(sizeof(char*) * 11);
// 	if (e->text == NULL || e->texture == NULL)
// 		return (-1);
// 	e->texture[0] = "../pics/textures/xpm/eagle.xpm";
// 	e->texture[1] = "../pics/textures/xpm/redbrick.xpm";
// 	e->texture[2] = "../pics/textures/xpm/purplestone.xpm";
// 	e->texture[3] = "../pics/textures/xpm/greystone.xpm";
// 	e->texture[4] = "../pics/textures/xpm/bluestone.xpm";
// 	e->texture[5] = "../pics/textures/xpm/bluestone.xpm";
// 	e->texture[6] = "../pics/textures/xpm/bluestone.xpm";
// 	e->texture[7] = "../pics/textures/xpm/bluestone.xpm";
// 	e->texture[8] = "../pics/textures/xpm/bluestone.xpm";
// 	e->texture[9] = "../pics/textures/xpm/bluestone.xpm";
// 	i = -1;
// 	while (e->texture[++i])
// 	{
// 		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx, e->texture[i],
// 				&w, &h);
// 		e->text[i].data = mlx_get_data_addr(e->text[i].img_ptr,
// 				&e->text[i].bpp, &e->text[i].sizeline, &e->text[i].endian);
// 	}
// 	return (0);
// }

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
	// init_texture(e);
	e->weapon = 0;
	e->color1 = COLOR1;
	e->color2 = COLOR2;
	e->color3 = COLOR3;
	e->color4 = COLOR4;
	e->color_sky = COLORSK;
	e->color_ground = COLORGR;
	e->mapnb = 0;
	return (1);
}
