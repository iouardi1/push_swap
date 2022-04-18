/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:24:18 by iouardi           #+#    #+#             */
/*   Updated: 2022/04/18 03:24:43 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnum(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	int_range(char *num)
{
	int		number;

	if (!isnum(num))
		return (0);
	number = ft_atoi(num);
	if ((number == 0 || number == -1) && (ft_strlen(num) > 3))
		return (0);
	return (1);
}

int		num_duplicated(char **argv, int l)
{
	int		j;

	j = 0;
	while (j < l)
	{
		if (!ft_strncmp(argv[j], argv[l], ft_strlen(argv[l])))
			return (0);
		j++;
	}
	return (1);
}

void    check_error(char **argv, int argc)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * argc);
	while (argv[i])
	{
		arr[j] = ft_strdup(argv[i]);
		i++;
	}
	arr[j] = NULL;
	i = 1;
	while (argv[i])
	{
		if (!int_range(argv[i]) || !num_duplicated(argv, i))
		{
			write (2, "errooor!\n", 8);
			exit (1);
		} 
		i++;
	}
}

int main(int argc, char **argv)
{
	t_list	*list = NULL;
	int		i;

	if (argc >= 3)
	{
		i = 1;
		check_error(argv, argc);
		// while (list->next)
		// {
		// 	list->data = ft_atoi(argv[i]);
		// 	printf("=====%d\n", list->data);
		// 	list->next->data = ft_atoi(argv[i + 1]);
		// 	i++;
		// }
		// list = malloc(sizeof(t_list) * argc);
		while (argv[i])
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		while (list)
		{
			printf("=====%d\n", (int)list->content);
			list = list->next;
		}
	}
	else
	{
		write (2, "error!\n", 8);
		exit (1);
	}
	return (0);
}
