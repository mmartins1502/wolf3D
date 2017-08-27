/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 22:41:02 by mmartins          #+#    #+#             */
/*   Updated: 2017/08/24 11:18:49 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_stradd(char *s1, char const *s2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen((char *)s2))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	ft_strdel(&s1);
	return (res);
}
