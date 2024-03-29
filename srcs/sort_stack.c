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

static void	stack_quicksort(t_stacks *stacks, t_btree *chunks, int size)
{
	if (!chunks)
		return ;
	if (!stacks->b && (chunks->left))
		move_chunk_to_b(stacks, chunk(chunks->left));
	else if (stacks->b && chunks->right)
		move_chunk_to_a(stacks, chunk(chunks->right));
	stack_quicksort(stacks, chunks->left, size);
	if (!chunks->left)
		sort_chunk(stacks, chunk(chunks));
	stack_quicksort(stacks, chunks->right, size);
}

void		sort_stack(t_stacks *stacks)
{
	int	size;

	size = ft_twlstcount(stacks->a);
	if (check_order(stacks->a))
		return ;
	if (size < 6)
		sort_small(stacks, chunk(stacks->chunks));
	else
		stack_quicksort(stacks, stacks->chunks, size);
}
