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

static int	find_nearest(t_twlist *lst, t_chunk *chunk,
						t_list *found, int *x_moves)
{
	int			moves[2];
	t_twlist	*tmp;

	moves[0] = 0;
	moves[1] = 0;
	tmp = lst;
	while (!in_chunk(FIRST(lst), chunk) || is_found(FIRST(lst), found))
	{
		lst = lst->next;
		if (!is_found(FIRST(lst), found))
			moves[0]++;
	}
	while (!in_chunk(FIRST(tmp), chunk) || is_found(FIRST(tmp), found))
	{
		tmp = tmp->prev;
		if (!is_found(FIRST(tmp), found))
			moves[1]--;
	}
	if (-moves[1] < moves[0])
	{
		*x_moves = moves[1];
		return (FIRST(tmp));
	}
	*x_moves = moves[0];
	return (FIRST(lst));
}

static int	calc_nearest(t_twlist *lst, t_chunk *chunk,
						t_list *found, int remaining)
{
	int		moves;
	int		x;
	int		x_moves;

	moves = 0;
	while (remaining > 0)
	{
		x = find_nearest(lst, chunk, found, &x_moves);
		if (x_moves > 0)
		{
			while (FIRST(lst) != x)
				lst = lst->next;
		}
		else
		{
			while (FIRST(lst) != x)
				lst = lst->prev;
			x_moves = -x_moves;
		}
		moves += x_moves + 1;
		ft_lstapp(&found, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
		remaining--;
	}
	return (moves);
}

int			calc_chunk_moves(t_twlist *lst, t_chunk *chunk)
{
	int		fwd;
	int		nearest;
	t_list	*found;

	found = NULL;
	fwd = calc_forward(lst, chunk);
	nearest = calc_nearest(lst, chunk, found, chunk->size);
	ft_lstdel(&found, &ft_lstfree);
	if (nearest < fwd)
		return (1);
	return (0);
}
