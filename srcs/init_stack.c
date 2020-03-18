/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_duplicate(t_twlist *stack_a, int nb)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (nb == FIRST(stack_a))
			i++;
		stack_a = stack_a->next;
	}
	if (i != 1)
		return (0);
	return (1);
}

static int	check_digits(char *str)
{
	if (*str == '-')
		str++;
	while(*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

static int	check_multiple(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == ' ' && ft_isdigit(*(str + 1)) == 1)
			i++;
		str++;
	}
	return (i);
}

int			init_stack(char **argv, t_twlist **stack_a)
{
	long long	lnb;
	int			nb;

	if (check_multiple(*argv))
		argv = ft_strsplit(*argv, ' ');
	while (*argv)
	{
		if (!check_digits(*argv))
			return (0);
		lnb = atoll(*argv);
		if (lnb > 2147483647 || lnb < -2147483648)
			return (0);
		nb = (int)lnb;
		ft_twlstapp(stack_a, ft_twlstnew(&nb, sizeof(nb)));
		if (!check_duplicate(*stack_a, nb))
			return (0);
		argv++;
	}
	ft_twlstconnect(*stack_a);
	return (1);
}
