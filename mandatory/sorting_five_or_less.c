/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five_or_less.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 04:10:01 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/12 04:18:49 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_1(t_struct *strr, t_list **tmp)
{
	if ((*tmp)->content > (*tmp)->next->content)
	{
		(*tmp) = (*tmp)->next;
		if ((*tmp)->content > (*tmp)->next->content)
		{
			swap(strr->lista);
			reverse_rotate(&strr->lista);
			write (1, "sa\n", 3);
			write (1, "rra\n", 4);
		}
		else if ((*tmp)->next->content > strr->lista->content)
		{
			swap(strr->lista);
			write (1, "sa\n", 3);
		}
		else
		{
			rotate(&strr->lista);
			write (1, "ra\n", 3);
		}
		return (1);
	}
	return (0);
}

void	sort_three_2(t_struct *strr, t_list **tmp)
{
	t_list	*tmp1;

	tmp1 = strr->lista;
	if ((*tmp)->next->content > tmp1->content)
	{
		swap(strr->lista);
		rotate(&strr->lista);
		write (1, "sa\n", 3);
		write (1, "ra\n", 3);
	}
	else
	{
		reverse_rotate(&strr->lista);
		write (1, "rra\n", 4);
	}
}

void	sort_three_or_two(t_struct *strr)
{
	t_list	*tmp;

	tmp = strr->lista;
	if (ft_lstsize(tmp) == 2)
	{
		sort_two(strr);
		exit (0);
	}
	if (!sort_three_1(strr, &tmp))
	{
		tmp = tmp->next;
		if (tmp->content > tmp->next->content)
			sort_three_2(strr, &tmp);
	}
}

void	sort_five_supp(t_struct *strr)
{
	t_list	*tmpa;

	tmpa = strr->lista;
	calcul_moyenne(strr, &tmpa);
	tmpa = strr->lista;
	biggest_num(strr, &tmpa);
	tmpa = strr->lista;
	smallest_num(strr, &tmpa);
	while (ft_lstsize(strr->lista) > 3)
	{
		tmpa = strr->lista;
		if (tmpa->content == strr->beggy || tmpa->content == strr->smally)
		{
			push(&strr->lista, &strr->listb);
			write (1, "pb\n", 3);
		}
		else
		{
			rotate(&strr->lista);
			write (1, "ra\n", 3);
		}
		tmpa = strr->lista;
	}
}

void	sort_five(t_struct *strr)
{
	t_list	*tmpb;

	sort_five_supp(strr);
	sort_three_or_two(strr);
	tmpb = strr->listb;
	while (ft_lstsize(tmpb))
	{
		if (tmpb->content < strr->lista->content)
		{
			push(&strr->listb, &strr->lista);
			write (1, "pa\n", 3);
		}
		else
		{
			push(&strr->listb, &strr->lista);
			rotate(&strr->lista);
			write (1, "pa\n", 3);
			write (1, "ra\n", 3);
		}
		tmpb = strr->listb;
	}
}
