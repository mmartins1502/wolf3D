/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 16:44:31 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/10 16:45:34 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_arrdel(char ***arr)
{
	char	**tmp;
	int		i;

	tmp = *arr;
	i = 0;
	if (!arr)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	*arr = NULL;
}
