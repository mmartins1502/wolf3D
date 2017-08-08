/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:57:20 by mmartins          #+#    #+#             */
/*   Updated: 2017/06/16 17:53:53 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_env		*init_env(t_env *e)
{
	e = (t_env *)ft_memalloc(sizeof(t_env));
	return (e);
}

int			main(int ac, char **av)
{
	t_env	*e;
	// int		ret;

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
	// if ((ret = init_opencl(e) < 0))
	// {
	// 	ft_printf("opencl error: %d\n", ret);
	// 	kill_program(e);
	// }
	e->mlx = mlx_start(WIDTH, HEIGHT, "Wolf3d");
	// mlx_key_hook(e->mlx->win, key_hook, e);
	// mlx_mouse_hook(e->mlx->win, mouse_hook, e);
	// mlx_hook(e->mlx->win, 6, (1L << 6), e_mouse_move, e);
	mlx_hook(e->mlx->win, 17, (1L << 17), kill_program, e);
	mlx_loop(e->mlx->mlx);
	return (1);
}
