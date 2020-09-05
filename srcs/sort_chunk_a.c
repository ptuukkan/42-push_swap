/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/08/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_nbrs	find_next(t_twlist *lst, t_chunk *chunk)
{
	t_twlist	*tmp;
	t_nbrs		numbers;

	tmp = lst;
	numbers.moves_fwd = 0;
	numbers.moves_rev = 0;
	while (!in_chunk(FIRST(lst), chunk))
	{
		lst = lst->next;
		numbers.moves_fwd++;
	}
	numbers.nb_fwd = FIRST(lst);
	while (!in_chunk(FIRST(tmp), chunk))
	{
		tmp = tmp->prev;
		numbers.moves_rev--;
	}
	numbers.nb_rev = FIRST(tmp);
	return (numbers);
}

static int	find_position(t_twlist *lst, int x, int max_moves, t_chunk *chunk)
{
	int			fwd;
	int			rev;
	t_twlist	*tmp;

	fwd = 0;
	rev = 0;
	tmp = lst;
	(void)max_moves;
	while (in_chunk(FIRST(lst), chunk) && FIRST(lst) < x)
	{
		lst = lst->next;
		fwd++;
	}
	while (in_chunk(PREV(tmp), chunk) && PREV(tmp) > x)
	{
		tmp = tmp->prev;
		rev++;
	}
	if (rev > fwd)
		return (-rev);
	return (fwd);
}

/*
static int	find_position(t_twlist *lst, int x, int max_moves, t_chunk *chunk)
{
	int			fwd;
	int			rev;
	t_twlist	*tmp;

	fwd = 0;
	rev = 0;
	tmp = lst;
	if (max_moves == 0)
		return (0);
	while (fwd <= max_moves && !(FIRST(tmp) > x && PREV(tmp) < x))
	{
		fwd++;
		tmp = tmp->next;
	}
	tmp = lst;
	while (rev <= max_moves && !(FIRST(tmp) > x && PREV(tmp) < x))
	{
		rev++;
		tmp = tmp->prev;
	}
	if (fwd > max_moves && rev > max_moves)
	{
		rev = 0;
		while (in_chunk(PREV(lst), chunk))
		{
			rev++;
			lst = lst->next;
		}
		return (-rev);
	}
	if (rev < fwd)
		return (-rev);
	return (fwd);
}
*/

static void	move_x_to_a(t_stacks *stacks, t_nbrs *numbers)
{
	if (ft_abs(numbers->pos_rev - numbers->moves_rev) <
		ft_abs(numbers->pos_fwd - numbers->moves_fwd))
	{
		ft_printf("moving %d\n", numbers->nb_rev);
		rotate_a(stacks, numbers->pos_rev);
		reverse_rotate_a(stacks, numbers->pos_rev);
		rotate_b(stacks, numbers->moves_rev);
		reverse_rotate_b(stacks, numbers->moves_rev);
	}
	else
	{
		ft_printf("moving %d\n", numbers->nb_fwd);
		rotate_a(stacks, numbers->pos_fwd);
		reverse_rotate_a(stacks, numbers->pos_fwd);
		rotate_b(stacks, numbers->moves_fwd);
		reverse_rotate_b(stacks, numbers->moves_fwd);
	}
	push_a(stacks);
}

void	sort_chunk_to_a(t_stacks *stacks, t_chunk *chunk)
{
	int		remaining;
	t_nbrs	numbers;

	remaining = chunk->size;
	while (remaining > 0)
	{
		numbers = find_next(stacks->b, chunk);
		numbers.pos_fwd = find_position(stacks->a, numbers.nb_fwd, chunk->size - remaining, chunk);
		numbers.pos_rev = find_position(stacks->a, numbers.nb_rev, chunk->size - remaining, chunk);
		ft_printf("nb_fwd: %d, moves_fwd: %d, pos_fwd: %d, nb_rev: %d, moves_rev: %d, pos_rev: %d\n",
			numbers.nb_fwd, numbers.moves_fwd, numbers.pos_fwd, numbers.nb_rev, numbers.moves_rev, numbers.pos_rev);
		print_stacks(stacks);
		move_x_to_a(stacks, &numbers);

		remaining--;
	}
	while (in_chunk(PREV(stacks->a), chunk))
	{
		reverse_rotate_a(stacks, -1);

	}

print_stacks(stacks);
}
