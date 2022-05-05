/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:44 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/05 01:37:11 by iouardi          ###   ########.fr       */
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
	t_list	*tmp;

	strr->moyenne = 0;
	strr->beggy = 0;
	strr->smally = 0;
	tmp = strr->lista;
	calcul_moyenne(strr, &tmp);
	tmp = strr->lista;
	biggest_num(strr, &tmp);
	tmp = strr->lista;
	smallest_num(strr, &tmp);
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

int	indexing_stack(t_list **list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while ((tmp)->next)
	{
		(tmp)->index = i++;
		(tmp) = (tmp)->next;
	}
	(tmp)->index = i;
	return ((tmp)->index);
}

// int		calcu_num_of_instr_in_a(t_struct *strr, int element)
// {
	// t_list	*list;
	// int		demi_stack;
	// int		all_elems;
	// int		min;
	// int		pos;

	// list = strr->lista;
	// all_elems = indexing_stack(&strr->lista);
	// if (!all_elems % 2)
	// 	demi_stack = all_elems / 2;
	// else
	// 	demi_stack = (all_elems + 1) / 2;
	// while (list)
	// {
	// 	if (element > list->content && min >= list->content)
	// 	{
	// 		min = list->content;
	// 		pos = list->index;
	// 	}
	// 	list = list->next;
	// }
	
	// return (0);
int    find_position(t_struct *strr, int element)
{
    t_list    *tmp;
    int        min;
    int        pos;
    int        flag;

    indexing_stack(&strr->lista);
    flag = 0;
    min = 1;
    pos = ft_lstsize(strr->lista);
    tmp = strr->lista;
    while (tmp)
    {
        if (element < tmp->content  && !flag)
        {
            min = tmp->content;
            flag = 1;
            pos = tmp->index;
        }
        else if ((element < tmp->content && min > tmp->content))
        {
             min = tmp->content;
             pos = tmp->index;
        }
        tmp = tmp->next;
    }
    return (pos);
}

void fill_demi_stacks(t_struct *strr)
{
	int		all_elems;
	
	all_elems = indexing_stack(&strr->lista);
	if (!all_elems % 2)
		strr->demi_stack_a = all_elems / 2;
	else
		strr->demi_stack_a = (all_elems + 1) / 2;
	all_elems = indexing_stack(&strr->listb);
	if (!all_elems % 2)
		strr->demi_stack_b = all_elems / 2;
	else
		strr->demi_stack_b = (all_elems + 1) / 2;
}

void	calculating_instruc(t_struct *strr)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		pos;

	fill_demi_stacks(strr);
	strr->lista->num_of_instru = 0;
	tmpb = strr->listb;
	tmpa = strr->lista;
	strr->lista->flag = 1;
	strr->listb->flag = 1;
	while (tmpb)
	{
		pos = find_position(strr, tmpb->content);
		if (pos <= strr->demi_stack_a)
		{
			tmpb->num_of_instru = pos;
			if (tmpb->index <= strr->demi_stack_b)
			{
				strr->listb->flag = 0;
				tmpb->num_of_instru += tmpb->index + 1;
			}
			else
				tmpb->num_of_instru += tmpb->index - strr->demi_stack_b + 1;
		}
		else if (tmpb->index <= strr->demi_stack_b)
			tmpb->num_of_instru = (pos - strr->demi_stack_a) + tmpb->index + 1;
			else
				tmpb->num_of_instru = (pos - strr->demi_stack_a) + tmpb->index 
					- strr->demi_stack_b + 1;
		tmpb = tmpb->next;
}

int	min_instruc_found(t_struct *strr)
{
	t_list	*tmp;
	int		min;

	tmp = strr->listb;
	calculating_instruc(strr);
	min = tmp->num_of_instru;
	while (tmp)
	{	
		if (min >= tmp->num_of_instru)
			min = tmp->num_of_instru;
		tmp = tmp->next;
	}
	tmp = strr->listb;
	while (tmp)
	{
		if (min == tmp->num_of_instru)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
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
		tmp1 = strr->lista;
		move_to_stack_b(strr);
		// tmp1 = strr->listb;
		tmp1 = strr->lista;
		// while (tmp1)
		// {
		// 	printf("%d\n", tmp1->content);
		// 	tmp1 = tmp1->next;
		// }
	}
	else
	{
		printf("Please insert more args\n");
		exit (-1);
	}
	return (0);
}