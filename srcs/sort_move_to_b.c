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

static int	find_next_rev(t_twlist *a, int *floor, int ceil, int *position)
{
	int home;

	home = FIRST(a);
	if ((floor && home > *floor && home < ceil) || (!floor && home < ceil))
		return (1);
	a = a->prev;
	*position = -1;
	while (a && FIRST(a) != home)
	{
		if ((floor && FIRST(a) > *floor && FIRST(a) < ceil) || (!floor && FIRST(a) < ceil))
			return (1);
		a = a->prev;
		(*position)--;
	}
	return (0);
}

static int	find_next_fwd(t_twlist *a, int *floor, int ceil, int *position)
{
	int home;

	home = FIRST(a);
	if ((floor && home > *floor && home < ceil) || (!floor && home < ceil))
		return (1);
	a = a->next;
	*position = 1;
	while (a && FIRST(a) != home)
	{
		if ((floor && FIRST(a) > *floor && FIRST(a) < ceil) || (!floor && FIRST(a) < ceil))
			return (1);
		a = a->next;
		(*position)++;
	}
	return (0);
}

static int	find_next(t_twlist *a, int *floor, int ceil, int *position)
{
	int	fwd;
	int	rev;

	fwd = 0;
	rev = 0;
	if (find_next_fwd(a, floor, ceil, &fwd) && find_next_rev(a, floor, ceil, &rev))
	{
		if (ft_abs(rev) < ft_abs(fwd))
			*position = rev;
		else
			*position = fwd;
		return (1);
	}
	return (0);
}

void	move_to_b(t_stacks *stacks, int ceil)
{
	int	position;

	while ((find_next(stacks->a, stacks->last_sorted, ceil, &position)))
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
	}
}
