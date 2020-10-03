/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitiess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int		in_chunk(int x, t_chunk *chunk)
{
	if (x >= chunk->low && x <= chunk->high)
		return (1);
	return (0);
}

void	new_last_sorted(t_stacks *stacks, int x)
{
	if (stacks->last_sorted == NULL)
		stacks->last_sorted = (int *)ft_memdup(&x, stacks->a->content_size);
	else if (x > *stacks->last_sorted)
		ft_memcpy(stacks->last_sorted, &x, stacks->a->content_size);
}

int		find_nearest_in_chunk(t_twlist *lst, t_chunk *chunk)
{
	int			fwd;
	int			rev;
	t_twlist	*tmp;

	fwd = 0;
	rev = 0;
	tmp = lst;
	while (!in_chunk(first(lst), chunk))
	{
		fwd++;
		lst = lst->next;
	}
	while (!in_chunk(first(tmp), chunk))
	{
		rev--;
		tmp = tmp->prev;
	}
	if (-rev < fwd)
		return (rev);
	return (fwd);
}

int		find_x(t_twlist *lst, int x)
{
	int			fwd;
	int			rev;
	t_twlist	*tmp;

	fwd = 0;
	rev = 0;
	tmp = lst;
	while (first(lst) != x)
	{
		fwd++;
		lst = lst->next;
	}
	while (first(tmp) != x)
	{
		rev--;
		tmp = tmp->prev;
	}
	if (-rev < fwd)
		return (rev);
	return (fwd);
}
