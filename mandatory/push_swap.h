/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:26:14 by iouardi           #+#    #+#             */
/*   Updated: 2022/05/10 23:52:21 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include "../src/gnl/get_next_line.h"

typedef struct s_struct
{
	int		moyenne;
	int		beggy;
	int		smally;
	t_list	*lista;
	t_list	*listb;
	int		instruc_num;
	int		max_a;
	int		max_b;
	int		pos;
	int		min_flag_a;
	int		min_flag_b;
}	t_struct;

t_list	*ft_lstlast(t_list *lst);
t_list	*find_position_init(t_struct *strr, int *flagg, int *min);
t_list	*min_instruc_found(t_struct *strr);
void	calculating_instruc(t_struct *strr);
void	check_error(char **argv);
void	fill_stack_a(t_struct *strr, char **argv);
void	calcul_moyenne(t_struct	*strr, t_list **lista);
void	biggest_num(t_struct *strr, t_list **list);
void	move_to_stack_b(t_struct *strr);
void	swap(t_list *list);
void	push(t_list **lista, t_list **listb);
void	rotate(t_list **lista);
void	reverse_rotate(t_list **lista);
void	sorting_supp1(t_struct *strr, int pos, int min_index);
void	sorting_supp2(t_struct *strr, int pos, int min_index);
void	sorting(t_struct *strr);
void	final_sorting(t_struct	*strr);
int		num_duplicated(char **argv, int l);
int		element_pos_in_a(t_struct *strr, int a);
int		indexing_stack(t_list *list);
int		smallest_num(t_struct *strr, t_list **list);
int		int_range(char *num);
int		isnum(char *num);
int		find_position_supp(t_struct *strr, int flag, int pos);
int		find_position(t_struct *strr, int element);
void	check_line(t_struct *strr, char *line);
void	check_instructions_errors(t_struct *strr);
int		check_line_supp(t_struct *strr, char *line);

#endif