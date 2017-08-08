/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:57:20 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/08 18:20:51 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		raycasting(t_env *e)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		e->cam.x = 2 * x / (double)WIDTH - 1;
		e->raypos.x = e->pos.x;
		e->raypos.y = e->pos.y;
		e->raydir.x = e->dir.x + e->pl.x * e->cam.x;
		e->raydir.y = e->dir.y + e->pl.y * e->cam.x;
		x++;
	}
}

void		init_e(t_env *e)
{
	e->pos.x = 22;
	e->pos.y = 12;
	e->dir.x = -1;
	e->dir.y = 0;
	e->pl.x = 0;
	e->pl.y = 0.66;
}

t_env		*init_env(t_env *e)
{
	e = (t_env *)ft_memalloc(sizeof(t_env));
	return (e);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = NULL;
	if ((!(e = init_env(e))))
	{
		ft_putstr_fd("Wolf3d error.", 2);
		kill_program(e);
	}
	if (ac != 2 || !(av[1]))
	{
		ft_putstr_fd("Usage <filename> [map]", 2);
		return (0);
	}
	init_e(e);
	e->mlx = mlx_start(WIDTH, HEIGHT, "Wolf3d");
	raycasting(e);
	printf("posx = %f, posy = %f, dirx = %f, diry = %f, plx = %f, ply = %f\n", e->pos.x, e->pos.y, e->dir.x, e->dir.y, e->pl.x, e->pl.y);
	mlx_hook(e->mlx->win, 17, (1L << 17), kill_program, e);
	mlx_loop(e->mlx->mlx);
	return (1);
}
