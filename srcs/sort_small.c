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

void		sort_small_a(t_stacks *stacks, int size)
{
	int	a;
	int	b;
	int	c;

	if (size <= 1)
		return ;
	a = FIRST(stacks->a);
	b = SECOND(stacks->a);
	if (size == 2 && (a > b))
			swap_a(stacks);
	else if (size == 3)
	{
		c = THIRD(stacks->a);
		if (a < b && a < c && b > c)
			exec_operations(stacks, "rra\nsa\n");
		else if (a > b && a < c && b < c)
			swap_a(stacks);
		else if (a < b && a > c && b > c)
			reverse_rotate_a(stacks);
		else if (a > b && a > c && b < c)
			rotate_a(stacks);
		else if (a > b && a > c && b > c)
			exec_operations(stacks, "ra\nsa\n");
	}
}

static void	sort_3_b(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "pa\nra\npa\nra\npa\nra\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "pa\nra\npa\npa\nra\nra\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "pa\npa\nra\nra\npa\nra\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "sb\npa\npa\npa\nra\nra\nra\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "pa\npa\nra\npa\nra\nra\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nra\nra\nra\n");
}

void	sort_small_b(t_stacks *stacks, int size)
{
	if (size == 1)
		exec_operations(stacks, "pa\nra\n");
	else if (size == 2 && (FIRST(stacks->b) > SECOND(stacks->b)))
		exec_operations(stacks, "pa\npa\nra\nra\n");
	else if (size == 2)
		exec_operations(stacks, "pa\nra\npa\nra\n");
	else
		sort_3_b(stacks, FIRST(stacks->b), SECOND(stacks->b),
						THIRD(stacks->b));
}
