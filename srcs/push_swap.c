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

void	sort_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b > c)
	{
		reverse_rotate(stacks, 'a', 0);
		swap(stacks, 'a', 0);
	}
	else if (a > b && a < c && b < c)
		swap(stacks, 'a', 0);
	else if (a < b && a > c && b > c)
		reverse_rotate(stacks, 'a', 0);
	else if (a > b && a > c && b < c)
		rotate(stacks, 'a', 0);
	else if (a > b && a > c && b > c)
	{
		rotate(stacks, 'a', 0);
		swap(stacks, 'a', 0);
	}
}

void	sort_small(t_stacks *stacks, int size)
{
	if (size == 3)
		sort_3(stacks, *(int *)stacks->a->content,\
		*(int *)stacks->a->next->content,\
		*(int *)stacks->a->next->next->content);
	else if (size == 2)
	{
		if (*(int *)stacks->a->content > *(int *)stacks->a->next->content)
			swap(stacks, 'a', 0);
	}
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
	if (check_order(stacks.a))
		return (0);
	size = ft_lstcount(stacks.a);
	if (size <= 3)
		sort_small(&stacks, size);
	else
		sort_quick(&stacks, 0);
	print_operations(stacks.oplist);
	return (0);
}
