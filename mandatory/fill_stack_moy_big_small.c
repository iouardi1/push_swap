/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_moy_big_small.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:18:58 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/12 03:26:11 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_struct *strr, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_lstadd_back(&strr->lista, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	calcul_moyenne(t_struct	*strr, t_list **lista)
{
	int		i;

	i = 0;
	while (*lista)
	{
		strr->moyenne += (*lista)->content;
		*lista = (*lista)->next;
		i++;
	}
	strr->moyenne /= i;
}

void	biggest_num(t_struct *strr, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	strr->beggy = strr->moyenne;
	while (tmp)
	{
		if (tmp->content >= strr->beggy)
			strr->beggy = tmp->content;
		tmp = tmp->next;
	}
}

int	smallest_num(t_struct *strr, t_list **list)
{
	int		index;
	t_list	*tmp;

	strr->smally = strr->moyenne;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content <= strr->smally)
		{
			strr->smally = tmp->content;
			index = tmp->index;
			strr->min_flag_a = tmp->flag;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	move_to_stack_b(t_struct *strr)
{
	t_list	*tmp;

	tmp = strr->lista;
	calcul_moyenne(strr, &tmp);
	tmp = strr->lista;
	biggest_num(strr, &tmp);
	tmp = strr->lista;
	smallest_num(strr, &tmp);
	while (ft_lstsize(strr->lista) > 2)
	{
		if (strr->lista->content != strr->beggy && \
			strr->lista->content != strr->smally)
		{
			push(&strr->lista, &strr->listb);
			write(1, "pb\n", 3);
			strr->instruc_num++;
		}
		else
		{
			rotate(&strr->lista);
			write(1, "ra\n", 3);
			strr->instruc_num++;
		}
	}
}
