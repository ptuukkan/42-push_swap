/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:55:44 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/12/03 11:55:46 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		optimizations_found(char **op)
{
	if (ft_strstr(*op, "pb\npa\n"))
	{
		*op = ft_strreplace("pb\npa\n", "", op);
		return (1);
	}
	else if (ft_strstr(*op, "sa\nsb\n"))
	{
		*op = ft_strreplace("sa\nsb\n", "ss\n", op);
		return (1);
	}
	else if (ft_strstr(*op, "sb\nsa\n"))
	{
		*op = ft_strreplace("sb\nsa\n", "ss\n", op);
		return (1);
	}
	return (0);
}

char	*optimize(t_list *oplist)
{
	char	*op;
	int		i;

	if (!(op = ft_lstfold(&oplist, &ft_lstjoin)))
		exit(0);
	i = 0;
	while (optimizations_found(&op))
	{
		i++;
	}
	//printf("Optimizations found: %d\n", i);
	return (op);
}
