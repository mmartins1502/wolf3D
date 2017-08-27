/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:52:53 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/24 11:30:45 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			ray_cal_dist_bis(t_env *e)
{
	if (e->map[e->ray.map.x][e->ray.map.y] > 0)
	{
		if (e->map[e->ray.map.x][e->ray.map.y] == 9 && e->space == 1)
			e->ray.hit = 0;
		else
			e->ray.hit = 1;
		if (e->ray.hit_side == 0)
			e->ray.dist = (e->ray.map.x - e->ray.pos.x +
				(1 - e->ray.step.x) / 2) / e->ray.dir.x;
		else
			e->ray.dist = (e->ray.map.y - e->ray.pos.y +
				(1 - e->ray.step.y) / 2) / e->ray.dir.y;
	}
}

int				error_map(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	ft_putstr_fd("Error map.\n", 2);
	ft_free(e);
	exit(0);
	return (0);
}

static void		draw_tile(t_env *e, int y, int x, unsigned int color)
{
	int		i;
	int		j;
	int		pos_y;
	int		pos_x;

	pos_y = e->height - (5 * e->map_height);
	pos_x = e->width - (25 + (5 * e->map_width));
	j = -1;
	while (++j <= 5)
	{
		i = -1;
		while (++i <= 5)
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, pos_x + (x + i), pos_y +
			(y + j), color);
	}
}

void			draw_minimap(t_env *e)
{
	int				y;
	int				x;
	int				pos_x;
	int				pos_y;
	unsigned int	color;

	pos_x = e->play.pos.y;
	pos_y = e->play.pos.x;
	y = -1;
	while (++y < e->map_height)
	{
		x = -1;
		while (++x < e->map_width)
		{
			if (e->map[y][x] > 0)
				color = 0x000000;
			else if (y == pos_y && x == pos_x)
				color = 0xFE0000;
			else
				color = 0xFFFFFF;
			draw_tile(e, 5 * y, 5 * x, color);
		}
	}
}
