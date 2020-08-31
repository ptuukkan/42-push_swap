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
#include <time.h>

t_avltree	*init_avl(t_twlist *stack)
{
	t_avltree	*avl;
	t_avltree	*new;

	avl = NULL;
	while(stack)
	{
		if (!(new = ft_avltnew(stack->content, stack->content_size)))
			return (NULL);
		if (!(avl = ft_avltinsert(avl, new, &ft_numcmp)))
			return (NULL);
		if (stack->end)
			break ;
		stack = stack->next;
	}
	return (avl);
}

void		print_operations(t_twlist *operations)
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

void		print_stack(t_twlist *stack)
{
	while (stack->end == 0)
	{
		ft_printf("%d\n", FIRST(stack));
		stack = stack->next;
	}
	ft_printf("%d\n", FIRST(stack));
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	t_avltree	*avl;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	avl = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	if (!(avl = init_avl(stacks.a)))
		return (print_error());
	stacks.last_sorted = NULL;
	if (check_order(stacks.a))
		return (0);
	if (ft_avltheight(avl) > 2)
		sort_stack(&stacks, avl);
	else
		sort_small(&stacks);
	print_operations(stacks.oplist);
	return (0);
}
