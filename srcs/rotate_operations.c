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

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
