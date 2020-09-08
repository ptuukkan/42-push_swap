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

static void	sort_a_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "ras\nras\nras\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "ras\nsa\nras\nras\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "sa\nras\nras\nras\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nras\npa\nras\nras\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "sa\nras\nsa\nras\nras\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nras\nras\npa\nras\n");
}

static void	sort_b_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "pa\nras\npa\nras\npa\nras\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "pa\nras\npa\npa\nras\nras\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "pa\npa\nras\nras\npa\nras\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nras\nsa\nras\nras\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "pa\npa\nras\npa\nras\nras\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nras\nras\nras\n");
}

static int	find_position(t_twlist *lst, int x, int max_moves, t_chunk *chunk)
{
	int			i;

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
		while (i < max_moves && x < FIRST(lst) && in_chunk(PREV(lst), chunk) && x < PREV(lst))
		{
			lst = lst->prev;
			i--;
		}
	}
	return (i);
}

static void	sort_b_n(t_stacks *stacks, t_chunk *chunk, int remaining)
{
	int	position;

	while (remaining > 0)
	{
		position = find_position(stacks->a, FIRST(stacks->b), chunk->size - remaining, chunk);
		rotate_a(stacks, position);
		reverse_rotate_a(stacks, position);
		push_a(stacks);
		new_last_sorted(stacks, FIRST(stacks->a));
		remaining--;
		print_stacks(stacks);
	}
	while (in_chunk(FIRST(stacks->a), chunk))
		rotate_a(stacks, 1);
}

static void	sort_b(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 1)
		exec_operations(stacks, "pa\nras\n");
	else if (chunk->size == 2 && FIRST(stacks->b) > SECOND(stacks->b))
		exec_operations(stacks, "pa\npa\nras\nras\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "pa\nras\npa\nras\n");
	else if (chunk->size == 3)
		return sort_b_3(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b));
	else
		return (sort_b_n(stacks, chunk, chunk->size));
}

static void	sort_a(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 1)
		exec_operations(stacks, "ras\n");
	else if (chunk->size == 2 && FIRST(stacks->a) < SECOND(stacks->a))
		exec_operations(stacks, "ras\nras\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "sa\nras\nras\n");
	else if (chunk->size == 3)
		return sort_a_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a));
	else if (chunk->size == 4)
	{
		exec_operations(stacks, "pb\npb");
		if (FIRST(stacks->a) > SECOND(stacks->a))
			swap_a(stacks);
		sort_b_n(stacks, chunk, 2);
	}
	else if (chunk->size == 5)
	{
		exec_operations(stacks, "pb\npb\npb\n");
		if (FIRST(stacks->a) > SECOND(stacks->a))
			swap_a(stacks);
		sort_b_n(stacks, chunk, 3);
	}
}

void	sort_chunk(t_stacks *stacks, t_chunk *chunk)
{
	if (!stacks->b)
		return (sort_a(stacks, chunk));
	else
	{
		return (sort_b(stacks, chunk));
	}

}
