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

static int	init_data(t_stacks *stacks, char **argv)
{
	int	size;
	int	*numbers;

	if (!init_stack(argv, &stacks->a))
		return (0);
	size = ft_twlstcount(stacks->a);
	if (!(numbers = init_array(stacks->a, size)))
		return (0);
	stacks->chunks = calculate_chunks(numbers, size);
	free(numbers);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	stacks.chunks = NULL;
	stacks.last_sorted = NULL;
	if (argc == 1)
		return (1);
	if (!init_data(&stacks, argv + 1))
		return (print_error());
	sort_stack(&stacks);
	print_operations(stacks.oplist);
	ft_btreedel(stacks.chunks, &ft_btreefree);
	ft_twlstdel(&stacks.a, &ft_lstfree);
	ft_twlstdel(&stacks.oplist, &ft_lstfree);
	free(stacks.last_sorted);
	return (0);
}
