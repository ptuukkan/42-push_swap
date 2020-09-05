/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:47:57 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/21 10:47:59 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_btree	*new_chunk(int low, int high, int size)
{
	t_chunk	*chunk;
	t_btree	*node;

	chunk = NULL;
	if (!(chunk = (t_chunk *)ft_memalloc(sizeof(t_chunk))))
		return (NULL);
	chunk->low = low;
	chunk->high = high;
	chunk->size = size;
	if (!(node = ft_btreenew(NULL, 0)))
		return (NULL);
	node->content = chunk;
	node->content_size = sizeof(t_chunk);
	return (node);
}

static t_btree	*calculate_chunk(int *numbers, t_btree *chunks, int size)
{
	if (!(chunks = new_chunk(numbers[0], numbers[size - 1], size - 0)))
		ft_exiterror("error", 1, 2);
	if (size > 3)
	{
		chunks->left = calculate_chunk(numbers, chunks->left, size / 2);
		chunks->right = calculate_chunk(numbers + (size / 2), chunks->right, size - (size / 2));
	}
	return (chunks);
}

void		print_chunks(void *content)
{
	ft_printf("%d - %d\n", ((t_chunk *)content)->low, ((t_chunk *)content)->high);
}

t_btree		**calculate_chunks(int *numbers, int size)
{
	t_btree	**chunk_array;
	int		num_chunks;
	int		i;

	// if (size > 90)
	// 	num_chunks = 10;
	// else
	num_chunks = 1;
	i = 0;
	chunk_array = NULL;
	if (!(chunk_array = (t_btree **)ft_memalloc(sizeof(t_btree *) * num_chunks + 1)))
		return (NULL);
	while (i < num_chunks)
	{
		chunk_array[i] = calculate_chunk(numbers + (size / num_chunks * i), chunk_array[i],
			size / num_chunks);
		i++;
	}
	chunk_array[i] = NULL;
	return (chunk_array);
}
