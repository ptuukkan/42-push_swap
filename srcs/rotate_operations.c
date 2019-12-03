/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stacks *stacks, char stackchar, int both)
{
	t_list	*temp;
	t_list	**stack;

	if (stackchar == 'a')
	{
		stack = &stacks->a;
		if (both == 0)
			ft_lstapp(&stacks->oplist, ft_lstnew("ra", 3));
	}
	else if (stackchar == 'b')
	{
		stack = &stacks->b;
		if (both == 0)
			ft_lstapp(&stacks->oplist, ft_lstnew("rb", 3));
	}
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = NULL;
}

void	reverse_rotate(t_stacks *stacks, char stackchar, int both)
{
	t_list	*temp;
	t_list	**stack;

	if (stackchar == 'a')
	{
		stack = &stacks->a;
		if (both == 0)
			ft_lstapp(&stacks->oplist, ft_lstnew("rra", 3));
	}
	else if (stackchar == 'b')
	{
		stack = &stacks->b;
		if (both == 0)
			ft_lstapp(&stacks->oplist, ft_lstnew("rrb", 3));
	}
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}

void	rotate_ab(t_stacks *stacks)
{
	ft_lstapp(&stacks->oplist, ft_lstnew("rr", 3));
	rotate(stacks, 'a', 1);
	rotate(stacks, 'b', 1);
}

void	reverse_rotate_ab(t_stacks *stacks)
{
	ft_lstapp(&stacks->oplist, ft_lstnew("rrr", 4));
	reverse_rotate(stacks, 'a', 1);
	reverse_rotate(stacks, 'b', 1);
}
