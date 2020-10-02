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
	if (ft_strequ(new_op, "ra\n") && ft_strequ(last_op, "rb\n"))
		return (2);
	if (ft_strequ(new_op, "rb\n") && ft_strequ(last_op, "ra\n"))
		return (2);
	if (ft_strequ(new_op, "rra\n") && ft_strequ(last_op, "rrb\n"))
		return (2);
	if (ft_strequ(new_op, "rrb\n") && ft_strequ(last_op, "rra\n"))
		return (2);
	return (0);
}

static void	replace(t_twlist *lst, char *last_op, char *new_op)
{
	if ((ft_strequ(new_op, "ra\n") && ft_strequ(last_op, "rb\n")) ||
		(ft_strequ(new_op, "rb\n") && ft_strequ(last_op, "ra\n")))
	{
		((char *)lst->content)[1] = 'r';
	}
	else if ((ft_strequ(new_op, "rra\n") && ft_strequ(last_op, "rrb\n")) ||
		(ft_strequ(new_op, "rrb\n") && ft_strequ(last_op, "rra\n")))
	{
		((char *)lst->content)[2] = 'r';
	}
}

void		append_op(t_twlist **oplist, char *op)
{
	t_twlist	*tmp;
	int			result;

	tmp = *oplist;
	if (!tmp || tmp == tmp->next)
	{
		ft_twlstapp(oplist, ft_twlstnew(op, ft_strlen(op) + 1));
		return ;
	}
	result = check_matching((char *)tmp->prev->content, op);
	if (result == 1)
		ft_twlstdelone(&tmp->prev, &ft_lstfree);
	else if (result == 2)
		replace(tmp->prev, (char *)tmp->prev->content, op);
	else
		ft_twlstapp(oplist, ft_twlstnew(op, ft_strlen(op) + 1));
}
