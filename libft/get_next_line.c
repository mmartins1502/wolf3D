/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:13:19 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/17 16:10:05 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static int		buffer_to_stock(int fd, char **stock, int *bytes_read)
{
	char	*buffer;
	char	*tmp;

	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (buffer == NULL)
		return (0);
	*bytes_read = read(fd, buffer, BUFF_SIZE);
	if (*bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[*bytes_read] = '\0';
	tmp = ft_strjoin(*stock, buffer);
	free(*stock);
	*stock = tmp;
	free(buffer);
	return (1);
}

static void		cut_stock(char **stock, char *str)
{
	char		*tmp;

	tmp = ft_strdup(str + 1);
	ft_strdel(stock);
	*stock = tmp;
}

static int		file_end(char **line, char **stock)
{
	if (ft_strlen(*stock))
	{
		*line = ft_strdup(*stock);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

static int		error_handling(char **stock)
{
	if (stock)
		ft_strdel(stock);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			*str;
	int				bytes_read;

	if (fd < 0 || !(line) || BUFF_SIZE < 0)
		return (-1);
	if (!(stock))
		stock = ft_strnew(0);
	while (!(ft_strchr(stock, '\n')))
	{
		if (!(buffer_to_stock(fd, &stock, &bytes_read)))
			return (error_handling(&stock));
		if (bytes_read == 0)
			return (file_end(line, &stock));
	}
	str = ft_strchr(stock, '\n');
	*line = ft_strsub(stock, 0, str - stock);
	cut_stock(&stock, str);
	return (1);
}
