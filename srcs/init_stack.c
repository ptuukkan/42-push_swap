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

static int	duplicate_number(t_twlist *stack_a, int nb)
{
	while (stack_a)
	{
		if (nb == FIRST(stack_a))
			return (1);
		if (stack_a->end)
			break ;
		stack_a = stack_a->next;
	}
	return (0);
}

static int	check_digits(char *str)
{
	if (*str == '-')
		str++;
	while(*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	valid_number(char *number, long long *lnb, int *nb,
							t_twlist **stack_a)
{
	if (!check_digits(number))
		return (0);
	*lnb = ft_atoll(number);
	if (*lnb > 2147483647 || *lnb < -2147483648)
		return (0);
	*nb = (int)*lnb;
	if (duplicate_number(*stack_a, *nb))
		return (0);
	return (1);
}

int			init_stack(char **argv, t_twlist **stack_a)
{
	long long	lnb;
	int			nb;
	int			i;
	char		**numbers;

	while (*argv)
	{
		if (!(numbers = ft_strsplit(*argv, ' ')))
			return (0);
		i = 0;
		while (numbers[i])
		{
			if (!valid_number(numbers[i], &lnb, &nb, stack_a))
				return (0);
			ft_twlstapp(stack_a, ft_twlstnew(&nb, sizeof(nb)));
			i++;
		}
		ft_strarrdel(&numbers);
		argv++;
	}
	return (1);
}
