/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:22:13 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 19:33:42 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexing_stack(t_list *list)
{
	int		i;
	int		size;
	int		demi_size;

	i = 0;
	size = ft_lstsize(list);
	if (size % 2 != 0)
		demi_size = (size / 2) + 1;
	else
		demi_size = size / 2;
	while (i < demi_size)
	{
		list->flag = 0;
		list->index = i++;
		list = list->next;
	}
	i = 0;
	while (i < demi_size && list)
	{
		list->flag = 1;
		list->index = i++;
		list = list->next;
	}
	return (i - 1);
}
