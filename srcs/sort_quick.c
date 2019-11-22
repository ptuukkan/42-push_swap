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

static double	get_average(t_list *stack, size_t n)
{
	double	avg;

	avg = 0;
	while (stack)
	{
		avg += (double)*(int *)stack->content;
		stack = stack->next;
	}
	printf("avg: %f\n", avg);
	avg = avg / (double)n;
	printf("avg: %f\n", avg);
	return (avg);
}

static int		get_median(t_list *stack, size_t n)
{
	double	avg;
	double	diff;
	double	lastdiff;
	int		med;

	avg = get_average(stack, n);
	med = *(int *)stack->content;
	if ((double)*(int *)stack->content > avg)
		lastdiff = (double)*(int *)stack->content - avg;
	else if ((double)*(int *)stack->content < avg)
		lastdiff = avg - (double)*(int *)stack->content;
	while (stack)
	{
		if ((double)*(int *)stack->content > avg)
			diff = (double)*(int *)stack->content - avg;
		else if ((double)*(int *)stack->content < avg)
			diff = avg - (double)*(int *)stack->content;
		if (diff < lastdiff)
			med = *(int *)stack->content;
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

static int		get_next(t_list *stack, int nb, size_t n)
{
	int	i;

	i = 1;
	while (stack && *(int *)stack->content > nb)
	{
		stack = stack->next;
		i++;
	}
	if (i > ((int)n / 5 * 2) && i < ((int)n / 5 * 3))
	{

	}
	return (i);
}

void	sort_quick(t_list *stack_a, t_list *stack_b, t_list **operations, size_t n)
{
	int	pivot;
	(void)stack_b;
	(void)operations;
	pivot = get_median(stack_a, n);
	printf("pivot: %d\n", pivot);
	printf("pivot location: %d\n", get_location(stack_a, pivot));

}
