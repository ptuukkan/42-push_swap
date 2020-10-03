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

static int	read_ops(t_stacks *stacks)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) && *line != '\0')
	{
		if (!exec_operation(line, stacks))
			return (0);
		if (line)
			ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.oplist = NULL;
	if (argc == 1)
		return (1);
	if (!init_stack(argv + 1, &stacks.a))
		return (print_error());
	if (!read_ops(&stacks))
		return (print_error());
	if (!check_order(stacks.a) || stacks.b != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_twlstdel(&stacks.a, &ft_lstfree);
	ft_twlstdel(&stacks.b, &ft_lstfree);
	ft_twlstdel(&stacks.oplist, &ft_lstfree);
	return (0);
}
