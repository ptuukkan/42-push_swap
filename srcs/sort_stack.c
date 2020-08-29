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

void	sort_stack(t_stacks *stacks, t_avltree *avl)
{
	//ft_printf("root: %d\n", ROOT(avl));
//	print_stacks(stacks);
	if (ft_avltheight(avl) < 3)
	{
		//ft_printf("return\n");
		return ;
	}
	if (!stacks->b)
	{
		//ft_printf("B is empty, moving stuff to B\n");
		move_to_b(stacks, ROOT(avl));
		//print_stacks(stacks);
	}
	else if (ft_avltheight(avl) > 2)
	{
		//ft_printf("move stuff to A\n");
		move_to_a(stacks, ROOT(avl));
		//print_stacks(stacks);
	}
//	ft_printf("go left\n");
	sort_stack(stacks, avl->left);
	if (ft_avltheight(avl) == 3)
	{
		//ft_printf("height is 3\n");
		//print_stacks(stacks);
		//ft_printf("sort left\n");
		sort_left(stacks, avl->left);
	//	print_stacks(stacks);
		//ft_printf("sort right\n");
		sort_right(stacks, avl);
		//print_stacks(stacks);
	}
	else if (ft_avltheight(avl) == 4)
	{
		if (ft_avltheight(avl->left) == 2)
		{
			//ft_printf("height is 4\n");
		//	print_stacks(stacks);
			//ft_printf("sort left\n");
			sort_left(stacks, avl->left);
			//print_stacks(stacks);
		}

		if (ft_avltheight(avl->right) == 2)
		{
			//ft_printf("height is 4\n");
			//print_stacks(stacks);
			//ft_printf("sort right\n");
			sort_right(stacks, avl);
			//print_stacks(stacks);
		}

	}
	//ft_printf("go right\n");
	sort_stack(stacks, avl->right);
	//ft_printf("return\n");
}
