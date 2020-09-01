/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
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
		exec_operations(stacks, "ras\nras\nras\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "ras\nsa\nras\nras\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "sa\nras\nras\nras\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nras\npa\nras\nras\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "sa\nras\nsa\nras\nras\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nras\nras\npa\nras\n");
}

static void	sort_a(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 1)
		exec_operations(stacks, "ras\n");
	else if (chunk->size == 2 && FIRST(stacks->a) < SECOND(stacks->a))
		exec_operations(stacks, "ras\nras\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "sa\nras\nras\n");
	else if (chunk->size == 3)
		return sort_a_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a));
}

static void	sort_b_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "pa\nras\npa\nras\npa\nras\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "pa\nras\npa\npa\nras\nras\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "pa\npa\nras\nras\npa\nras\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nras\nsa\nras\nras\n");
	else if (a > b && a > c && b < c)
		exec_operations(stacks, "pa\npa\nras\npa\nras\nras\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pa\npa\npa\nras\nras\nras\n");
}

static void	sort_b(t_stacks *stacks, t_chunk *chunk)
{
	if (chunk->size == 1)
		exec_operations(stacks, "pa\nras\n");
	else if (chunk->size == 2 && FIRST(stacks->b) > SECOND(stacks->b))
		exec_operations(stacks, "pa\npa\nras\nras\n");
	else if (chunk->size == 2)
		exec_operations(stacks, "pa\nras\npa\nras\n");
	else if (chunk->size == 3)
		return sort_b_3(stacks, FIRST(stacks->b), SECOND(stacks->b),
				THIRD(stacks->b));
}

void	sort(t_stacks *stacks, t_chunk *chunk)
{
	if (!stacks->b)
		return (sort_a(stacks, chunk));
	else
		return (sort_b(stacks, chunk));
}
