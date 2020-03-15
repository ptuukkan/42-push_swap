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


void	swap(t_stacks *stacks, char stackchar, int both)
{
	t_list	*temp;
	t_list	**stack;

	if (stackchar == 'a')
	{
		stack = &stacks->a;
		if (both == 0)
			ft_lstapp(&stacks->oplist, ft_lstnew("sa", 3));
	}
	else
	{
		stack = &stacks->b;
		if (both == 0)
			ft_lstapp(&stacks->oplist, ft_lstnew("sb", 3));
	}
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack =  temp;
}

void	swap_ab(t_stacks *stacks)
{
	ft_lstapp(&stacks->oplist, ft_lstnew("ss", 3));
	swap(stacks, 'a', 1);
	swap(stacks, 'b', 1);
}
