/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "pa\nra\npa\nra\npa\nra\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "pa\nra\npa\npa\nra\nra\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "pa\npa\nra\nra\npa\nra\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nra\nsa\nra\nra\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "pa\npa\nra\npa\nra\nra\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nra\nra\nra\n");
}

static int	find_position(t_twlist *lst, int x, int max_moves, t_chunk *chunk)
{
	int	i;

	if (max_moves == 0)
		return (0);
	i = 0;
	if (x > FIRST(lst))
	{
		while (i < max_moves && x > FIRST(lst) && in_chunk(FIRST(lst), chunk))
		{
			lst = lst->next;
			i++;
		}
	}
	else
	{
		while (i > -max_moves && x < FIRST(lst) && in_chunk(PREV(lst), chunk)
				&& x < PREV(lst))
		{
			lst = lst->prev;
			i--;
		}
	}
	return (i);
}

void		sort_b_n(t_stacks *stacks, t_chunk *chunk, int remaining)
{
	int	position;

	while (remaining > 0)
	{
		if (remaining == 2 && FIRST(stacks->b) > SECOND(stacks->b))
			swap_b(stacks);
		position = find_position(stacks->a, FIRST(stacks->b),
					chunk->size - remaining, chunk);
		rotate_a(stacks, position);
		reverse_rotate_a(stacks, position);
		push_a(stacks);
		remaining--;
	}
	while (in_chunk(FIRST(stacks->a), chunk))
		rotate_a(stacks, 1);
}

static void	sort_b(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 1)
		exec_operations(stacks, "pa\nra\n");
	else if (chunk->size == 2 && FIRST(stacks->b) > SECOND(stacks->b))
		exec_operations(stacks, "pa\npa\nra\nra\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "pa\nra\npa\nra\n");
	else if (chunk->size == 3)
		return (sort_b_3(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b)));
	else
		return (sort_b_n(stacks, chunk, chunk->size));
}

void		sort_chunk(t_stacks *stacks, t_chunk *chunk)
{
	if (!stacks->b)
		sort_a(stacks, chunk);
	else
		sort_b(stacks, chunk);
	new_last_sorted(stacks, chunk->high);
}
