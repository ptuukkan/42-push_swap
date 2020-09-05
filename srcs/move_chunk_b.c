/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunk_b.c                                     :+:      :+:    :+:   */
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
		while (!in_chunk(FIRST(stacks->a), chunk))
			rotate_a(stacks, 1);
		push_b(stacks);
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
		nearest = find_nearest_in_chunk(stacks->a, chunk);
		rotate_a(stacks, nearest);
		reverse_rotate_a(stacks, nearest);
		push_b(stacks);
		remaining--;
	}
}


void		move_chunk_to_b(t_stacks *stacks, t_chunk *chunk)
{
	int	mode;
	mode = calc_chunk_moves(stacks->a, chunk);
	if (mode == 1)
		move_forward(stacks, chunk);
	else if (mode == 3)
		move_nearest(stacks, chunk);
	else
	 	ft_exiterror("REVERSE NOT IMPLEMENTED", 1, 1);
	//ft_printf("%d - %d\n", chunk->low, chunk->high);
	//print_stacks(stacks);
}
