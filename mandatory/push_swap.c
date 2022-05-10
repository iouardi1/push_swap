/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:55:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 18:05:48 by iouardi          ###   ########.fr       */
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

int	smallest_num(t_struct *strr, t_list **list)
{
	int		index;

	strr->smally = strr->moyenne;
	while ((*list))
	{
		if ((*list)->content <= strr->smally)
		{
			strr->smally = (*list)->content;
			index = (*list)->index;
			strr->min_flag_a = (*list)->flag;
		}
		*list = (*list)->next;
	}
	return (index);
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

void	move_to_stack_b(t_struct *strr)
{
	t_list	*tmp;

	tmp = strr->lista;
	calcul_moyenne(strr, &tmp);
	tmp = strr->lista;
	biggest_num(strr, &tmp);
	tmp = strr->lista;
	smallest_num(strr, &tmp);
	while (ft_lstsize(strr->lista) > 2)
	{
		if (strr->lista->content != strr->beggy && \
			strr->lista->content != strr->smally)
		{
			push(&strr->lista, &strr->listb);
			write(1, "pb\n", 3);
			strr->instruc_num++;
		}
		else
		{
			rotate(&strr->lista);
			write(1, "ra\n", 3);
			strr->instruc_num++;
		}
	}
}

int	indexing_stack(t_list *list)
{
	int		i;
	int		size;
	int		demi_size;

	i = 0;
	size = ft_lstsize(list);
	if (size % 2 != 0)
		demi_size = (size / 2) + 1;
	else
		demi_size = size / 2;
	while (i < demi_size)
	{
		list->flag = 0;
		list->index = i++;
		list = list->next;
	}
	i = 0;
	while (i < demi_size && list)
	{
		list->flag = 1;
		list->index = i++;
		list = list->next;
	}
	return (i - 1);
}

t_list	*find_position_init(t_struct *strr, int *flagg, int *min)
{
	t_list	*tmp;

	strr->max_a = indexing_stack(strr->lista);
	*flagg = 0;
	*min = 1;
	tmp = strr->lista;
	return (tmp);
}

int	find_position_supp(t_struct *strr, int flag, int pos)
{
	if (!flag)
	{
		strr->min_flag_a = 0;
		if (pos == 0)
			return (pos - 1);
		return (pos);
	}
	else
	{
		strr->min_flag_a = 1;
		return (strr->max_a - pos + 1);
	}
	return (-1);
}

int	find_position(t_struct *strr, int element)
{
	t_list	*tmp;
	int		min;
	int		pos;
	int		flagg;
	int		flag;

	tmp = find_position_init(strr, &flagg, &min);
	while (tmp)
	{
		if (element < tmp->content && !flagg)
		{
			flag = tmp->flag;
			min = tmp->content;
			flagg = 1;
			pos = tmp->index;
		}
		else if ((element < tmp->content && min > tmp->content))
		{
			flag = tmp->flag;
			min = tmp->content;
			pos = tmp->index;
		}
		tmp = tmp->next;
	}
	return (find_position_supp(strr, flag, pos));
}

void	calculating_instruc(t_struct *strr)
{
	t_list	*tmpb;
	int		pos;

	tmpb = strr->listb;
	while (tmpb)
	{
		pos = find_position(strr, tmpb->content);
		strr->max_b = indexing_stack(strr->listb);
		tmpb->num_of_instru = pos;
		if (!tmpb->flag)
			tmpb->num_of_instru += tmpb->index + 1;
		else
			tmpb->num_of_instru += strr->max_b - tmpb->index + 2;
		tmpb = tmpb->next;
	}
}

t_list	*min_instruc_found(t_struct *strr)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		min;
	int		pos;

	tmp = strr->listb;
	calculating_instruc(strr);
	min = tmp->num_of_instru;
	tmp1 = tmp;
	while (tmp)
	{
		if (min > tmp->num_of_instru)
		{
			min = tmp->num_of_instru;
			tmp1 = tmp;
		}
		tmp = tmp->next;
	}
	pos = find_position(strr, tmp1->content);
	if (tmp1->flag)
		tmp1->index = strr->max_b - tmp1->index + 1;
	tmp1->num_of_instru = pos;
	strr->min_flag_b = tmp1->flag;
	return (tmp1);
}

int	element_pos_in_a(t_struct *strr, int a)
{
	t_list	*tmp;
	int		pos;

	tmp = strr->listb;
	while (tmp)
	{
		if (!tmp->flag && tmp->index == a)
		{
			pos = find_position(strr, tmp->content);
			return (pos);
		}
		tmp = tmp->next;
	}
	return (-1);
}

void	sorting_supp1(t_struct *strr, int pos, int min_index)
{
	while (pos > 0 && min_index && !strr->min_flag_a && !strr->min_flag_b)
	{
		rotate(&strr->listb);
		rotate(&strr->lista);
		write(1, "rr\n", 3);
		pos--;
		min_index--;
	}
	while (pos > 0 && !strr->min_flag_a)
	{	
		rotate(&strr->lista);
		write(1, "ra\n", 3);
		pos--;
	}
	while (min_index && !strr->min_flag_b)
	{
		rotate(&strr->listb);
		write(1, "rb\n", 3);
		min_index--;
	}
}

void	sorting_supp2(t_struct *strr, int pos, int min_index)
{
	while (pos > 0 && min_index && strr->min_flag_a && strr->min_flag_b)
	{
		reverse_rotate(&strr->listb);
		reverse_rotate(&strr->lista);
		write(1, "rrr\n", 4);
		pos--;
		min_index--;
	}
	while (pos > 0 && strr->min_flag_a)
	{
		reverse_rotate(&strr->lista);
		write(1, "rra\n", 4);
		pos--;
	}
	while (min_index && strr->min_flag_b)
	{
		reverse_rotate(&strr->listb);
		write(1, "rrb\n", 4);
		min_index--;
	}
}	

void	sorting(t_struct *strr)
{
	int		min_index;
	int		pos;
	t_list	*f;

	while (ft_lstsize(strr->listb))
	{
		f = min_instruc_found(strr);
		pos = f->num_of_instru;
		min_index = f->index;
		find_position(strr, f->content);
		sorting_supp1(strr, pos, min_index);
		sorting_supp2(strr, pos, min_index);
		push(&strr->listb, &strr->lista);
		write(1, "pa\n", 3);
	}
}

void	final_sorting(t_struct	*strr)
{
	t_list	*tmp;
	int		smally_index;

	sorting(strr);
	indexing_stack(strr->lista);
	tmp = strr->lista;
	smally_index = smallest_num(strr, &tmp);
	if (strr->min_flag_a)
	{
		while (strr->lista->content != strr->smally)
		{
			reverse_rotate(&strr->lista);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while (strr->lista->content != strr->smally)
		{
			rotate(&strr->lista);
			write(1, "ra\n", 3);
		}
	}
}

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
