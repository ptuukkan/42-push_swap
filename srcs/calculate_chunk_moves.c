/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_chunk_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_forward(t_twlist *lst, t_chunk *chunk)
{
	int	moves;
	int	remaining;

	moves = 0;
	remaining = chunk->size;
	while (remaining > 0)
	{
		while (!in_chunk(FIRST(lst), chunk))
		{
			lst = lst->next;
			moves++;
		}
		lst = lst->next;
		moves++;
		remaining--;
	}
	return (moves);
}

static int	calc_reverse(t_twlist *lst, t_chunk *chunk)
{
	int	moves;
	int	remaining;

	moves = 0;
	remaining = chunk->size;
	while (remaining > 0)
	{
		while (!in_chunk(FIRST(lst), chunk))
		{
			lst = lst->prev;
			moves++;
		}
		lst = lst->prev;
		moves += 2;
		remaining--;
	}
	return (moves);
}

static int	is_found(int x, t_list *found)
{
	while (found)
	{
		if (x == FIRST(found))
			return (1);
		found = found->next;
	}
	return (0);
}

static int	find_nearest(t_twlist *lst, t_chunk *chunk, t_list *found)
{
	int			fwd;
	int			rev;
	t_twlist	*tmp;
	int			f;

	fwd = 0;
	rev = 0;
	tmp = lst;
	f = 0;
	while (!in_chunk(FIRST(lst), chunk) || (f = is_found(FIRST(lst), found)))
	{
		//ft_printf("%d\n", FIRST(lst));
		if (!f)
			fwd++;
		lst = lst->next;
	}
	f = 0;
	while (!in_chunk(FIRST(tmp), chunk) || (f = is_found(FIRST(tmp), found)))
	{
		//ft_printf("%d\n", FIRST(tmp));
		if (!f)
			rev--;
		tmp = tmp->prev;
	}
	if (-rev < fwd)
		return (rev);
	return (fwd);
}

static int	calc_nearest(t_twlist *lst, t_chunk *chunk)
{
	int		moves;
	int		remaining;
	int		nearest;
	t_list	*found;

	moves = 0;
	remaining = chunk->size;
	found = NULL;
	while (remaining > 0)
	{
		nearest = find_nearest(lst, chunk, found);
		if (nearest > 0)
			moves += nearest;
		else
			moves += -nearest;
		while (nearest > 0)
		{
			if (!is_found(FIRST(lst), found))
				nearest--;
			lst = lst->next;
		}
		while (nearest < 0)
		{
			if (!is_found(FIRST(lst), found))
				nearest++;
			lst = lst->prev;
		}
		moves++;
		ft_lstapp(&found, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
		remaining--;
	}
	return (moves);
}

int	calc_chunk_moves(t_twlist *lst, t_chunk *chunk)
{
	int	fwd;
	int	rev;
	int	nearest;

	fwd = calc_forward(lst, chunk);
	rev = calc_reverse(lst, chunk);
	nearest = calc_nearest(lst, chunk);
	//ft_printf("fwd: %d, rev: %d, nearest: %d\n", fwd, rev, nearest);
	if (nearest < fwd && nearest < rev)
		return (3);
	if (rev < fwd && rev < nearest)
		return (2);
	return (1);
}
