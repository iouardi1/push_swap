/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 19:31:40 by iouardi          ###   ########.fr       */
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

int	num_duplicated(char **argv, int l)
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

void	check_error(char **argv, int argc)
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
