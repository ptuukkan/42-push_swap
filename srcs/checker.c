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

int			main(int argc, char **argv)
{
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stack_a))
		return (print_error());
	while (get_next_line(0, &line))
	{
		if (!exec_operation(line, &stack_a, &stack_b))
			return (print_error());
		ft_strdel(&line);
	}
	if (!check_order(stack_a))
	{
		printf("KO\n");
		return (0);
	}
	printf("OK\n");
	return (0);
}
