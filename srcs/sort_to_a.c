/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(t_twlist *lst, int x, int size)
{
	int			moves;
	t_twlist	*tmp;

	moves = 0;
	tmp = lst;
	if (size < 2)
		return (0);
	while (moves < size && !(PREV(lst) < x && FIRST(lst) > x))
	{
		lst = lst->next;
		moves++;
	}
	if (moves == size)
	{
		moves = 0;
		while (FIRST(tmp) > PREV(tmp))
		{
			tmp = tmp->next;
			moves++;
		}
	}
	if (moves > (size / 2))
		return (-(size - moves));
	return (moves);
}

void		sort_to_a(t_stacks *stacks)
{
	int	position;
	int	size;

	size = 0;
	while (stacks->b)
	{
		position = find_position(stacks->a, FIRST(stacks->b), size);
		rotate_a(stacks, position);
		reverse_rotate_a(stacks, position);
		push_a(stacks);
		size++;
	}
	while (PREV(stacks->a) < FIRST(stacks->a))
		reverse_rotate_a(stacks, -1);
}
