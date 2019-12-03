/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_lsttoarray(t_list *lst, int size)
{
	static int	*array;
	int			i;

	i = 0;
	if (lst == NULL)
		return (NULL);
	if (!(array = (int *)ft_memalloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		array[i] = *(int *)lst->content;
		i++;
		lst = lst->next;
	}
	return (array);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_quicksort(int *array, int size)
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
		{
			ft_swap(&array[begin], &array[end]);
			begin++;
			end--;
		}
	}
	ft_quicksort(array, end + 1);
	ft_quicksort(array + begin, size - begin);
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int		*array_quicksort(t_list *lst, int size)
{
	int	*array;

	if (!(array = ft_lsttoarray(lst, size)))
		return (NULL);
	ft_quicksort(array, size);
	return (array);
}
