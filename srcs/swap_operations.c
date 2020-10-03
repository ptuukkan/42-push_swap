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
	temp = first(stacks->a);
	*(int *)stacks->a->content = second(stacks->a);
	*(int *)stacks->a->next->content = temp;
	ft_twlstapp(&stacks->oplist, ft_twlstnew("sa\n", 4));
}

void	swap_b(t_stacks *stacks)
{
	int	temp;

	if (stacks->b == NULL || stacks->b == stacks->b->next)
		return ;
	temp = first(stacks->b);
	*(int *)stacks->b->content = second(stacks->b);
	*(int *)stacks->b->next->content = temp;
	ft_twlstapp(&stacks->oplist, ft_twlstnew("sb\n", 4));
}

void	swap_ab(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
