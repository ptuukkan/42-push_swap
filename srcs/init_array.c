/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	populate_array(int *numbers, t_twlist *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		numbers[i] = FIRST(lst);
		if (lst->end)
			break ;
		lst = lst->next;
		i++;
	}
}

static void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_array(int *array, int size)
{
	int	pivot;
	int	begin;
	int	end;

	if (size < 2)
		return ;
	if (size == 2)
		if (array[0] < array[1])
			return ;
	pivot = array[size / 2];
	begin = 0;
	end = size - 1;
	while (begin < end)
	{
		while (begin < size && array[begin] < pivot)
			begin++;
		while (end >= 0 && array[end] > pivot)
			end--;
		if (begin < end)
			swap(&array[begin++], &array[end--]);
	}
	sort_array(array, end + 1);
	sort_array(array + begin, size - begin);
}

int			*init_array(t_twlist *lst, int size)
{
	int	*numbers;

	numbers = NULL;
	if (!(numbers = (int *)ft_memalloc(sizeof(int) * size)))
		return (NULL);
	populate_array(numbers, lst);
	sort_array(numbers, size);
	return (numbers);
}
