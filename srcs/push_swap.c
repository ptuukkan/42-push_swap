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

void		print_stack(t_list *stack)
{
	int	nb;

	while (stack != NULL)
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
	t_stacks	copy;
	int			size;
	char		*op;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	copy.a = NULL;
	copy.b = NULL;
	copy.oplist = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	if (!init_stack(argv + 1, &copy.a))
		return (print_error());
	if (check_order(stacks.a))
		return (0);
	size = ft_lstcount(stacks.a);
	if (size <= 3)
		sort_small_a(&stacks, size);
	else
		sort_stack(&stacks);
	//printf("%d\n", ft_lstcount(stacks.oplist));
	op = optimize(stacks.oplist);
	//(void)op;
	ft_putstr(op);
	//visualize(stacks.oplist, &copy);
	return (0);
}
