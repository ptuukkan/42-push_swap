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

static void	print_operations(t_twlist *operations)
{
	if (!operations)
		return ;
	while (!operations->end)
	{
		ft_putstr((char *)operations->content);
		operations = operations->next;
	}
	ft_putstr((char *)operations->content);
}

int			main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*numbers;
	int			size;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	numbers = NULL;
	stacks.chunks = NULL;
	stacks.last_sorted = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	if (check_order(stacks.a))
		return (0);
	size = ft_twlstcount(stacks.a);
	if (!(numbers = init_array(stacks.a, size)))
		return (print_error());
	if (!(stacks.chunks = calculate_chunks(numbers, size)))
		return (print_error());
	sort_stack(&stacks, size);
	print_operations(stacks.oplist);
	return (0);
}
