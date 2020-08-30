/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	temp;

	if (stacks->a == NULL || stacks->a == stacks->a->next)
		return ;
	temp = FIRST(stacks->a);
	FIRST(stacks->a) = SECOND(stacks->a);
	SECOND(stacks->a) = temp;
	ft_twlstapp(&stacks->oplist, ft_twlstnew("sa\n", 4));
}

void	swap_b(t_stacks *stacks)
{
	int	temp;

	if (stacks->b == NULL || stacks->b == stacks->b->next)
		return ;
	temp = FIRST(stacks->b);
	FIRST(stacks->b) = SECOND(stacks->b);
	SECOND(stacks->b) = temp;
	ft_twlstapp(&stacks->oplist, ft_twlstnew("sb\n", 4));
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
