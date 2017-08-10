/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:43:24 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 17:48:47 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		display_comment_1(t_env *e)
{
	mlx_string_put(e->mlx.mlx, e->mlx.win, 500, 380, 0xFFFFFF,
		"Map #1    = 1");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 500, 400, 0xFFFFFF,
		"Map #2    = 2");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 500, 420, 0xFFFFFF,
		"Map #3    = 3");
}

int		ft_free(t_env *e)
{
	if (e)
		free(e);
	return (1);
}

static int		close_win(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	ft_free(e);
	exit(1);
	return (1);
}

int				main(void)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))) || !(init_env(e)))
	{
		ft_free(e);
		exit(0);
		return (1);
	}
	e->mlx.win = mlx_new_window(e->mlx.mlx, e->width, e->height, "WOLF3D");
	display_comment_1(e);
	mlx_hook(e->mlx.win, 17, 18, close_win, e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_loop(e->mlx.mlx);
}
