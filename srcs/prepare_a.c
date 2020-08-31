/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stacks *stacks, int moves, void (*f)(t_stacks *))
{
	while (moves-- > 0)
	{
		(*f)(stacks);
	}

}

void		prepare_a(t_stacks *stacks, int last_sorted)
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
		rotate(stacks, rev, &reverse_rotate_a);
	else
		rotate(stacks, fwd, &rotate_a);
}
