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
	int		size_a = ft_lstcount(stacks->a);
	int		size_b = ft_lstcount(stacks->b);
	t_list	*lst_a = stacks->a;
	t_list	*lst_b = stacks->b;
	int		size = size_a > size_b ? size_a : size_b;
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

int		get_median(t_list *stack, int size)
{
	int	*array;
	int	median;

	if (!(array = array_quicksort(stack, size)))
		exit(-1);
	median = array[size / 2];
	return (median);
}

int		get_next_over(t_list *stack, int pivot, int size)
{
	int	first;
	int	last;
	int	i;

	first = 0;
	last = 0;
	i = 1;
	while (stack)
	{
		if (FIRST(stack) >= pivot)
		{
			if (first == 0)
				first = i;
			last = i;
		}
		stack = stack->next;
		i++;
	}
	if (first <= (size - last))
		return (first);
	return (last);
}

int		get_next_under(t_list *stack, int pivot, int size)
{
	int	first;
	int	last;
	int	i;

	first = 0;
	last = 0;
	i = 1;
	while (stack)
	{
		if (FIRST(stack) <= pivot)
		{
			if (first == 0)
				first = i;
			last = i;
		}
		stack = stack->next;
		i++;
	}
	if (first <= (size - last))
		return (first);
	return (last);
}

int		check_sorted(t_list *stack, int reverse)
{
	if (reverse == 0)
	{
		while (stack->next)
		{
			if (FIRST(stack) > SECOND(stack))
				return (0);
			stack = stack->next;
		}
	}
	else
	{
		while (stack->next)
		{
			if (FIRST(stack) < SECOND(stack))
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

void	maybe_swap(t_stacks *stacks)
{
	if (ft_lstcount(stacks->a) >= 2)
	{
		if (FIRST(stacks->a) > SECOND(stacks->a))
			swap_a(stacks);
	}
	if (ft_lstcount(stacks->b) >= 2)
	{
		if (FIRST(stacks->b) < SECOND(stacks->b))
			swap_b(stacks);
	}
}

int	push_under_pivot(t_stacks *stacks)
{
	int	pivot;
	int	nextnb;
	int	i;
	int	size;

	i = 0;
	if (stacks->a == NULL)
		return (0);
//	if (check_sorted(stacks->a, 0) == 1)
//		return (-1);
	size = ft_lstcount(stacks->a);
	pivot = get_median(stacks->a, size);
	while ((nextnb = get_next_under(stacks->a, pivot, size)) > 0)
	{
		while (FIRST(stacks->a) > pivot)
		{
			if (nextnb <= size / 2)
				rotate_a(stacks);
			else
				reverse_rotate_a(stacks);
		}
		push_b(stacks);
		//maybe_swap(stacks);
		i++;
		size--;
	}
	return (i);
}

int	push_over_pivot(t_stacks *stacks)
{
	int	pivot;
	int	nextnb;
	int	i;
	int	size;

	i = 0;
	if (stacks->b == NULL)
		return (0);
//	if (check_sorted(stacks->b, 1) == 1)
//		return (-1);
	size = ft_lstcount(stacks->b);
	pivot = get_median(stacks->b, size);
	while ((nextnb = get_next_over(stacks->b, pivot, size)) > 0)
	{
		while (FIRST(stacks->b) < pivot)
		{
			if (nextnb <= size / 2)
				rotate_b(stacks);
			else
				reverse_rotate_b(stacks);
		}
		push_a(stacks);
		//maybe_swap(stacks);
		size--;
		i++;
	}
	return (i);
}

void	sort_stack_b(t_stacks *stacks, int size)
{
	int	chunk;
	//print_stacks(stacks);
	if (size <= 3)
	{
		return (sort_small_b(stacks, size));
	}
	chunk = push_over_pivot(stacks);
	sort_stack_b(stacks, size - chunk);
	//print_stacks(stacks);
	while (chunk--)
		push_b(stacks);
	sort_stack_b(stacks, ft_lstcount(stacks->b));

}

void	sort_stack(t_stacks *stacks)
{
	int	chunk;
	int	size;
	int	i;

	size = ft_lstcount(stacks->a);
	//print_stacks(stacks);

	chunk = push_under_pivot(stacks);

	sort_stack_b(stacks, chunk);

	i = 0;
	//print_stacks(stacks);
	while (i + chunk < size)
	{
		push_b(stacks);
		i++;
	}
	sort_stack_b(stacks, i);
	/*
	if ((size - chunk) <= 3)
	{
		sort_small_a(stacks, size - chunk);
		while (chunk++ < size)
			rotate_a(stacks);
	}
	else
	{
		while (i + chunk < size)
		{
			push_b(stacks);
			i++;
		}

		sort_stack_b(stacks, i);

	}
	*/

	//print_stacks(stacks);
}
