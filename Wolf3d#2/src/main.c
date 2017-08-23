/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:43:24 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/23 13:59:00 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <stdio.h>

void			homescreen(t_env *e)
{
	int		i;
	int		w;
	int		h;

	e->mlx.win = mlx_new_window(e->mlx.mlx, e->width, e->height, "WOLF3D");
	e->text = ft_memalloc(sizeof(t_mlxo) * 5);
	e->texture = ft_memalloc(sizeof(char*) * 5);
	if (e->text == NULL || e->texture == NULL)
		exit(0);
	e->texture[0] = "../pics/XPM/homescreen.xpm";
	e->texture[1] = "../pics/XPM/pressspace.xpm";
	e->texture[2] = "../pics/XPM/map_menu.xpm";
	e->texture[3] = "../pics/XPM/selecteur.xpm";
	i = -1;
	while (e->texture[++i])
	{
		e->text[i].img = mlx_xpm_file_to_image(e->mlx.mlx, e->texture[i],
				&w, &h);
		e->text[i].pxl = mlx_get_data_addr(e->text[i].img,
				&e->text[i].bpp, &e->text[i].s_line, &e->text[i].ed);
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[0].img, 0, 0);
	set_menu(e);
}

void			set_menu(t_env *e)
{
	if (e->enter == 0)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[1].img, e->width
			/ 4 + 100, e->height / 2 + 250);
	else
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[0].img, 0, 0);
	if (e->enter == 1)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[2].img, e->width
			/ 4, e->height / 3);
	if (e->enter == 1 && e->select == 1)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[3].img, e->width
			/ 3 + 30, e->height / 3 + 105);
	if (e->enter == 1 && e->select == 2)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[3].img, e->width
			/ 3 + 30, e->height / 3 + 162);
	if (e->enter == 1 && e->select == 3)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[3].img, e->width
			/ 3 + 30, e->height / 3 + 219);
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

int				main(int ac, char **av)
{
	t_env *e;

	if (ac != 1 || ft_strcmp(av[0], "wolf3d") == 0)
	{
		ft_putstr_fd("Usage <filename>.\n", 2);
		exit(0);
	}
	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))) || !(init_env(e)))
	{
		ft_free(e);
		exit(0);
		return (1);
	}
	homescreen(e);
	mlx_hook(e->mlx.win, 17, 18, close_win, e);
	mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, e);
	mlx_hook(e->mlx.win, 6, (1L << 6), e_mouse_move, e);
	mlx_key_hook(e->mlx.win, key_hook_1, e);
	mlx_loop(e->mlx.mlx);
}
