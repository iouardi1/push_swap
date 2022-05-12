/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:55:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/12 04:11:17 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lista(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

int	sorted(t_struct *strr)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = strr->lista;
	tmp1 = strr->lista->next;
	while (tmp)
	{
		if (!tmp1)
			break ;
		if (tmp1->content < tmp->content)
			return (0);
		tmp1 = tmp1->next;
		tmp = tmp->next;
	}
	return (1);
}

void	sort_two(t_struct *strr)
{
	if (!sorted(strr))
	{
		rotate(&strr->lista);
		write (1, "ra\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_struct	*strr;

	strr = malloc(sizeof(t_struct));
	strr->lista = NULL;
	strr->listb = NULL;
	if (argc <= 2)
		exit (0);
	if (argc > 2)
	{
		check_error(argv);
		fill_stack_a(strr, argv);
		if (sorted(strr))
			return (0);
		if (argc < 7)
		{
			sort_five(strr);
			exit (0);
		}
		move_to_stack_b(strr);
		final_sorting(strr);
		free_lista(strr->lista);
		free(strr);
	}
	return (0);
}
