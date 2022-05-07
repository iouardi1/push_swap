/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:55:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/07 19:16:53 by iouardi          ###   ########.fr       */
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

	if (*lista == NULL)
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
	while (ft_lstsize(strr->lista) > 2)
	{
		if (strr->lista->content != strr->beggy && strr->lista->content != strr->smally)
		{
			push(&strr->lista, &strr->listb);
			printf("pb\n");
			strr->instruc_num++;
		}
		else
		{
			rotate(&strr->lista);
			printf("ra\n");
			strr->instruc_num++;
		}
	}
}

void	sort_first_two(t_struct *strr)
{
	if (strr->lista->content == strr->beggy)
	{
		rotate(&strr->lista);
		printf("ra\n");
		strr->instruc_num++;
	}
}

void	fill_stack_a(t_struct *strr, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_lstadd_back(&strr->lista, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	indexing_stack(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		size;
	int		demi_size;

	i = 0;
	tmp = *list;
	size = ft_lstsize(tmp);
	if (size % 2 != 0)
		demi_size = (size / 2) + 1;
	else
		demi_size = size / 2;
	while (i < demi_size)
	{
		(tmp)->index = i++;
		tmp = tmp->next;
	}
	i = 0;
	while (i < demi_size && tmp)
	{
		(tmp)->index = i++;
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	t_struct	*strr;
	t_list		*tmp1;
	
	strr = malloc(sizeof(t_struct));
	strr->lista = NULL;
	strr->listb = NULL;
	if (argc > 2)
	{
		check_error(argv, argc);
		fill_stack_a(strr, argv);
		// move_to_stack_b(strr);
		// sort_first_two(strr);
		tmp1 = strr->listb;
		tmp1 = strr->lista;
		indexing_stack(&tmp1);
		// sorting(strr);
		// final_sorting(strr);
		tmp1 = strr->lista;
		while (tmp1)
		{
			printf("stack a : %d index : %d\n", tmp1->content, tmp1->index);
			tmp1 = tmp1->next;
		}
	}
	else
	{
		printf("Please insert more args\n");
		exit (-1);
	}
	return (0);
}