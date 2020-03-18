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

int		get_median(t_twlist *stack, int size)
{
	int	*array;
	int	median;

	if (!(array = array_quicksort(stack, size)))
		exit(-1);
	median = array[size / 2];
	return (median);
}

int		get_next_over(t_twlist *stack, int pivot, int size)
{
	int			first;
	int			last;
	t_twlist	*tmp;

	first = 0;
	last = 1;
	tmp = stack->prev;
	while (first++ < size && FIRST(stack) < pivot)
		stack = stack->next;
	if (first > size)
		return (-1);
	while (last++ < first && FIRST(tmp) < pivot)
		tmp = tmp->prev;
	if (last < first)
		return (size - last);
	return (first);
}

int		get_next_under(t_twlist *stack, int pivot, int size, int highest)
{
	int			first;
	int			last;
	t_twlist	*tmp;

	first = 0;
	last = 1;
	tmp = stack->prev;
	while (first++ < size && (FIRST(stack) > pivot || FIRST(stack) <= highest))
		stack = stack->next;
	if (first > size)
		return (-1);
	while (last++ < first && (FIRST(tmp) > pivot || FIRST(tmp) <= highest))
		tmp = tmp->prev;
	if (last < first)
		return (size - last);
	return (first);
}

int		check_sorted(t_twlist *stack, int reverse)
{
	if (reverse == 0)
	{
		while (!stack->next->end)
		{
			if (FIRST(stack) > SECOND(stack))
				return (0);
			stack = stack->next;
		}
	}
	else
	{
		while (!stack->next->end)
		{
			if (FIRST(stack) < SECOND(stack))
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int		push_to_b(t_stacks *stacks, int size, t_twlist *a)
{
	if (size > 3)
		return (push_under_pivot(stacks, size));
	if (size == 1)
		rotate_a_sorted(stacks);
	if (size == 2 && FIRST(a) > SECOND(a))
		swap_a(stacks);
	if (size == 2)
		exec_operations(stacks, "ras\nras\n");
	if (size == 1 || size == 2)
		return (0);
	if (THIRD(a) < FIRST(a) && THIRD(a) < SECOND(a))
	{
		if (SECOND(a) < FIRST(a))
			exec_operations(stacks, "pb\nsa\nras\nras\npa\nras\n");
		else
			exec_operations(stacks, "pb\nsa\nras\npa\nras\nras\n");
		return (0);
	}
	if (SECOND(a) < FIRST(a) && SECOND(a) < THIRD(a))
		swap_a(stacks);
	if (SECOND(stacks->a) > THIRD(stacks->a))
		exec_operations(stacks, "ras\nsa\nra\nras\n");
	else
		exec_operations(stacks, "ras\nras\nras\n");
	return (0);
}

void	prepare_a(t_stacks *stacks, t_twlist *a, int pivot)
{
	int	i;
	int	size;

	i = 0;
	size = ft_twlstcount(stacks->a);
	while (FIRST(a) > pivot && i++ != -1 && !a->end)
		a = a->next;
	while (FIRST(a) < pivot && i++ != -1 && !a->end)
		a = a->next;
	if (i > size)
		return ;
	if (i < (size / 2))
	{
		while (i--)
			rotate_a(stacks);
	}
	else
	{
		while (i++ < size)
			reverse_rotate_a(stacks);
	}
}

int		push_under_pivot(t_stacks *stacks, int size)
{
	int	pivot;
	int	nextnb;
	int	i;
	int	highest;
	//int	smallest;

	i = 0;
	if (stacks->a == NULL)
		return (0);
	pivot = get_median(stacks->a, size);
	size = ft_twlstcount(stacks->a);
	highest = stacks->highest;
	//smallest = INT32_MAX;
	while ((nextnb = get_next_under(stacks->a, pivot, size, stacks->highest)) != -1)
	{
		while (FIRST(stacks->a) > pivot || FIRST(stacks->a) < stacks->highest)
		{
			if (nextnb <= size / 2)
				rotate_a(stacks);
			else
				reverse_rotate_a(stacks);
		}
		if (FIRST(stacks->a) > highest)
			highest = FIRST(stacks->a);
	//	if (FIRST(stacks->a) < smallest)
	//		smallest = FIRST(stacks->a);
		push_b(stacks);
		i++;
		size--;
	}
	//stacks->highest = highest;
	//if (i <= 7)
	prepare_a(stacks, stacks->a, pivot);
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
	size = ft_twlstcount(stacks->b);
	pivot = get_median(stacks->b, size);
	while ((nextnb = get_next_over(stacks->b, pivot, size)) != -1)
	{
		while (FIRST(stacks->b) < pivot)
		{
			if (nextnb <= size / 2)
				rotate_b(stacks);
			else
				reverse_rotate_b(stacks);
		}
		push_a(stacks);
		size--;
		i++;
	}
	return (i);
}

void	sort_stack_b(t_stacks *stacks, int size)
{
	int	chunk;
	if (size <= 3)
	{
		return (sort_small_b(stacks, size));
	}
	chunk = push_over_pivot(stacks);
	sort_stack_b(stacks, size - chunk);
	size = chunk;
	while (chunk != 0)
	{
		chunk = push_to_b(stacks, size, stacks->a);
		if (chunk != 0)
			sort_stack_b(stacks, ft_twlstcount(stacks->b));
		size -= chunk;
	}
}

void	sort_stack(t_stacks *stacks)
{
	int	chunk;
	int	size;

	size = ft_twlstcount(stacks->a);
	stacks->highest = INT32_MIN;
	chunk = 1;
	while (chunk != 0)
	{
		chunk = push_to_b(stacks, size, stacks->a);
		if (chunk != 0)
			sort_stack_b(stacks, chunk);
		size -= chunk;
	}
}
