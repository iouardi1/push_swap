/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_errors_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:46:24 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/11 00:02:20 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	check_line_supp(t_struct *strr, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(&strr->lista);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(&strr->listb);
	else if (!ft_strncmp(line, "rr\n", 3))
	{
		rotate(&strr->lista);
		rotate(&strr->listb);
	}
	else if (!ft_strncmp(line, "rrr\n", 4))
	{
		reverse_rotate(&strr->lista);
		reverse_rotate(&strr->listb);
	}
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(&strr->lista);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(&strr->listb);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(&strr->lista, &strr->listb);
	else
		return (0);
	return (1);
}

void	check_line(t_struct *strr, char *line)
{
	if (check_line_supp(strr, line))
		return ;
	else if (!ft_strncmp(line, "pa\n", 3))
		push(&strr->listb, &strr->lista);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap(strr->lista);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(strr->listb);
	else if (!ft_strncmp(line, "ss\n", 3))
	{
		swap(strr->listb);
		swap(strr->lista);
	}
	else
	{
		write (2, "Error\n", 7);
		exit (1);
	}
}

void	check_instructions_errors(t_struct *strr)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_line(strr, line);
		free (line);
	}
}
