/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:12:19 by iouardi           #+#    #+#             */
/*   Updated: 2022/04/18 03:15:58 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*arr;

	arr = (t_list *)malloc(sizeof(t_list));
	if (arr == NULL)
		return (NULL);
	arr->next = NULL;
	arr->content = content;
	return (arr);
}
