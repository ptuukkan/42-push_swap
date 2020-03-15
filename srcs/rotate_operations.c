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
	t_list	*temp;

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	temp = stacks->a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = stacks->a;
	stacks->a = stacks->a->next;
	temp->next->next = NULL;
	ft_lstapp(&stacks->oplist, ft_lstnew("ra\n", 4));
}

void	rotate_b(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	temp = stacks->b;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = stacks->b;
	stacks->b = stacks->b->next;
	temp->next->next = NULL;
	ft_lstapp(&stacks->oplist, ft_lstnew("rb\n", 4));
}

void	rotate_ab(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
