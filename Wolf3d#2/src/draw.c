/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:15:18 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/23 11:51:01 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void			put_pxl(t_env *e, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = color;
	e->mlx.pxl[++i] = color >> 8;
	e->mlx.pxl[++i] = color >> 16;
}

static void			get_color_bis(t_env *e)
{
	if (e->wallcolor == 0)
	{
		e->color1 = COLOR1;
		e->color2 = COLOR2;
		e->color3 = COLOR3;
		e->color4 = COLOR4;
		e->color_sky = COLORSK;
		e->color_ground = COLORGR;
	}
	else
	{
		e->color1 = COLOR5;
		e->color2 = COLOR6;
		e->color3 = COLOR7;
		e->color4 = COLOR8;
		e->color_sky = COLORSK1;
		e->color_ground = COLORGR1;
	}
}

static int			get_color(t_env *e)
{
	get_color_bis(e);
	if (e->ray.hit_side == 1)
	{
		if (e->ray.step.y == -1)
			return (e->color1);
		if (e->ray.step.y == 1)
			return (e->color2);
	}
	if (e->ray.step.x == -1)
		return (e->color3);
	return (e->color4);
}

void				draw_line(t_env *e, int x, int start, int end)
{
	unsigned int	color;
	int				i;

	i = -1;
	color = get_color(e);
	while (++i < start + e->play.z)
		put_pxl(e, x, i, e->color_sky);
	i--;
	while (++i <= end + e->play.z && i < e->height)
	{
		put_pxl(e, x, i, color);
	}
	i--;
	while (++i < e->height)
		put_pxl(e, x, i, e->color_ground);
}
