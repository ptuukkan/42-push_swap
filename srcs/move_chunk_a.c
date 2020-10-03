/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunk_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_forward(t_stacks *stacks, t_chunk *chunk)
{
	int	remaining;

	remaining = chunk->size;
	while (remaining)
	{
		while (!in_chunk(first(stacks->b), chunk))
			rotate_b(stacks, 1);
		push_a(stacks);
		remaining--;
	}
}

static void	move_nearest(t_stacks *stacks, t_chunk *chunk)
{
	int	nearest;
	int	remaining;

	remaining = chunk->size;
	while (remaining > 0)
	{
		nearest = find_nearest_in_chunk(stacks->b, chunk);
		rotate_b(stacks, nearest);
		reverse_rotate_b(stacks, nearest);
		push_a(stacks);
		remaining--;
	}
}

void		move_chunk_to_a(t_stacks *stacks, t_chunk *chunk)
{
	if (calc_chunk_moves(stacks->b, chunk))
		move_nearest(stacks, chunk);
	else
		move_forward(stacks, chunk);
}
