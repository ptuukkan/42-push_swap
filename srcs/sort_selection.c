/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_selection(t_list *stack_a, t_list *stack_b, t_list **operations, size_t n)
{
	size_t	i;

	while (stack_a)
	{
		i = 0;
		push(&stack_a, &stack_b);
		n--;
		ft_lstapp(operations, ft_lstnew("pb", 3));
		while (i < n)
		{
			if (*(int *)stack_a->content < *(int *)stack_b->content)
			{
				push(&stack_a, &stack_b);
				ft_lstapp(operations, ft_lstnew("pb", 3));
				swap(&stack_b);
				ft_lstapp(operations, ft_lstnew("sb", 3));
				push(&stack_b, &stack_a);
				ft_lstapp(operations, ft_lstnew("pa", 3));
			}
			rotate(&stack_a);
			ft_lstapp(operations, ft_lstnew("ra", 3));
			i++;
		}
	}
	while (stack_b)
	{
		push(&stack_b, &stack_a);
		ft_lstapp(operations, ft_lstnew("pa", 3));
	}
}
