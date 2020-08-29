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

static void	prepare_a(t_stacks *stacks, int last_sorted)
{
	int			fwd;
	int			rev;
	t_twlist	*a;

	a = stacks->a;
	fwd = 1;
	rev = -1;
	while (FIRST(a) != last_sorted)
	{
		a = a->next;
		fwd++;
	}
	a = stacks->a;
	while (FIRST(a) != last_sorted)
	{
		a = a->prev;
		rev++;
	}
	if (rev < fwd)
	{
		while (rev-- > 0)
			reverse_rotate_a(stacks);
	}
	else
	{
		while (fwd-- > 0)
			rotate_a(stacks);
	}
}

static int	find_prev_over(t_twlist *b, int nb, int *position)
{
	int home;

	home = FIRST(b);
	if (home >= nb)
		return (1);
	b = b->prev;
	*position = -1;
	while (b && FIRST(b) != home)
	{
		if (FIRST(b) >= nb)
			return (1);
		b = b->prev;
		(*position)--;
	}
	return (0);
}

static int	find_next_over(t_twlist *b, int nb, int *position)
{
	int home;

	home = FIRST(b);
	if (home >= nb)
		return (1);
	b = b->next;
	*position = 1;
	while (b && FIRST(b) != home)
	{
		if (FIRST(b) >= nb)
			return (1);
		b = b->next;
		(*position)++;
	}
	return (0);
}

static int	find_over(t_twlist *b, int nb, int *position)
{
	int	next;
	int	prev;

	next = 0;
	prev = 0;
	if (find_next_over(b, nb, &next) && find_prev_over(b, nb, &prev))
	{
		if (ft_abs(prev) < ft_abs(next))
			*position = prev;
		else
			*position = next;
		return (1);
	}
	return (0);
}

void	move_to_a(t_stacks *stacks, int nb)
{
	int	position;

	if (stacks->last_sorted)
		prepare_a(stacks, *stacks->last_sorted);
	while ((find_over(stacks->b, nb, &position)))
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
	}
}
