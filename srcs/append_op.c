/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_matching(char *last_op, char *new_op)
{
	if (ft_strequ(new_op, "pa\n") && ft_strequ(last_op, "pb\n"))
		return (1);
	if (ft_strequ(new_op, "pb\n") && ft_strequ(last_op, "pa\n"))
		return (1);
	if (ft_strequ(new_op, "ra\n") && ft_strequ(last_op, "rra\n"))
		return (1);
	if (ft_strequ(new_op, "rra\n") && ft_strequ(last_op, "ra\n"))
		return (1);
	if (ft_strequ(new_op, "rb\n") && ft_strequ(last_op, "rrb\n"))
		return (1);
	if (ft_strequ(new_op, "rrb\n") && ft_strequ(last_op, "rb\n"))
		return (1);
	return (0);
}

void	append_op(t_list **oplist, char *op)
{
	t_list	*tmp;

	tmp = *oplist;
	if (!tmp || !tmp->next)
	{
		ft_lstapp(oplist, ft_lstnew(op, ft_strlen(op) + 1));
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	if (check_matching((char *)tmp->next->content, op))
		ft_lstdelone(&tmp->next, &ft_lstfree);
	else
		tmp->next->next = ft_lstnew(op, ft_strlen(op) + 1);
}
