/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:24:18 by iouardi           #+#    #+#             */
/*   Updated: 2022/04/25 04:59:41 by iouardi          ###   ########.fr       */
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

	if (list == NULL || list->next == NULL)
		return ;
	if (ft_lstsize(list) <= 1)
		return ;
	tmp = list->content;
	list->content = list->next->content;
	list->next->content = tmp;
}

void	push(t_list **lista, t_list **listb)
{
	t_list	*new_list;

	if (*lista == NULL || (*lista)->next == NULL)
		return ;
	ft_lstadd_front(listb, ft_lstnew((*lista)->content));
	new_list = *lista;
	(*lista) = (*lista)->next;
	ft_lstdelone(new_list, NULL);
}

void	rotate(t_list **lista)
{
	t_list	*temp;

	if (*lista == NULL || (*lista)->next == NULL)
		return ;
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

void	calcul_moyenne(t_struct	*strr, t_list **lista)
{
	int		i;

	i = 0;
	while (*lista)
	{
		strr->moyenne += (*lista)->content;
		*lista = (*lista)->next;
		i++;
	}
	strr->moyenne /= i;
}

void	biggest_num(t_struct *strr, t_list **list)
{
	strr->beggy = strr->moyenne;
	while ((*list))
	{
		if ((*list)->content >= strr->beggy)
			strr->beggy = (*list)->content;
		*list = (*list)->next;
	}
}

void	smallest_num(t_struct *strr, t_list **list)
{
	strr->smally = strr->moyenne;
	while ((*list))
	{
		if ((*list)->content <= strr->smally)
			strr->smally = (*list)->content;
		*list = (*list)->next;
	}
}

void	move_to_stack_b(t_struct *strr)
{
	t_list	*tmp;

	tmp = strr->lista;
	while (ft_lstsize(strr->lista) > 2)
	{
		if (strr->lista->content != strr->beggy && strr->lista->content != strr->smally)
		{
			push(&strr->lista, &strr->listb);
			strr->instruc_num++;
		}
		else
		{
			rotate(&strr->lista);
			strr->instruc_num++;
		}
	}
}

void	sort_first_two(t_struct *strr)
{
	if (strr->lista->content == strr->beggy)
	{
		rotate(&strr->lista);
		strr->instruc_num++;
	}
}

void	indexing_stuck(t_list **list)
{
	(*list)->index = 0;
	while ((*list))
	{
		(*list)->index++;
		(*list) = (*list)->next;
	}
}

void	calculating_instruc(t_struct *strr)
{
	indexing_stuck(&strr->listb);
	strr->listb->num_of_instru = 0;
	while (*)
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
		// printf("%d=====\n", strr->lista->content);
		temp2 = strr->listb;
		temp1 = strr->lista;
		calcul_moyenne(strr, &temp1);
		printf("moyenne:%d\n", strr->moyenne);
		temp1 = strr->lista;
		biggest_num(strr, &temp1);
		printf("beggy:%d\n", strr->beggy);
		temp1 = strr->lista;
		smallest_num(strr, &temp1);
		printf("smally:%d\n", strr->smally);
		temp1 = strr->lista;
		while (temp1)
		{
			printf("++++++%d\n", temp1->content);
			temp1 = temp1->next;
		}
		temp1 = strr->lista;
		move_to_stack_b(strr);
		sort_first_two(strr);
		// while (temp1)
		// {
		// 	printf("-----%d\n", temp1->content);
		// 	temp1 = temp1->next;
		// }
		while (strr->lista)
		{
			printf("-----%d\n", strr->lista->content);
			strr->lista = strr->lista->next;
		}
		temp1 = strr->lista;
		// swap_a(strr->lista);
		// push(&strr->lista, &strr->listb);
		// push(&strr->listb, &strr->lista);
		// reverse_rotate(&strr->lista);
		temp1 = strr->lista;
		
	}
	else
	{
		write (2, "error!\n", 8);
		exit (1); 
	}
	return (0);
}
