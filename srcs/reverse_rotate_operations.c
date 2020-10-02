/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks, int times)
{
	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	while (times < 0)
	{
		stacks->a->prev->prev->end = 1;
		stacks->a->prev->end = 0;
		stacks->a = stacks->a->prev;
		append_op(&stacks->oplist, "rra\n");
		times++;
	}
}

void	reverse_rotate_b(t_stacks *stacks, int times)
{
	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	while (times < 0)
	{
		stacks->b->prev->prev->end = 1;
		stacks->b->prev->end = 0;
		stacks->b = stacks->b->prev;
		append_op(&stacks->oplist, "rrb\n");
		times++;
	}
}

void	reverse_rotate_ab(t_stacks *stacks)
{
	reverse_rotate_a(stacks, -1);
	reverse_rotate_b(stacks, -1);
}
