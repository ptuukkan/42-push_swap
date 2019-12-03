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

	while (stack->next != NULL)
	{
		nb1 = *(int *)stack->content;
		nb2 = *(int *)stack->next->content;
		if (nb1 > nb2)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_empty(t_list *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

int	exec_operation(char *instruction, t_stacks *stacks)
{
	if (ft_strequ(instruction, "sa"))
		swap(stacks, 'a', 0);
	else if (ft_strequ(instruction, "sb"))
		swap(stacks, 'b', 0);
	else if (ft_strequ(instruction, "ss"))
		swap_ab(stacks);
	else if (ft_strequ(instruction, "pa"))
		push(stacks, 'a');
	else if (ft_strequ(instruction, "pb"))
		push(stacks, 'b');
	else if (ft_strequ(instruction, "ra"))
		rotate(stacks, 'a', 0);
	else if (ft_strequ(instruction, "rb"))
		rotate(stacks, 'b', 0);
	else if (ft_strequ(instruction, "rr"))
		rotate_ab(stacks);
	else if (ft_strequ(instruction, "rra"))
		reverse_rotate(stacks, 'a', 0);
	else if (ft_strequ(instruction, "rrb"))
		reverse_rotate(stacks, 'b', 0);
	else if (ft_strequ(instruction, "rrr"))
		reverse_rotate_ab(stacks);
	else
		return (0);
	return (1);
}
