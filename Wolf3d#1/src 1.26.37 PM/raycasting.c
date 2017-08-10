/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:46:27 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 13:24:54 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void	ray_draw(t_env *e, int x)
{
	int			height;
	float		start;
	float		end;

	height = (int)(HEIGHT / e->dist);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	x = 0;
	// draw_line(e, x, start, end);
}

static void	ray_dist(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->side.x < e->side.y)
		{
			e->side.x += e->delta.x;
			e->map.x += e->step.x;
			e->hit_side = 0;
		}
		else
		{
			e->side.y += e->delta.y;
			e->map.y += e->step.y;
			e->hit_side = 1;
		}
		if (e->worldmap[e->map.x][e->map.y] > 0)
		{
			e->hit = 1;
			e->colornb = e->worldmap[e->map.x][e->map.y];
			if (e->hit_side == 0)
				e->dist = (e->map.x - e->raypos.x +
					(1 - e->step.x) / 2) / e->raydir.x;
			else
				e->dist = (e->map.y - e->raypos.y +
					(1 - e->step.y) / 2) / e->raydir.y;
		}
	}
}

static void	side_and_step(t_env *e)
{
	if (e->raydir.x < 0)
	{
		e->step.x = -1;
		e->side.x = (e->raypos.x - (int)e->raypos.x) * e->delta.x;
	}
	else
	{
		e->step.x = 1;
		e->side.x = ((int)e->raypos.x + 1.0 - e->raypos.x) * e->delta.x;
	}
	if (e->raydir.y < 0)
	{
		e->step.y = -1;
		e->side.y = (e->raypos.y - (int)e->raypos.y) * e->delta.y;
	}
	else
	{
		e->step.y = 1;
		e->side.y = ((int)e->raypos.y + 1.0 - e->raypos.y) * e->delta.y;
	}
}

static void	init_ray(t_env *e)
{
	e->map.x = (int)e->raypos.x;
	e->map.y = (int)e->raypos.y;
	e->delta.x = sqrt(1 + (e->raydir.y * e->raydir.y) / (e->raydir.x *
		e->raydir.x));
	e->delta.y = sqrt(1 + (e->raydir.x * e->raydir.x) / (e->raydir.y *
		e->raydir.y));
	e->hit = 0;
	e->dist = -1;
	e->hit_side = -1;
}

void		raycasting(t_env *e)
{
	int		x;

	x = -1;
	e->raypos.x = e->pos.x;
	e->raypos.y = e->pos.y;
	while (++x < WIDTH)
	{
		e->cam.x = 2 * x / (double)WIDTH - 1;
		e->raydir.x = e->dir.x + e->pl.x * e->cam.x;
		e->raydir.y = e->dir.y + e->pl.y * e->cam.x;
		init_ray(e);
		side_and_step(e);
		ray_dist(e);
		ray_draw(e, x);
	}
}
