/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:24:18 by iouardi           #+#    #+#             */
/*   Updated: 2022/04/22 06:25:11 by iouardi          ###   ########.fr       */
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

void	swap(t_list *list)
{
	int		tmp;

	if (ft_lstsize(list) <= 1)
		return ;
	tmp = list->content;
	list->content = list->next->content;
	list->next->content = tmp;
}

void	push(t_list **lista, t_list **listb)
{
	t_list	*new_list;

	if (!lista)
		return;
	ft_lstadd_front(listb, ft_lstnew((*lista)->content));
	new_list = *lista;
	(*lista) = (*lista)->next;
	ft_lstdelone(new_list, NULL);
}

void	rotate(t_list **lista)
{
	t_list	*temp;

	temp = (*lista)->next;
	ft_lstadd_back(lista, ft_lstnew((*lista)->content));
	ft_lstdelone((*lista), NULL);
	(*lista) = temp;
}

void	reverse_rotate(t_list **lista)
{
	t_list	*temp;
	t_list	*temp1;

	temp = (*lista);
	temp1 = NULL;

	if (*lista == NULL || (*lista)->next == NULL)
		return ;
	while (temp->next != NULL)
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = NULL;
	temp->next = *lista;
	*lista = temp;
}

int main(int argc, char **argv)
{
	t_list	*lista = NULL;
	t_list	*listb = NULL;
	t_list	*temp1;
	t_list	*temp2;
	int		i;

	if (argc >= 3)
	{
		i = 1;
		check_error(argv, argc);
		while (argv[i])
		{
			ft_lstadd_back(&lista, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		temp2 = listb;
		// swap_a(lista);
		// push(&lista, &listb);
		// printf("------%d\n", listb->content);
		temp1 = lista;
		// while (temp1)
		// {
		// 	printf("=====%d\n", (int)temp1->content);
		// 	temp1 = temp1->next;
		// }
		// puts("\n\n");
		// push(&listb, &lista);
		reverse_rotate(&lista);
		temp1 = lista;
		while (temp1)
		{
			printf("++++++%d\n", (int)temp1->content);
			temp1 = temp1->next;
		}
		// if (listb)
		// 	printf("------%d\n", listb->content);
	}
	else
	{
		write (2, "error!\n", 8);
		exit (1); 
	}
	return (0);
}
