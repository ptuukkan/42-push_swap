/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		first(t_twlist *lst)
{
	return (*(int *)lst->content);
}

int		second(t_twlist *lst)
{
	return (*(int *)lst->next->content);
}

int		third(t_twlist *lst)
{
	return (*(int *)lst->next->next->content);
}

int		prev(t_twlist *lst)
{
	return (*(int *)lst->prev->content);
}

t_chunk	*chunk(t_btree *node)
{
	return ((t_chunk *)node->content);
}
