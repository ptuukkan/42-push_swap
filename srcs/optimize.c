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
	if (ft_strstr(*op, "\npb\npa\n"))
	{
		*op = ft_strreplace("\npb\npa\n", "\n", op);
		return (1);
	}
	else if (ft_strstr(*op, "\nsa\nsb\n"))
	{
		*op = ft_strreplace("\nsa\nsb\n", "\nss\n", op);
		return (1);
	}
	else if (ft_strstr(*op, "\nsb\nsa\n"))
	{
		*op = ft_strreplace("\nsb\nsa\n", "\nss\n", op);
		return (1);
	}
	else if (ft_strstr(*op, "\nra\nrb\n"))
	{
		*op = ft_strreplace("\nra\nrb\n", "\nrr\n", op);
		return (1);
	}
	else if (ft_strstr(*op, "\nrra\nrrb\n"))
	{
		*op = ft_strreplace("\nrra\nrrb\n", "\nrrr\n", op);
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
	return (op);
	i = 0;
	while (optimizations_found(&op))
	{
		i++;
	}
	printf("Optimizations found: %d\n", i);
	return (op);
}
