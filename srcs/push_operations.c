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
	t_twlist	*temp;

	if (stacks->b == NULL)
		return;
	temp = stacks->b;
	if (stacks->b->end)
		stacks->b = NULL;
	else if (stacks->b->next->end)
	{
		stacks->b = stacks->b->next;
		stacks->b->next = NULL;
		stacks->b->prev = NULL;
	}
	else
	{
		stacks->b->prev->next = stacks->b->next;
		stacks->b->next->prev = stacks->b->prev;
		stacks->b = stacks->b->next;
	}
	temp->next = NULL;
	temp->prev = NULL;
	ft_twlstadd(&stacks->a, temp);
	//if (!stacks->a->prev && !stacks->a->end)
	//	ft_twlstconnect(stacks->a);
	ft_lstapp(&stacks->oplist, ft_lstnew("pa\n", 4));
}

void	push_b(t_stacks *stacks)
{
	t_twlist	*temp;

	if (stacks->a == NULL)
		return;
	temp = stacks->a;
	if (stacks->a->next->end)
	{
		stacks->a = stacks->a->next;
		stacks->a->next = NULL;
		stacks->a->prev = NULL;
	}
	else
	{
		stacks->a->prev->next = stacks->a->next;
		stacks->a->next->prev = stacks->a->prev;
		stacks->a = stacks->a->next;
	}
	temp->next = NULL;
	temp->prev = NULL;
	ft_twlstadd(&stacks->b, temp);
	if (!stacks->b->prev && !stacks->b->end)
		ft_twlstconnect(stacks->b);
	ft_lstapp(&stacks->oplist, ft_lstnew("pb\n", 4));
}
