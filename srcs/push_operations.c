/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	t_twlist	*temp;

	if (stacks->b == NULL)
		return;
	temp = ft_twlstdetach(&stacks->b);
	ft_twlstadd(&stacks->a, temp);
	append_op(&stacks->oplist, "pa\n");
}

void	push_b(t_stacks *stacks)
{
	t_twlist	*temp;

	if (stacks->a == NULL)
		return;
	temp = ft_twlstdetach(&stacks->a);
	ft_twlstadd(&stacks->b, temp);
	append_op(&stacks->oplist, "pb\n");
}
