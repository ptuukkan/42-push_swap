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

void	append_op(t_twlist **oplist, char *op)
{
	t_twlist	*tmp;
	int			size;

	tmp = *oplist;
	size = ft_twlstcount(tmp);
	if (size < 2)
	{
		ft_twlstapp(oplist, ft_twlstnew(op, ft_strlen(op) + 1));
		return ;
	}
	if (check_matching((char *)tmp->prev->content, op))
		ft_twlstdelone(&tmp->prev, &ft_lstfree);
	else
		ft_twlstapp(oplist, ft_twlstnew(op, ft_strlen(op) + 1));
}
