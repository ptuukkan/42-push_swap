/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_right_3(t_stacks *stacks, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		exec_operations(stacks, "ras\nras\nras\n");
	else if (a < b && a < c && b > c)
		exec_operations(stacks, "ras\nsa\nras\nras\n");
	else if (a > b && a < c && b < c)
		exec_operations(stacks, "sa\nras\nras\nras\n");
	else if (a < b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nras\npa\nras\nras\n");
	else if (a > b && a > c && b > c)
		exec_operations(stacks, "pb\nsa\nras\nras\npa\nras\n");
	else
		exec_operations(stacks, "pb\nras\nras\npa\nras\n");
}

static void	sort_right_4(t_stacks *stacks, int a, int b, int c)
{
	int	d;

	d = FOURTH(stacks->a);
	if (a > b && a > c && a > d)
		push_b(stacks);
	else if (b > a && b > c && b > d)
		exec_operations(stacks, "sa\npb\n");
	else if (c > a && c > b && c > d)
		exec_operations(stacks, "ra\nsa\npb\nrra\n");
	sort_right_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a));
	exec_operations(stacks, "pa\nras\n");
}

void		sort_right(t_stacks *stacks, t_avltree *avl)
{
	int	size;

	size = 1 + ft_avltcount(avl->right);
	if (size == 1)
		rotate_a_sorted(stacks);
	else if (size == 2 && (FIRST(stacks->a) > SECOND(stacks->a)))
		exec_operations(stacks, "sa\nras\nras\n");
	else if (size == 2)
		exec_operations(stacks, "ras\nras\n");
	else if (size == 3)
		return (sort_right_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a)));
	else if (size == 4)
		return (sort_right_4(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a)));
}
