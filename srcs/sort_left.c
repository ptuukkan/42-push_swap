/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
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

static void	sort_left_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "pa\nras\npa\nras\npa\nras\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "pa\nras\npa\npa\nras\nras\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "pa\npa\nras\nras\npa\nras\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "sb\npa\npa\npa\nras\nras\nras\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "pa\npa\nras\npa\nras\nras\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nras\nras\nras\n");
}

static void	sort_left_4(t_stacks *stacks, int a, int b, int c)
{
	int	d;

	d = FOURTH(stacks->b);
	if (a > b && a > c && a > d)
		exec_operations(stacks, "rb\n");
	else if (b > a && b > c && b > d)
		exec_operations(stacks, "rb\nrb\n");
	else if (c > a && c > b && c > d)
		exec_operations(stacks, "rrb\n");
	sort_left_3(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b));
	exec_operations(stacks, "pa\nras\n");
}

void	sort_left(t_stacks *stacks, t_avltree *avl)
{
	int	size;
	(void)avl;
	if (stacks->last_sorted)
		prepare_a(stacks, *stacks->last_sorted);
	size = ft_twlstcount(stacks->b);
	if (size == 1)
		exec_operations(stacks, "pa\nras\n");
	else if (size == 2 && (FIRST(stacks->b) > SECOND(stacks->b)))
		exec_operations(stacks, "pa\npa\nras\nras\n");
	else if (size == 2)
		exec_operations(stacks, "pa\nras\npa\nras\n");
	else if (size == 3)
		return (sort_left_3(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b)));
	else if (size == 4)
		return (sort_left_4(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b)));
}
