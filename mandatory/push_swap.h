/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:26:14 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/07 23:36:53 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct  s_struct{
	int     moyenne;
	int		beggy;
	int		smally;
	t_list	*lista;
	t_list	*listb;
	int		instruc_num;
	// int		demi_stack_a;
	// int		demi_stack_b;
	int		max_a;
	int		max_b;
	int		min_flag_a;
	int		min_flag_b;
}   t_struct;

t_list	*ft_lstlast(t_list *lst);

#endif