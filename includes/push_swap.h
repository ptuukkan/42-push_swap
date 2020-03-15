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

# define FIRST(x) *(int *)x->content
# define SECOND(x) *(int *)x->next->content
# define THIRD(x) *(int *)x->next->next->content

typedef struct		s_stacks
{
	t_list	*a;
	t_list	*b;
	t_list	*oplist;
}					t_stacks;

typedef struct		s_info
{
	int	s_a;
	int	s_b;
	int	p_a;
	int	p_b;
}					t_info;

int		init_stack(char **argv, t_list **stack_a);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_ab(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_ab(t_stacks *stacks);
int		check_order(t_list *stack);
int		check_empty(t_list *stack);
int		exec_operation(char *instruction, t_stacks *stacks);
int		print_error(void);
void	sort_selection(t_list *stack_a, t_list *stack_b, t_list **operations, size_t n);
void	print_operations(t_list *operations);
void	print_stack(t_list *stack);
int		sort_quick(t_stacks *stacks, int chunk);
int		ft_lstcount(t_list *lst);
int		*array_quicksort(t_list *lst, int size);
int		get_median(t_list *stack, int size);
int		get_next_over(t_list *stack, int pivot, int size);
int		get_next_under(t_list *stack, int pivot, int size);
int		push_under_pivot(t_stacks *stacks);
int		push_over_pivot(t_stacks *stacks);
void	sort_stack(t_stacks *stacks);
char	*optimize(t_list *oplist);
void	exec_operations(t_stacks *stacks, char *ops);
void	sort_small_a(t_stacks *stacks, int size);
void	sort_small_b(t_stacks *stacks, int size);

#endif
