/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_instruc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:23:56 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 19:29:21 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_position_init(t_struct *strr, int *flagg, int *min)
{
	t_list	*tmp;

	strr->max_a = indexing_stack(strr->lista);
	*flagg = 0;
	*min = 1;
	tmp = strr->lista;
	return (tmp);
}

int	find_position_supp(t_struct *strr, int flag, int pos)
{
	if (!flag)
	{
		strr->min_flag_a = 0;
		if (pos == 0)
			return (pos - 1);
		return (pos);
	}
	else
	{
		strr->min_flag_a = 1;
		return (strr->max_a - pos + 1);
	}
	return (-1);
}

int	find_position(t_struct *strr, int element)
{
	t_list	*tmp;
	int		min;
	int		pos;
	int		flagg;
	int		flag;

	tmp = find_position_init(strr, &flagg, &min);
	while (tmp)
	{
		if (element < tmp->content && !flagg)
		{
			flag = tmp->flag;
			min = tmp->content;
			flagg = 1;
			pos = tmp->index;
		}
		else if ((element < tmp->content && min > tmp->content))
		{
			flag = tmp->flag;
			min = tmp->content;
			pos = tmp->index;
		}
		tmp = tmp->next;
	}
	return (find_position_supp(strr, flag, pos));
}

void	calculating_instruc(t_struct *strr)
{
	t_list	*tmpb;
	int		pos;

	tmpb = strr->listb;
	while (tmpb)
	{
		pos = find_position(strr, tmpb->content);
		strr->max_b = indexing_stack(strr->listb);
		tmpb->num_of_instru = pos;
		if (!tmpb->flag)
			tmpb->num_of_instru += tmpb->index + 1;
		else
			tmpb->num_of_instru += strr->max_b - tmpb->index + 2;
		tmpb = tmpb->next;
	}
}

t_list	*min_instruc_found(t_struct *strr)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		min;
	int		pos;

	tmp = strr->listb;
	calculating_instruc(strr);
	min = tmp->num_of_instru;
	tmp1 = tmp;
	while (tmp)
	{
		if (min > tmp->num_of_instru)
		{
			min = tmp->num_of_instru;
			tmp1 = tmp;
		}
		tmp = tmp->next;
	}
	pos = find_position(strr, tmp1->content);
	if (tmp1->flag)
		tmp1->index = strr->max_b - tmp1->index + 1;
	tmp1->num_of_instru = pos;
	strr->min_flag_b = tmp1->flag;
	return (tmp1);
}
