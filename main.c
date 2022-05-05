/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:26:06 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/04 16:29:26 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexing_stack(t_list **list)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *list;
	while ((tmp)->next)
	{
		(tmp)->index = i++;
		(tmp) = (tmp)->next;
	}
	(tmp)->index = i;
	return ((tmp)->index + 1);
}

int	find_position(t_struct *strr, int element)
{
	t_list	*tmp;
	int		min;
	int		pos;

	indexing_stack(&strr->lista);
	tmp = strr->lista;
	min = tmp->content;
	while (tmp)
	{
		if (element < tmp->content && min <= tmp->content)
		{
			min = tmp->content;
			pos = tmp->index;
			printf("pos : %d\n", pos);
		}
		tmp = tmp->next;
	}
	return (pos);
}

int main(int argc, char **argv)
{
    t_struct	*strr = malloc(sizeof(t_struct));
	t_list		*temp1;
	t_list		*temp2;
	int			i;

	strr->lista = NULL;
	strr->listb = NULL;
	strr->moyenne = 0;
	strr->beggy = 0;
	strr->smally = 0;
	strr->instruc_num = 0;
	if (argc >= 3)
	{
		i = 1;
		check_error(argv, argc);
		while (argv[i])
		{
			ft_lstadd_back(&strr->lista, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		temp1 = strr->lista;
        calcul_moyenne(strr, &temp1);
        temp1 = strr->lista;
		biggest_num(strr, &temp1);
        temp1 = strr->lista;
		smallest_num(strr, &temp1);
        move_to_stack_b(strr);
        sort_first_two(strr);
        temp1 = strr->lista;
    }
	else
	{
		write (2, "error!\n", 8);
		exit (1);
	}
	return (0);

}