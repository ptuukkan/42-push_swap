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

void	sort_small_3(t_stacks *stacks, int a, int b, int c)
{
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

void	sort_small(t_stacks *stacks)
{
	int	size;

	size = ft_twlstcount(stacks->a);
	if (size == 2 && FIRST(stacks->a) > SECOND(stacks->a))
		swap_a(stacks);
	else if (size == 3)
		return sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
				THIRD(stacks->a));
}
