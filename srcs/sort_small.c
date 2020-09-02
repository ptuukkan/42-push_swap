/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small_3(t_stacks *stacks, int a, int b, int c)
{
		if (a < b && a < c && b > c)
			exec_operations(stacks, "rra\nsa\n");
		else if (a > b && a < c && b < c)
			swap_a(stacks);
		else if (a < b && a > c && b > c)
			reverse_rotate_a(stacks);
		else if (a > b && a > c && b < c)
			rotate_a(stacks);
		else if (a > b && a > c && b > c)
			exec_operations(stacks, "ra\nsa\n");
}

static int	get_position(t_twlist *lst, int x, int low, int high)
{
	int	i;
	int	size;

	i = 0;
	size = ft_twlstcount(lst);
	if (x > high || x < low)
	{
		while (FIRST(lst) > PREV(lst))
		{
			i++;
			lst = lst->next;
		}
	}
	else
	{
		while (!(PREV(lst) < x && FIRST(lst) > x))
		{
			i++;
			lst = lst->next;
		}
	}
	if (i == 2 && size == 3)
		return (-1);
	return (i);
}

static void	finish_rotate(t_stacks *stacks)
{
	int			i;
	t_twlist	*lst;
	int			size;

	i = 0;
	lst = stacks->a;
	size = ft_twlstcount(stacks->a);
	while (FIRST(lst) > *(int *)lst->prev->content)
	{
		lst = lst->next;
		i++;
	}
	if (i >= 3)
		i = -(size - i);
	while (i > 0)
	{
		exec_operations(stacks, "ra\n");
		i--;
	}
	while (i < 0)
	{
		exec_operations(stacks, "rra\n");
		i++;
	}
}

static void	return_b(t_stacks *stacks)
{
	int	position;
	int	low;
	int	high;

	low = FIRST(stacks->a);
	high = PREV(stacks->a);
	while (stacks->b)
	{
		position = get_position(stacks->a, FIRST(stacks->b), low, high);
		while (position > 0)
		{
			exec_operations(stacks, "ra\n");
			position--;
		}
		while (position < 0)
		{
			exec_operations(stacks, "rra\n");
			position++;
		}
		exec_operations(stacks, "pa\n");
		if (FIRST(stacks->a) < low)
			low = FIRST(stacks->a);
		else if (FIRST(stacks->a) > high)
			high = FIRST(stacks->a);
	}
	finish_rotate(stacks);
}

void		sort_small(t_stacks *stacks, int size)
{
	if (size == 2 && FIRST(stacks->a) > SECOND(stacks->a))
		exec_operations(stacks, "sa\n");
	else if (size == 3)
		return (sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
			THIRD(stacks->a)));
	else if (size == 4)
	{
		exec_operations(stacks, "pb\n");
		sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
			THIRD(stacks->a));
		return_b(stacks);
	}
	else if (size == 5)
	{
		exec_operations(stacks, "pb\npb\n");
		sort_small_3(stacks, FIRST(stacks->a), SECOND(stacks->a),
			THIRD(stacks->a));
		return_b(stacks);
	}
}
