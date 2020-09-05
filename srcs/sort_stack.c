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

static void	move_chunks_to_b(t_stacks *stacks, t_btree *chunks, int sort_level)
{
	(void)stacks;
	if (!chunks || CHUNK(chunks)->level > sort_level)
		return;
	move_chunks_to_b(stacks, chunks->left, sort_level);
	if (CHUNK(chunks)->level == sort_level)
		move_chunk_to_b(stacks, CHUNK(chunks));
	move_chunks_to_b(stacks, chunks->right, sort_level);
}

// static void sort_chunks_to_a(t_stacks *stacks, t_btree *chunks)
// {

// }

void		sort_stack(t_stacks *stacks, int size)
{
	int	i;
	int	sort_level;

	i = 0;
	if (check_order(stacks->a))
		return ;
	if (size < 6)
		return (sort_small(stacks, size));
	sort_level = 2;
	if (size > 45)
		sort_level = 3;
	if (size > 200)
		sort_level = 4;
	if (size > 350)
		sort_level = 5;
	while (stacks->chunks[i])
	{
		move_chunks_to_b(stacks, stacks->chunks[i], sort_level);
		sort_to_a(stacks);
		i++;
	}
	//print_stacks(stacks);
}
