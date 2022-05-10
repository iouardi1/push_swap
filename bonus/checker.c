/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:55:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/11 00:01:18 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	sorted(t_struct *strr)
{
	t_list	*tmp;

	tmp = strr->lista;
	while (strr->lista)
	{
		tmp = strr->lista->next;
		if (!tmp)
			break ;
		if (tmp->content < strr->lista->content)
			return (0);
		strr->lista = strr->lista->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	*strr;

	strr = malloc(sizeof(t_struct));
	strr->lista = NULL;
	strr->listb = NULL;
	if (argc > 2)
	{
		check_error(argv);
		fill_stack_a(strr, argv);
		check_instructions_errors(strr);
		if (!strr->listb && sorted(strr))
		{
			write(1, "OK\n", 3);
			exit (0);
		}
		write(1, "KO\n", 3);
	}
	else
	{
		write(1, "Please insert more args\n", 25);
		exit (-1);
	}
	return (0);
}
