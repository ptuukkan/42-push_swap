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
		exec_operations(stacks, "ra\nra\nra\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "ra\nsa\nra\nra\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "sa\nra\nra\nra\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nra\npa\nra\nra\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "sa\nra\nsa\nra\nra\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nra\nra\npa\nra\n");
}

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
		if (remaining == 2 && FIRST(stacks->b) > SECOND(stacks->b))
			swap_b(stacks);
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

static int	calculate_moves(t_twlist *lst, t_chunk *chunk, int hold)
{
	int	ret1;
	int	ret2;

	ret1 = 0;
	ret2 = 0;
	if (!in_chunk(FIRST(lst), chunk))
		return (0);
	if (FIRST(lst) < hold)
	{
		return (1 + calculate_moves(lst->next, chunk, hold));
	}
	else
	{
		ret1 = calculate_moves(lst->next, chunk, hold);
		ret2 = calculate_moves(lst->next, chunk, FIRST(lst));
		if (ret2 <= ret1)
			return (ret2);
		return (1 + ret1);
	}
}

static int	calculate_hold(t_twlist *lst, t_chunk *chunk)
{
	int			i;
	int			selected;
	int			selected_moves;
	int			current_moves;

	i = 0;
	selected = 0;
	selected_moves = INT32_MAX;
	current_moves = 0;
	while (in_chunk(FIRST(lst), chunk))
	{
		current_moves = calculate_moves(lst, chunk, FIRST(lst));
		if (current_moves + i < selected_moves)
		{
			selected_moves = current_moves + i;
			selected = i;
		}
		i++;
		lst = lst->next;
	}
	return (selected);
}

static void	sort_a_n(t_stacks *stacks, t_chunk *chunk)
{
	int i;
	int	hold;

	i = calculate_hold(stacks->a, chunk);
	while (i > 0)
	{
		push_b(stacks);
		i--;
	}
	hold = FIRST(stacks->a);
	while (in_chunk(FIRST(stacks->a), chunk))
	{
		if (FIRST(stacks->a) < hold)
			push_b(stacks);
		else
		{
			if (calculate_moves(stacks->a->next, chunk, hold) <
				calculate_moves(stacks->a->next, chunk, FIRST(stacks->a)))
				push_b(stacks);
			else
			{
				hold = FIRST(stacks->a);
				rotate_a(stacks, 1);
			}
		}
	}
	if (!in_chunk(FIRST(stacks->a), chunk) && in_chunk(PREV(stacks->a), chunk))
		reverse_rotate_a(stacks, -1);
	sort_b_n(stacks, chunk, ft_twlstcount(stacks->b));
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
		return sort_b_3(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b));
	else
		return (sort_b_n(stacks, chunk, chunk->size));
}

static void	sort_a(t_stacks *stacks, t_chunk *chunk)
{
	// int	i;

	// i = 0;
	if (chunk->size == 1)
		exec_operations(stacks, "ra\n");
	else if (chunk->size == 2 && FIRST(stacks->a) < SECOND(stacks->a))
		exec_operations(stacks, "ra\nra\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "sa\nra\nra\n");
	else if (chunk->size == 3)
		return sort_a_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a));
	else
	{
		return (sort_a_n(stacks, chunk));
		// while (i + 2 < chunk->size)
		// {
		// 	push_b(stacks);
		// 	i++;
		// }
		// if (FIRST(stacks->a) > SECOND(stacks->a))
		// 	swap_a(stacks);
		// sort_b_n(stacks, chunk, i);
	}
}

void	sort_chunk(t_stacks *stacks, t_chunk *chunk)
{
	if (!stacks->b)
		sort_a(stacks, chunk);
	else
		sort_b(stacks, chunk);
	new_last_sorted(stacks, chunk->high);
}
