/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdint.h>

# define FIRST(x) *(int *)x->content
# define SECOND(x) *(int *)x->next->content
# define THIRD(x) *(int *)x->next->next->content

typedef struct		s_stacks
{
	t_twlist	*a;
	t_twlist	*b;
	t_list		*oplist;
	int			highest;
}					t_stacks;

int		init_stack(char **argv, t_twlist **stack_a);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_ab(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_a_sorted(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_ab(t_stacks *stacks);
int		check_order(t_twlist *stack);
int		check_empty(t_twlist *stack);
int		exec_operation(char *instruction, t_stacks *stacks);
int		print_error(void);
void	print_operations(t_list *operations);
void	print_stack(t_twlist *stack);
int		sort_quick(t_stacks *stacks, int chunk);
int		*array_quicksort(t_twlist *lst, int size);
int		get_median(t_twlist *stack, int size);
int		get_next_over(t_twlist *stack, int pivot, int size);
int		get_next_under(t_twlist *stack, int pivot, int size, int highest);
int		push_under_pivot(t_stacks *stacks, int size);
int		push_over_pivot(t_stacks *stacks);
void	sort_stack(t_stacks *stacks);
char	*optimize(t_list *oplist);
void	exec_operations(t_stacks *stacks, char *ops);
void	sort_small_a(t_stacks *stacks, int size);
void	sort_small_b(t_stacks *stacks, int size);
void	print_stacks(t_stacks *stacks);

#endif
