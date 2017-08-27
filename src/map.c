/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:23:08 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/26 16:23:12 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static int		check_border(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	while (j++ < e->map_height - 1)
	{
		i = -1;
		if (e->map[j][0] == 0 || e->map[j][e->map_width - 1] == 0 || e->map[j]
			[e->map_width - 1] == 9 || e->map[j][0] == 9)
			error_map(e);
		while (i++ < e->map_width - 1)
		{
			if (e->map[0][i] == 0 || e->map[e->map_height - 1][i] == 0 ||
				e->map[e->map_height - 1][i] == 9 || e->map[0][i] == 9)
				error_map(e);
		}
	}
	return (1);
}

static int		read_line(char **line, int y, t_env *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->map_height)
		error_map(e);
	line_split = ft_strsplit(*line, ' ');
	ft_strdel(line);
	if (!(e->map[y] = (int *)ft_memalloc(sizeof(int) * e->map_width)))
		return (0);
	while (line_split[++x])
	{
		if (ft_atoi(line_split[x]) > 9 || ft_atoi(line_split[x]) < 0 ||
		x > e->map_width)
			error_map(e);
		e->map[y][x] = ft_atoi(line_split[x]);
	}
	if (x != e->map_width)
		error_map(e);
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
	if (get_next_line(fd, &line) < 1)
		error_map(e);
	line_split = ft_strsplit(line, ' ');
	ft_strdel(&line);
	while (line_split[++i])
		;
	if (i != 4)
		error_map(e);
	e->map_width = ft_atoi(line_split[0]);
	e->map_height = ft_atoi(line_split[1]);
	e->play.pos.x = ft_atoi(line_split[2]) + 0.5;
	e->play.pos.y = ft_atoi(line_split[3]) + 0.5;
	if (e->map_width < 0 || e->map_height < 0 || e->play.pos.x < 0 ||
			e->play.pos.y < 0 || e->play.pos.x >= e->map_width ||
			e->play.pos.y >= e->map_height)
		error_map(e);
	ft_arrdel(&line_split);
	return (1);
}

static int		read_file(char *filename, t_env *e)
{
	int			fd;
	char		*line;
	int			y;

	y = -1;
	line = NULL;
	if (open(filename, O_DIRECTORY) == 1)
		error_map(e);
	if ((fd = open(filename, O_RDONLY)) < 0)
		error_map(e);
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
	if (e->map[(int)e->play.pos.x][(int)e->play.pos.y] != 0 || y !=
	e->map_height - 1 || !check_border(e))
		error_map(e);
	close(fd);
	return (1);
}

int				map(t_env *e)
{
	if (e->mapnb == 1)
		if (!read_file("./maps/map_1.map", e))
			error_map(e);
	if (e->mapnb == 2)
		if (!read_file("./maps/map_2.map", e))
			error_map(e);
	if (e->mapnb == 3)
		if (!read_file("./maps/map_3.map", e))
			error_map(e);
	e->mapon = 1;
	free(e->text);
	free(e->texture);
	mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	mlx_key_hook(e->mlx.win, key_hook_2, e);
	return (1);
}
