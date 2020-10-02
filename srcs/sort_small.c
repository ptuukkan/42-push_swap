/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b > c)
		exec_operations(stacks, "rra\nsa\n");
	else if (a > b && a < c && b < c)
		swap_a(stacks);
	else if (a < b && a > c && b > c)
		reverse_rotate_a(stacks, -1);
	else if (a > b && a > c && b < c)
		rotate_a(stacks, 1);
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "ra\nsa\n");
}

static int	edge_position(t_twlist *lst)
{
	int			fwd;
	int			rev;
	t_twlist	*tmp;

	fwd = 0;
	rev = 0;
	tmp = lst;
	while (FIRST(lst) > PREV(lst))
	{
		fwd++;
		lst = lst->next;
	}
	while (FIRST(tmp) > PREV(tmp))
	{
		rev--;
		tmp = tmp->prev;
	}
	if (-rev < fwd)
		return (rev);
	return (fwd);
}

static int	find_position(t_twlist *lst, int x, int max_moves)
{
	int			i;

	if (max_moves == 0)
		return (0);
	i = 0;
	while (i < max_moves && !(FIRST(lst) > x && PREV(lst) < x))
	{
		lst = lst->next;
		i++;
	}
	if (i == max_moves)
		return (edge_position(lst));
	if (max_moves - i < i)
		return (-(max_moves - i));
	return (i);
}

static void	return_b(t_stacks *stacks, t_chunk *chunk, int remaining)
{
	int	position;
	int	head;

	while (remaining > 0)
	{
		position = find_position(stacks->a, FIRST(stacks->b),
					chunk->size - remaining);
		rotate_a(stacks, position);
		reverse_rotate_a(stacks, position);
		push_a(stacks);
		remaining--;
	}
	head = find_x(stacks->a, chunk->low);
	rotate_a(stacks, head);
	reverse_rotate_a(stacks, head);
}

void		sort_small(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 2 && FIRST(stacks->a) > SECOND(stacks->a))
		swap_a(stacks);
	else if (chunk->size == 3)
		return (sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
			THIRD(stacks->a)));
	else if (chunk->size == 4)
	{
		push_b(stacks);
		sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
			THIRD(stacks->a));
		return_b(stacks, chunk, 1);
	}
	else
	{
		exec_operations(stacks, "pb\npb\n");
		sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
			THIRD(stacks->a));
		return_b(stacks, chunk, 2);
	}
}
