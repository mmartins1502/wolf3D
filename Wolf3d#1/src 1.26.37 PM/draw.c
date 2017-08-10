/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:15:10 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 12:50:21 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

// static void	put_pxl(t_env *e, int x, int y, unsigned int color)
// {
// 	int		i;
//
// 	i = (x * 4 + (y * e->mlx.s_line));
// 	e->mlx.pxl[i] = color;
// 	e->mlx.pxl[++i] = color >> 8;
// 	e->mlx.pxl[++i] = color >> 16;
// }
//
// static int	get_color(t_env *e)
// {
// 	if (e->hit_side == 1)
// 	{
// 		if (e->step.y == -1)
// 			return (e->color1);
// 		if (e->step.y == 1)
// 			return (e->color2);
// 	}
// 	if (e->step.x == -1)
// 		return (e->color3);
// 	return (e->color4);
// }
//
// void		draw_line(t_env *e, int x, int start, int end)
// {
// 	int				i;
// 	unsigned int	color;
//
// 	color = get_color(e);
// 	i = -1;
// 	while (++i < start + e->z)
// 		put_pxl(e, x, i, e->colorsky);
// 	i--;
// 	while (++i <= end + e->z && i < HEIGHT)
// 		put_pxl(e, x, i, color);
// 	i--;
// 	while (++i < HEIGHT)
// 		put_pxl(e, x, i, e->colorground);
// }
