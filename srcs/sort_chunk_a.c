/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_a.c                                     :+:      :+:    :+:   */
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

static int	calculate_moves(t_twlist *lst, t_chunk *chunk, int hold)
{
	int	ret1;
	int	ret2;

	ret1 = 0;
	ret2 = 0;
	if (!in_chunk(first(lst), chunk))
		return (0);
	if (first(lst) < hold)
	{
		return (1 + calculate_moves(lst->next, chunk, hold));
	}
	else
	{
		ret1 = calculate_moves(lst->next, chunk, hold);
		ret2 = calculate_moves(lst->next, chunk, first(lst));
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
	while (in_chunk(first(lst), chunk))
	{
		current_moves = calculate_moves(lst, chunk, first(lst));
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

static void	sort_a_n(t_stacks *stacks, t_chunk *chunk, int i)
{
	int	hold;

	i = calculate_hold(stacks->a, chunk);
	while (i-- > 0)
		push_b(stacks);
	hold = first(stacks->a);
	while (in_chunk(first(stacks->a), chunk))
	{
		if (first(stacks->a) < hold)
			push_b(stacks);
		else
		{
			if (calculate_moves(stacks->a->next, chunk, hold) <
				calculate_moves(stacks->a->next, chunk, first(stacks->a)))
				push_b(stacks);
			else
			{
				hold = first(stacks->a);
				rotate_a(stacks, 1);
			}
		}
	}
	if (!in_chunk(first(stacks->a), chunk) && in_chunk(prev(stacks->a), chunk))
		reverse_rotate_a(stacks, -1);
	sort_b_n(stacks, chunk, ft_twlstcount(stacks->b));
}

void		sort_a(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 1)
		exec_operations(stacks, "ra\n");
	else if (chunk->size == 2 && first(stacks->a) < second(stacks->a))
		exec_operations(stacks, "ra\nra\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "sa\nra\nra\n");
	else if (chunk->size == 3)
		return (sort_a_3(stacks, first(stacks->a), second(stacks->a),
				third(stacks->a)));
	else
		return (sort_a_n(stacks, chunk, 0));
}
