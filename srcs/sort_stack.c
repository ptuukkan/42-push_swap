/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int			size_a = ft_twlstcount(stacks->a);
	int			size_b = ft_twlstcount(stacks->b);
	t_twlist	*lst_a = stacks->a;
	t_twlist	*lst_b = stacks->b;
	int			size = size_a > size_b ? size_a : size_b;
	printf("Stack A    Stack B\n");
	while (size)
	{
		if (size_a)
		{
			printf("%2d", FIRST(lst_a));
			size_a--;
			lst_a = lst_a->next;
		}
		else
			printf("  ");
		if (size_b)
		{
			printf("%10d\n", FIRST(lst_b));
			size_b--;
			lst_b = lst_b->next;
		}
		else
			printf("  \n");
		size--;
	}
}

void	print_numbers(t_list *numbers)
{
	while (numbers)
	{
		ft_printf("%d ", *(int *)numbers->content);
		numbers = numbers->next;
	}
	ft_printf("\n");
}

static void	sort_chunk(t_stacks *stacks, t_btree *chunks)
{
	if (!chunks)
		return ;
	if (stacks->b && chunks->right)
		move_to_a(stacks, chunks->right->content);
	else if (!stacks->b && chunks->left)
		move_to_b(stacks, chunks->left->content);
	sort_chunk(stacks, chunks->left);
	if (((t_chunk *)chunks->content)->size < 4)
		sort(stacks, chunks->content);
	sort_chunk(stacks, chunks->right);
}

void		sort_stack(t_stacks *stacks, int size)
{
	int	i;

	(void)size;
	i = 0;
	if (check_order(stacks->a))
		return ;
	while (stacks->chunks[i])
	{
		move_to_b(stacks, stacks->chunks[i]->content);
		sort_chunk(stacks, stacks->chunks[i]);
		i++;
	}
}
