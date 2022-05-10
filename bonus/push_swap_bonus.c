/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:55:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 19:26:55 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	*strr;

	strr = malloc(sizeof(t_struct));
	strr->lista = NULL;
	strr->listb = NULL;
	if (argc > 2)
	{
		check_error(argv, argc);
		fill_stack_a(strr, argv);
		move_to_stack_b(strr);
		final_sorting(strr);
	}
	else
	{
		write(1, "Please insert more args\n", 25);
		exit (-1);
	}
	return (0);
}
