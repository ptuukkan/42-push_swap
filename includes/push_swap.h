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

typedef struct		s_stacks
{
	t_list	*a;
	t_list	*b;
	t_list	*oplist;
}					t_stacks;

int		init_stack(char **argv, t_list **stack_a);
void	swap(t_stacks *stacks, char stackchar, int both);
void	swap_ab(t_stacks *stacks);
void	push(t_stacks *stacks, char stackchar);
void	rotate(t_stacks *stacks, char stackchar, int both);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate(t_stacks *stacks, char stackchar, int both);
void	reverse_rotate_ab(t_stacks *stacks);
int		check_order(t_list *stack);
int		check_empty(t_list *stack);
int		exec_operation(char *instruction, t_stacks *stacks);
int		print_error(void);
void	sort_selection(t_list *stack_a, t_list *stack_b, t_list **operations, size_t n);
void	print_operations(t_list *operations);
void	print_stack(t_list *stack);
void	sort_quick(t_stacks *stacks);
int		ft_lstcount(t_list *lst);
int		*array_quicksort(t_list *lst, int size);

#endif
