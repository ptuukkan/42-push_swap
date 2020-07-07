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


void	print_operations(t_list *operations)
{
	while (operations)
	{
		ft_putstr((char *)operations->content);
		operations = operations->next;
	}
}

void		print_stack(t_twlist *stack)
{
	int	nb;

	while (stack->end == 0)
	{
		nb = *(int *)stack->content;
		printf("%d\n", nb);
		stack = stack->next;
	}
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
	int			size;
	char		*op;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	sort_stack(&stacks);
	print_operations(&stacks.oplist);
	return (0);
}
