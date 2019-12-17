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

void	choose_algorithm(t_stacks *stacks)
{

	sort_quick(stacks);

}

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	size = ft_lstcount(stacks.a);
	if (size <= 3)
		sort_small(&stacks);
	else
		sort_big(&stacks);
	print_operations(stacks.oplist);
	return (0);
}
