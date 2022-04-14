/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:24:18 by iouardi           #+#    #+#             */
/*   Updated: 2022/04/14 02:13:41 by iouardi          ###   ########.fr       */
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

int		num_duplicated(char **argv, char *num, int argc, int l)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char) * argc);
	i = 0;
	j = 1;
	while (arr[i])
	{
		arr[i++] = ft_strdup(argv[j]);
		printf("%s\n", arr[i]);
	}
	j = 0;
	while (j < l)
	{
		if (!ft_strncmp(argv[j], num, ft_strlen(num)))
			return (0);
		j++;
	}
	return (1);
}

void    check_error(char **argv, int argc)
{
	int		i;

	i = 1;
	(void)argc;
	while (argv[i])
	{
		// printf("%s\n", argv[i]);
		if (!int_range(argv[i]) || num_duplicated(argv, argv[i], argc, i))
		{
			write (2, "errooor!\n", 8);
			exit (1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc >= 3)
	{
		check_error(argv, argc);
	}
	else
	{
		write (2, "error!\n", 8);
		exit (1);
	}
	return (0);
}
