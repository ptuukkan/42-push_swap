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
	}
	if (!check_order(stacks.a) || stacks.b != NULL)
	{
		ft_printf("KO\n");
		return (1);
	}
	ft_printf("OK\n");
	return (0);
}
