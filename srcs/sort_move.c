/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_rev(t_twlist *lst, int low, int high, int *position)
{
	int home;

	home = FIRST(lst);
	if (home >= low && home <= high)
		return (1);
	lst = lst->prev;
	*position = -1;
	while (lst && FIRST(lst) != home)
	{
		if (FIRST(lst) >= low && FIRST(lst) <= high)
			return (1);
		lst = lst->prev;
		(*position)--;
	}
	return (0);
}

static int	find_next_fwd(t_twlist *lst, int low, int high, int *position)
{
	int home;

	home = FIRST(lst);
	if (home >= low && home <= high)
		return (1);
	lst = lst->next;
	*position = 1;
	while (lst && FIRST(lst) != home)
	{
		if (FIRST(lst) >= low && FIRST(lst) <= high)
			return (1);
		lst = lst->next;
		(*position)++;
	}
	return (0);
}

static int	find_next(t_twlist *lst, int low, int high, int *position)
{
	int	fwd;
	int	rev;

	fwd = 0;
	rev = 0;
	if (!lst)
		return (0);
	if (find_next_fwd(lst, low, high, &fwd) && find_next_rev(lst, low, high, &rev))
	{
		if (ft_abs(rev) < ft_abs(fwd))
			*position = rev;
		else
			*position = fwd;
		return (1);
	}
	return (0);
}

void	move_to_b(t_stacks *stacks, t_chunk *chunk)
{
	int	position;
	int remaining;

	remaining = chunk->size;
	position = 0;
	while (remaining > 0 && find_next(stacks->a, chunk->low, chunk->high, &position))
	{
		while (position > 0)
		{
			rotate_a(stacks);
			position--;
		}
		while (position < 0)
		{
			reverse_rotate_a(stacks);
			position++;
		}
		push_b(stacks);
		remaining--;
	}
	if (stacks->last_sorted)
		prepare_a(stacks, *stacks->last_sorted);
}

void	move_to_a(t_stacks *stacks, t_chunk *chunk)
{
	int	position;
	int remaining;

	remaining = chunk->size;
	position = 0;
	while (remaining > 0 && find_next(stacks->b, chunk->low, chunk->high, &position))
	{
		while (position > 0)
		{
			rotate_b(stacks);
			position--;
		}
		while (position < 0)
		{
			reverse_rotate_b(stacks);
			position++;
		}
		push_a(stacks);
		remaining--;
	}
}
