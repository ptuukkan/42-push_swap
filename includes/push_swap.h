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
# define FOURTH(x) *(int *)x->next->next->next->content
# define PREV(x) *(int *)x->prev->content
# define ROOT(x) *(int *)x->content
# define LEFT(x) *(int *)x->left->content
# define RIGHT(x) *(int *)x->right->content

typedef struct		s_nbrs
{
	int	nb_fwd;
	int	moves_fwd;
	int	pos_fwd;
	int	nb_rev;
	int	moves_rev;
	int pos_rev;
}					t_nbrs;

typedef struct		s_chunk
{
	int	low;
	int	high;
	int	size;
}					t_chunk;

typedef struct		s_stacks
{
	t_twlist	*a;
	t_twlist	*b;
	t_twlist	*oplist;
	t_btree		**chunks;
	int			*last_sorted;
}					t_stacks;

int		init_stack(char **argv, t_twlist **stack_a);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_ab(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks, int times);
void	rotate_a_sorted(t_stacks *stacks);
void	rotate_b(t_stacks *stacks, int times);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks, int times);
void	reverse_rotate_b(t_stacks *stacks, int times);
void	reverse_rotate_ab(t_stacks *stacks);
void	prepare_a(t_stacks *stacks);
int		check_order(t_twlist *stack);
int		exec_operation(char *instruction, t_stacks *stacks);
int		print_error(void);
void	print_operations(t_twlist *operations);
void	print_stack(t_twlist *stack);
void	exec_operations(t_stacks *stacks, char *ops);
void	print_stacks(t_stacks *stacks);
void	move_to_b(t_stacks *stacks, t_chunk *chunk);
void	move_to_a(t_stacks *stacks, t_chunk *chunk);
void	sort(t_stacks *stacks, t_chunk *chunk);
void	sort_small(t_stacks *stacks, int size);
void	sort_stack(t_stacks *stacks, int size);
void	append_op(t_twlist **oplist, char *op);
int		*init_array(t_twlist *lst, int size);
t_btree	**calculate_chunks(int *numbers, int size);
void	push_a_sort(t_stacks *stacks, t_chunk *chunk, int remaining);
void	move_chunk_to_b(t_stacks *stacks, t_chunk *chunk);
void	move_chunk_to_a(t_stacks *stacks, t_chunk *chunk);
int		in_chunk(int x, t_chunk *chunk);
int		calc_chunk_moves(t_twlist *lst, t_chunk *chunk);
int		find_nearest_in_chunk(t_twlist *lst, t_chunk *chunk);
void	sort_chunk_to_a(t_stacks *stacks, t_chunk *chunk);


#endif
