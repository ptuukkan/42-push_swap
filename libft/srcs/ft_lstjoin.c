/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:48:13 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 14:07:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstjoin(const void *s1, const void *s2)
{
	char	*joinstr;
	char	*str1;
	char	*str2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	joinstr = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	if (joinstr == NULL)
		return (NULL);
	joinstr = ft_strcat(joinstr, str1);
	joinstr = ft_strcat(joinstr, str2);
	return ((void *)joinstr);
}
