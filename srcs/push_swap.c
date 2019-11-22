/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:51:53 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:51:54 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_operations(t_list *operations)
{
	while (operations)
	{
		ft_putendl((char *)operations->content);
		operations = operations->next;
	}
}

void		print_stack(t_list *stack)
{
	int	nb;

	while (stack != NULL)
	{
		nb = *(int *)stack->content;
		printf("%d\n", nb);
		stack = stack->next;
	}
}

t_list	*choose_algorithm(t_list *stack_a, t_list *stack_b, t_list *operations)
{
	size_t	n;

	n = ft_lstsize(stack_a) / 4;
	sort_quick(stack_a, stack_b, &operations, n);
	return (operations);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operations;

	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stack_a))
		return (print_error());
	operations = choose_algorithm(stack_a, stack_b, operations);
	print_operations(operations);
	return (0);
}
