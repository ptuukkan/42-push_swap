/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:51:53 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:51:54 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <time.h>

t_avltree	*init_avl(t_twlist *stack)
{
	t_avltree	*avl;
	t_avltree	*new;

	avl = NULL;
	while(!stack->end)
	{
		if (!(new = ft_avltnew(stack->content, stack->content_size)))
			return (NULL);
		if (!(avl = ft_avltinsert(avl, new, &ft_numcmp)))
			return (NULL);
		stack = stack->next;
	}
	if (!(new = ft_avltnew(stack->content, stack->content_size)))
		return (NULL);
	if (!(avl = ft_avltinsert(avl, new, &ft_numcmp)))
		return (NULL);
	return (avl);
}

void		print_operations(t_list *operations)
{
	while (operations)
	{
		ft_putstr((char *)operations->content);
		operations = operations->next;
	}
}

void		print_stack(t_twlist *stack)
{
	while (stack->end == 0)
	{
		ft_printf("%d\n", FIRST(stack));
		stack = stack->next;
	}
	ft_printf("%d\n", FIRST(stack));
}


void	visualize(t_list *oplist, t_stacks *stacks)
{
//	char	*line;

	print_stacks(stacks);
	while (oplist)
	{
		//while (get_next_line(0, &line) && *line != '\0')
		//{
		//	if (*line == '\n')
		//		break ;
		//}
		printf("%s", (char*)oplist->content);
		exec_operation((char*)oplist->content, stacks);
		print_stacks(stacks);
		oplist = oplist->next;
	}
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	t_avltree	*avl;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	avl = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	//print_stack(stacks.a);
	if (!(avl = init_avl(stacks.a)))
		return (print_error());
//	sort_stack(&stacks);
//	print_operations(stacks.oplist);
	ft_avltprint(avl, avl->height);
	return (0);
}
