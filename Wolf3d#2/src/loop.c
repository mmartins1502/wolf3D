/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:24:11 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/14 16:52:19 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		weapon(t_env *e)
{
	int		i;
	int		w;
	int		h;

	e->text = ft_memalloc(sizeof(t_mlxo) * 4);
	e->texture = ft_memalloc(sizeof(char*) * 4);
	if (e->text == NULL || e->texture == NULL)
		exit(0);
	e->texture[0] = "../pics/XPM/MP40.xpm";
	e->texture[1] = "../pics/XPM/lasergun.xpm";
	e->texture[2] = "../pics/XPM/Slash.xpm";
	i = -1;
	while (e->texture[++i])
	{
		e->text[i].img = mlx_xpm_file_to_image(e->mlx.mlx, e->texture[i],
				&w, &h);
		e->text[i].pxl = mlx_get_data_addr(e->text[i].img,
				&e->text[i].bpp, &e->text[i].s_line, &e->text[i].ed);
	}
	if (e->weapon == 0)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[0].img, e->width
			/ 2 - 120, e->height / 2 + 80);
	else if (e->weapon == 1)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[1].img, e->width
			/ 2, e->height / 2 + 30);
	else if (e->weapon == 2)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[2].img, e->width
			/ 4 - 100, e->height / 2 + 95);
}

int				loop_hook(t_env *e)
{
	raycasting(e);
	if (e->play.jump)
	{
		if (e->play.z <= 50)
			e->play.z += 50;
	}
	if (e->play.sprint)
	{
		if (e->play.speed_move == 0.5)
			e->play.speed_move -= 0.4;
		else
			e->play.speed_move += 0.4;
	}
	if (!(e->play.jump) && e->play.z)
		e->play.z -= 50;
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	weapon(e);
	return (0);
}
