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

void	rotate_a(t_stacks *stacks)
{
	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	stacks->a->end = 1;
	stacks->a->prev->end = 0;
	stacks->a = stacks->a->next;
	append_op(&stacks->oplist, "ra\n");
}

void	rotate_a_sorted(t_stacks *stacks)
{
	if (stacks->last_sorted == NULL)
		stacks->last_sorted = (int *)ft_memdup(&FIRST(stacks->a), stacks->a->content_size);
	else if (FIRST(stacks->a) > *stacks->last_sorted)
		ft_memcpy(stacks->last_sorted, &FIRST(stacks->a), stacks->a->content_size);
	rotate_a(stacks);
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stacks->b->end = 1;
	stacks->b->prev->end = 0;
	stacks->b = stacks->b->next;
	append_op(&stacks->oplist, "rb\n");
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
