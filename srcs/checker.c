/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

int			main(int argc, char **argv)
{
	char		*line;
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	while (get_next_line(0, &line) && *line != '\0')
	{
		if (!exec_operation(line, &stacks))
			return (print_error());
		ft_strdel(&line);
		sleep(1);
		print_stacks(&stacks);
	}
	if (!check_order(stacks.a) || stacks.b != NULL)
	{
		ft_putstr("KO\n");
		return (0);
	}
	ft_putstr("OK\n");
	return (0);
}
