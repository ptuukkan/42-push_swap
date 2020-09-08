/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	if (!stacks->debug)
		return ;
	int			size_a = ft_twlstcount(stacks->a);
	int			size_b = ft_twlstcount(stacks->b);
	t_twlist	*lst_a = stacks->a;
	t_twlist	*lst_b = stacks->b;
	int			size = size_a > size_b ? size_a : size_b;
	printf("Stack A    Stack B\n");
	while (size)
	{
		if (size_a)
		{
			printf("%2d", FIRST(lst_a));
			size_a--;
			lst_a = lst_a->next;
		}
		else
			printf("  ");
		if (size_b)
		{
			printf("%10d\n", FIRST(lst_b));
			size_b--;
			lst_b = lst_b->next;
		}
		else
			printf("  \n");
		size--;
	}
}

void	print_numbers(t_list *numbers)
{
	while (numbers)
	{
		ft_printf("%d ", *(int *)numbers->content);
		numbers = numbers->next;
	}
	ft_printf("\n");
}

static void	stack_quicksort(t_stacks *stacks, t_btree *chunks, int size)
{
	if (!chunks)
		return ;
	if (!stacks->b && (chunks->left || size < 12))
	{
		move_chunk_to_b(stacks, CHUNK(chunks));
		print_stacks(stacks);
	}
	if (stacks->b && chunks->right)
	{
		move_chunk_to_a(stacks, CHUNK(chunks->right));
		print_stacks(stacks);
	}
	stack_quicksort(stacks, chunks->left, size);
	if (!chunks->left)
	{
		sort_chunk(stacks, CHUNK(chunks));
		print_stacks(stacks);
	}
	stack_quicksort(stacks, chunks->right, size);
}

void		sort_stack(t_stacks *stacks, int size)
{
	if (size < 6)
		return (sort_small(stacks, size));
	print_stacks(stacks);
	stack_quicksort(stacks, stacks->chunks->left, size);
	print_stacks(stacks);
	stack_quicksort(stacks, stacks->chunks->right, size);
	print_stacks(stacks);
}
