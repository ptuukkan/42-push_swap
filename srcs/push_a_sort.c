/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stacks *stacks, int x, int max_moves)
{
	int			fwd;
	int			rev;
	t_twlist	*lst;

	fwd = 0;
	rev = 0;
	lst = stacks->a;
	if (max_moves == 0 && stacks->last_sorted)
		max_moves = ft_twlstcount(stacks->a);
	while (fwd <= max_moves && (!(PREV(lst) < x && FIRST(lst) > x)))
	{
		lst = lst->next;
		fwd++;
	}
	lst = stacks->a;
	while (rev <= max_moves && (!(PREV(lst) < x && FIRST(lst) > x)))
	{
		lst = lst->prev;
		rev++;
	}
	if (fwd > max_moves && rev > max_moves)
	{
		lst = stacks->a;
		rev = 0;
		while (FIRST(lst) > PREV(lst))
		{
			lst = lst->prev;
			rev++;
		}
		lst = stacks->a;
		fwd = 0;
		while (FIRST(lst) > PREV(lst))
		{
			lst = lst->next;
			fwd++;
		}
	}
	if (rev < fwd)
		return (-rev);
	return (fwd);
}

void	push_a_sort(t_stacks *stacks, t_chunk *chunk, int remaining)
{
	int	position;

	position = get_position(stacks, FIRST(stacks->b), chunk->size - remaining);
	while (position > 0)
	{
		rotate_a(stacks, 1);
		position--;
	}
	while (position < 0)
	{
		reverse_rotate_a(stacks, -1);
		position++;
	}
	push_a(stacks);
}
