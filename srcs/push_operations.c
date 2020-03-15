/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->b == NULL)
		return;
	temp = stacks->b->next;
	stacks->b->next = stacks->a;
	stacks->a = stacks->b;
	stacks->b = temp;
	ft_lstapp(&stacks->oplist, ft_lstnew("pa\n", 4));
}

void	push_b(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->a == NULL)
		return;
	temp = stacks->a->next;
	stacks->a->next = stacks->b;
	stacks->b = stacks->a;
	stacks->a = temp;
	ft_lstapp(&stacks->oplist, ft_lstnew("pb\n", 4));
}
