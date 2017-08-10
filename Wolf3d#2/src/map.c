/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:23:08 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 18:23:25 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		read_line(char **line, int y, t_env *e)
{
	int		x;
	char	**line_split;

	x = -1;
	line_split = ft_strsplit(*line, ' ');
	ft_strdel(line);
	if (!(e->map[y] = (int *)ft_memalloc(sizeof(int) * e->map_width)))
		return (0);
	while (line_split[++x])
	{
		e->map[y][x] = ft_atoi(line_split[x]);
		// ft_printf("e->map[%d][%d] = %d\n", y, x, e->map[y][x]);
	}
	if (x != e->map_width)
		return (0);
	ft_arrdel(&line_split);
	return (1);
}

static int		read_pos(int fd, t_env *e)
{
	char	*line;
	int		i;
	char	**line_split;

	line = NULL;
	i = -1;
	get_next_line(fd, &line);
	line_split = ft_strsplit(line, ' ');
	ft_printf("line = %s\n", line);
	ft_strdel(&line);
	while (line_split[++i])
		;
	e->map_width = ft_atoi(line_split[0]);
	e->map_height = ft_atoi(line_split[1]);
	// e->play.pos.x = ft_atoi(line_split[2]) + 0.5;
	// e->play.pos.y = ft_atoi(line_split[3]) + 0.5;
	ft_printf("e->map_width = %d\n", e->map_width);
	ft_printf("e->map_height = %d\n", e->map_height);
	// ft_printf("line_split[2] = %d\n", line_split[2]);
	// ft_printf("e->play.pos.x = %d\n", e->play.pos.x);
	// ft_printf("line_split[3] = %d\n", line_split[3]);
	// ft_printf("e->play.pos.y = %d\n", e->play.pos.y);
	ft_arrdel(&line_split);
	// if (e->map_width < 0 || e->map_height < 0 || e->play.pos.x != 0 || e->play.pos.x >= e->map_width ||
	// 	e->play.pos.y >= e->map_height)
	// 	{
	// 		ft_printf("error map\n");
	// 		return (0);
	// 	}
	return (1);
}

static int		read_file(char *filename, t_env *e)
{
	int			fd;
	char		*line;
	int			y;

	y = -1;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (!read_pos(fd, e))
		return (0);
	if (!(e->map = (int **)ft_memalloc(sizeof(int *) * e->map_height)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(read_line(&line, ++y, e)))
			return (0);
		ft_strdel(&line);
	}
	return (1);
}

int				map(t_env *e)
{
	if (e->mapnb == 1)
		read_file("./map_1.map", e);
	if (e->mapnb == 2)
		read_file("./map_2.map", e);
	if (e->mapnb == 3)
		read_file("./map_3.map", e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (1);
}
