/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:57:20 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 13:25:00 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static int	ft_free(t_env *e)
{
	if (e)
		free(e);
	return (1);
}

static void	init_mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
		&(e->mlx.ed));
}

static int		init_e(t_env *e)
{
	e->pos.x = 22;
	e->pos.y = 12;
	e->dir.x = -1;
	e->dir.y = 0;
	e->pl.x = 0;
	e->pl.y = 0.66;
	e->z = 0;
	init_mlx(e);
	e->color1 = COLOR1;
	e->color2 = COLOR2;
	e->color3 = COLOR3;
	e->color4 = COLOR4;
	e->colorsky = COLORSK;
	e->colorground = COLORGR;
	return (1);
}

int		close_win(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	ft_free(e);
	exit(1);
	return (1);
}

int			main(void)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))) || !(init_e(e)))
	{
		ft_free(e);
		exit(0);
		return (0);
	}
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "Wolf3d");
	raycasting(e);
	printf("posx = %f, posy = %f, dirx = %f, diry = %f, plx = %f, ply = %f\n",
		e->pos.x, e->pos.y, e->dir.x, e->dir.y, e->pl.x, e->pl.y);
	// mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	// mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, e);
	mlx_hook(e->mlx.win, 17, 18, close_win, e);
	// mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_loop(e->mlx.mlx);
	return (1);
}
