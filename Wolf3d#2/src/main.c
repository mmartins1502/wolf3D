/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:43:24 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/14 14:02:27 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <stdio.h>

static void		homescreen(t_env *e)
{
	int		i;
	int		w;
	int		h;

	e->text = ft_memalloc(sizeof(t_mlxo) * 2);
	e->texture = ft_memalloc(sizeof(char*) * 2);
	if (e->text == NULL || e->texture == NULL)
		exit(0);
	e->texture[0] = "../pics/XPM/homescreen.xpm";
	i = -1;
	e->text[0].img = mlx_xpm_file_to_image(e->mlx.mlx, e->texture[0],
			&w, &h);
	e->text[0].pxl = mlx_get_data_addr(e->text[0].img,
			&e->text[0].bpp, &e->text[0].s_line, &e->text[0].ed);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[0].img, 0, 0);
}

static void		display_comment_1(t_env *e)
{
	mlx_string_put(e->mlx.mlx, e->mlx.win, 530, 380, 0xFFFFFF,
		"Map #1    = 1");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 530, 400, 0xFFFFFF,
		"Map #2    = 2");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 530, 420, 0xFFFFFF,
		"Map #3    = 3");
}

int				ft_free(t_env *e)
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
	homescreen(e);
	display_comment_1(e);
	mlx_hook(e->mlx.win, 17, 18, close_win, e);
	mlx_key_hook(e->mlx.win, key_hook_1, e);
	mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, e);
	mlx_loop(e->mlx.mlx);
}
