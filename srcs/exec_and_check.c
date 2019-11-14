/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	check_order(t_list *stack)
{
	int	nb1;
	int	nb2;

	while (stack != NULL)
	{
		nb1 = *(int *)stack->content;
		nb2 = *(int *)stack->next->content;
		if (nb1 > nb2)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	exec_operation(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strequ(instruction, "sa"))
		swap(stack_a);
	else if (ft_strequ(instruction, "sb"))
		swap(stack_b);
	else if (ft_strequ(instruction, "ss"))
		swap_ab(stack_a, stack_b);
	else if (ft_strequ(instruction, "pa"))
		push(stack_b, stack_a);
	else if (ft_strequ(instruction, "pb"))
		push(stack_a, stack_b);
	else if (ft_strequ(instruction, "ra"))
		rotate(stack_a);
	else if (ft_strequ(instruction, "rb"))
		rotate(stack_b);
	else if (ft_strequ(instruction, "rr"))
		rotate_ab(stack_a, stack_b);
	else if (ft_strequ(instruction, "rra"))
		reverse_rotate(stack_a);
	else if (ft_strequ(instruction, "rrb"))
		reverse_rotate(stack_b);
	else if (ft_strequ(instruction, "rrr"))
		reverse_rotate_ab(stack_a, stack_b);
	else
		return (0);
	return (1);
}
