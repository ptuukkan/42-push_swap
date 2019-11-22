/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                   ....                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static double	get_average(t_list *stack, int size)
{
	double	avg;

	avg = 0;
	while (stack)
	{
		avg += (double)*(int *)stack->content;
		stack = stack->next;
	}
	avg = avg / (double)size;
	return (avg);
}

static int		get_median(t_list *stack, int size)
{
	int		avg;
	int		diff;
	int		lastdiff;
	int		med;

	avg = (int)get_average(stack, size);
	med = *(int *)stack->content;
	if (*(int *)stack->content > avg)
		lastdiff = *(int *)stack->content - avg;
	else if (*(int *)stack->content < avg)
		lastdiff = avg - *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > avg)
			diff = *(int *)stack->content - avg;
		else if (*(int *)stack->content < avg)
			diff = avg - *(int *)stack->content;
		if (diff < lastdiff)
		{
			med = *(int *)stack->content;
			lastdiff = diff;
		}
		stack = stack->next;
	}
	return (med);
}

/*

static int		get_location(t_list *stack, int nb)
{
	int	i;

	i = 1;
	while (stack && *(int *)stack->content != nb)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
*/
static int		get_next_over(t_list *stack, int pivot, int size)
{
	int	i;
	int	i2;
	int	j;

	i = 0;
	i2 = 0;
	j = 1;
	while (stack)
	{
		if (*(int *)stack->content > pivot)
		{
			i = j;
			break ;
		}
		stack = stack->next;
		j++;
	}
	if (i > (size / 5 * 2))
	{
		while (stack)
		{
			if (*(int *)stack->content > pivot)
				i2 = j;
			stack = stack->next;
			j++;
		}
		if (size - i2 < i)
			return (i2);
	}
	return (i);
}

static int		get_next_under(t_list *stack, int pivot, int size)
{
	int	i;
	int	i2;
	int	j;

	i = 0;
	i2 = 0;
	j = 1;
	while (stack)
	{
		if (*(int *)stack->content < pivot)
		{
			i = j;
			break ;
		}
		stack = stack->next;
		j++;
	}
	if (i > (size / 5 * 2))
	{
		while (stack)
		{
			if (*(int *)stack->content < pivot)
				i2 = j;
			stack = stack->next;
			j++;
		}
		if (size - i2 < i)
			return (i2);
	}
	return (i);
}

int		get_stack_size(t_list *stack)
{
	int	i;
	int	sorted;

	i = 1;
	sorted = 0;
	while (stack->next)
	{
		i++;
		if (*(int *)stack->content < *(int *)stack->next->content)
			sorted++;
		else
			sorted--;
		stack = stack->next;
	}
	if (sorted > 0 && sorted + 1 == i)
		return (0);
	if (sorted < 0 && sorted * -1 + 1 == i)
		return (-1);
	return (i);
}

int	push_under_pivot(t_list **stack_from, t_list **stack_to)
{
	int	size;
	int	pivot;
	int	nextnb;

	size = get_stack_size(*stack_from);
	if (size == 0)
		return (1);
	pivot = get_median(*stack_from, size);
	while (size > 2 && (nextnb = get_next_under(*stack_from, pivot, size)) > 0)
	{
		while (*(int *)(*stack_from)->content > pivot)
		{
			if (nextnb <= size / 2)
				rotate(stack_from);
			else
				reverse_rotate(stack_from);
		}
		push(stack_from, stack_to);
		size--;
	}
	if (size == 2)
		return (0);
	return (1);
}

int	push_over_pivot(t_list **stack_from, t_list **stack_to)
{
	int	size;
	int	pivot;
	int	nextnb;

	size = get_stack_size(*stack_from);
	if (size == -1)
		return (-1);
	pivot = get_median(*stack_from, size);
	while (size > 2 && (nextnb = get_next_over(*stack_from, pivot, size)) > 0)
	{
		while (*(int *)(*stack_from)->content <= pivot)
		{
			if (nextnb <= size / 2)
				rotate(stack_from);
			else
				reverse_rotate(stack_from);
		}
		push(stack_from, stack_to);
		size--;
	}
	if (size == 2)
		return (0);
	return (1);
}

void	sort_quick(t_list **stack_a, t_list **stack_b, t_list **operations)
{	
	(void)operations;

	push_under_pivot(stack_a, stack_b);
	while (push_over_pivot(stack_b, stack_a))
	{
		printf("Stack A:\n");
		print_stack(*stack_a);
		printf("Stack B:\n");
		print_stack(*stack_b);
	}
	printf("Stack A:\n");
	print_stack(*stack_a);
	printf("Stack B:\n");
	print_stack(*stack_b);
}
