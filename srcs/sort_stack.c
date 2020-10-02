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
		move_chunk_to_b(stacks, CHUNK(chunks->left));
	else if (stacks->b && chunks->right)
		move_chunk_to_a(stacks, CHUNK(chunks->right));
	stack_quicksort(stacks, chunks->left, size);
	if (!chunks->left)
		sort_chunk(stacks, CHUNK(chunks));
	stack_quicksort(stacks, chunks->right, size);
}

void		sort_stack(t_stacks *stacks, int size)
{
	if (size < 6)
		return (sort_small(stacks, CHUNK(stacks->chunks)));
	stack_quicksort(stacks, stacks->chunks, size);
}
