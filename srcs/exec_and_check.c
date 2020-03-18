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

int	check_order(t_twlist *stack)
{
	int	nb1;
	int	nb2;

	while (stack->end == 0)
	{
		nb1 = FIRST(stack);
		nb2 = SECOND(stack);
		if (nb1 > nb2)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	exec_operation(char *op, t_stacks *stacks)
{
	if (ft_strequ(op, "sa"))
		swap_a(stacks);
	else if (ft_strequ(op, "sb"))
		swap_b(stacks);
	else if (ft_strequ(op, "ss"))
		swap_ab(stacks);
	else if (ft_strequ(op, "pa"))
		push_a(stacks);
	else if (ft_strequ(op, "pb"))
		push_b(stacks);
	else if (ft_strequ(op, "ra"))
		rotate_a(stacks);
	else if (ft_strequ(op, "ras"))
		rotate_a_sorted(stacks);
	else if (ft_strequ(op, "rb"))
		rotate_b(stacks);
	else if (ft_strequ(op, "rr"))
		rotate_ab(stacks);
	else if (ft_strequ(op, "rra"))
		reverse_rotate_a(stacks);
	else if (ft_strequ(op, "rrb"))
		reverse_rotate_b(stacks);
	else if (ft_strequ(op, "rrr"))
		reverse_rotate_ab(stacks);
	else
		return (0);
	return (1);
}

void	exec_operations(t_stacks *stacks, char *ops)
{
	char	**split;
	int		i;

	if (!(split = ft_strsplit(ops, '\n')))
		return ;
	i = 0;
	while (split[i] != NULL)
		exec_operation(split[i++], stacks);
	i--;
	while (i >= 0)
		ft_strdel(&split[i--]);
	free(split);
}
