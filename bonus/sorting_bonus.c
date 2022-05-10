/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:26:17 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 19:36:31 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_pos_in_a(t_struct *strr, int a)
{
	t_list	*tmp;
	int		pos;

	tmp = strr->listb;
	while (tmp)
	{
		if (!tmp->flag && tmp->index == a)
		{
			pos = find_position(strr, tmp->content);
			return (pos);
		}
		tmp = tmp->next;
	}
	return (-1);
}

void	sorting_supp1(t_struct *strr, int pos, int min_index)
{
	while (pos > 0 && min_index && !strr->min_flag_a && !strr->min_flag_b)
	{
		rotate(&strr->listb);
		rotate(&strr->lista);
		write(1, "rr\n", 3);
		pos--;
		min_index--;
	}
	while (pos > 0 && !strr->min_flag_a)
	{	
		rotate(&strr->lista);
		write(1, "ra\n", 3);
		pos--;
	}
	while (min_index && !strr->min_flag_b)
	{
		rotate(&strr->listb);
		write(1, "rb\n", 3);
		min_index--;
	}
}

void	sorting_supp2(t_struct *strr, int pos, int min_index)
{
	while (pos > 0 && min_index && strr->min_flag_a && strr->min_flag_b)
	{
		reverse_rotate(&strr->listb);
		reverse_rotate(&strr->lista);
		write(1, "rrr\n", 4);
		pos--;
		min_index--;
	}
	while (pos > 0 && strr->min_flag_a)
	{
		reverse_rotate(&strr->lista);
		write(1, "rra\n", 4);
		pos--;
	}
	while (min_index && strr->min_flag_b)
	{
		reverse_rotate(&strr->listb);
		write(1, "rrb\n", 4);
		min_index--;
	}
}	

void	sorting(t_struct *strr)
{
	int		min_index;
	int		pos;
	t_list	*f;

	while (ft_lstsize(strr->listb))
	{
		f = min_instruc_found(strr);
		pos = f->num_of_instru;
		min_index = f->index;
		find_position(strr, f->content);
		sorting_supp1(strr, pos, min_index);
		sorting_supp2(strr, pos, min_index);
		push(&strr->listb, &strr->lista);
		write(1, "pa\n", 3);
	}
}

void	final_sorting(t_struct	*strr)
{
	t_list	*tmp;
	int		smally_index;

	sorting(strr);
	indexing_stack(strr->lista);
	tmp = strr->lista;
	smally_index = smallest_num(strr, &tmp);
	if (strr->min_flag_a)
	{
		while (strr->lista->content != strr->smally)
		{
			reverse_rotate(&strr->lista);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while (strr->lista->content != strr->smally)
		{
			rotate(&strr->lista);
			write(1, "ra\n", 3);
		}
	}
}
