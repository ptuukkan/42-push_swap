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

/*

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
		if (*(int *)stack->content >= avg)
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
static int		get_median(t_list *stack, int size)
{
	int	*array;
	int	median;

	if (!(array = array_quicksort(stack, size)))
		exit(-1);
	median = array[size / 2];
	return (median);
}

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

int		check_sorted(t_list *stack, int sortdir)
{
	if (sortdir == 1)
	{
		while (stack->next)
		{
			if (*(int *)stack->content > *(int *)stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	else
	{
		while (stack->next)
		{
			if (*(int *)stack->content < *(int *)stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
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
	if (check_sorted(stacks->a, 1) == 1)
		return (-1);
	size = ft_lstcount(stacks->a);
	pivot = get_median(stacks->a, size);
	while ((nextnb = get_next_under(stacks->a, pivot, size)) > 0)
	{
		while (*(int *)stacks->a->content > pivot)
		{
			if (nextnb <= size / 2)
				rotate(stacks, 'a', 0);
			else
				reverse_rotate(stacks, 'a', 0);
		}
		push(stacks, 'b');
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
	if (check_sorted(stacks->b, -1) == 1)
		return (-1);
	size = ft_lstcount(stacks->b);
	pivot = get_median(stacks->b, size);
	while ((nextnb = get_next_over(stacks->b, pivot, size)) > 0)
	{
		while (*(int *)stacks->b->content < pivot)
		{
			if (nextnb <= size / 2)
				rotate(stacks, 'b', 0);
			else
				reverse_rotate(stacks, 'b', 0);
		}
		push(stacks, 'a');
		size--;
		i++;
	}
	return (i);
}

void	swap_stack(t_stacks *stacks, char stackchar)
{
	if (stackchar == 'a')
	{
		if (stacks->a->next == NULL)
			return ;
		if (*(int *)stacks->a->content > *(int *)stacks->a->next->content)
			swap(stacks, stackchar, 0);
	}
	else if (stackchar == 'b')
	{
		if (stacks->b->next == NULL)
			return ;
		if (*(int *)stacks->b->content < *(int *)stacks->b->next->content)
			swap(stacks, stackchar, 0);
	}
}


void	stack_quicksort(t_stacks *stacks, int chunk, int size)
{
	int	i;

	if (size < 3)
	{
		swap_stack(stacks, 'b');
		while (stacks->b)
			push(stacks, 'a');
		while (size-- > 0)
			rotate(stacks, 'a', 0);
		if (chunk == 1)
			rotate(stacks, 'a', 0);
		if (chunk == 2)
		{
			swap_stack(stacks, 'a');
			rotate(stacks, 'a', 0);
			rotate(stacks, 'a', 0);
		}
		return ;
	}
	stack_quicksort(stacks, push_over_pivot(stacks), ft_lstcount(stacks->b));
	if (size + chunk == ft_lstcount(stacks->a))
		i = size;
	else
		i = chunk;
	while (i-- > 0)
		push(stacks, 'b');
	stack_quicksort(stacks, push_over_pivot(stacks), ft_lstcount(stacks->b));
}


void	sort_quick(t_stacks *stacks)
{
	int	chunk;

	chunk = push_under_pivot(stacks);
	if (chunk > 0)
		stack_quicksort(stacks, chunk, ft_lstcount(stacks->a));

}

