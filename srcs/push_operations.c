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
	if (!stacks->a->prev && !stacks->a->end)
		ft_twlstconnect(stacks->a);
	ft_lstapp(&stacks->oplist, ft_lstnew("pa\n", 4));
}

void	push_b(t_stacks *stacks)
{
	t_twlist	*temp;

	if (stacks->a == NULL)
		return;
	temp = ft_twlstdetach(&stacks->a);
	ft_twlstadd(&stacks->b, temp);
	if (!stacks->b->prev && !stacks->b->end)
		ft_twlstconnect(stacks->b);
	ft_lstapp(&stacks->oplist, ft_lstnew("pb\n", 4));
}
