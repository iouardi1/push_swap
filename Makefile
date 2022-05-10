# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:41:34 by iouardi           #+#    #+#              #
#    Updated: 2022/05/10 20:00:05 by iouardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 			push_swap
FLAGS=			-Wall -Werror -Wextra
CC=				cc
SRC_FILES=		mandatory/push_swap.c \
				mandatory/calculate_min_instruc.c \
				mandatory/check_errors.c \
				mandatory/fill_stack_moy_big_small.c \
				mandatory/indexing.c \
				mandatory/instructions.c \
				mandatory/sorting.c

SRC_FILES_BONUS = bonus/push_swap_bonus.c \
				bonus/calculate_min_instruc_bonus.c \
				bonus/check_errors_bonus.c \
				bonus/fill_stack_moy_big_small_bonus.c \
				bonus/indexing_bonus.c \
				bonus/instructions_bonus.c \
				bonus/sorting_bonus.c

OBJ_FILES=			$(SRC_FILES:.c=.o)
OBJ_FILES_BONUS=	$(SRC_FILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C src/libft
	@cp src/libft/libft.a ./
	$(CC) $(OBJ_FILES) -o $(NAME) libft.a
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -g

clean:
	find . -name "*.o" -delete
	find . -name "*.a" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ_FILES_BONUS)
	@make -C src/libft
	@cp src/libft/libft.a ./
	$(CC) $(FLAGS) $(OBJ_FILES_BONUS) -o $(NAME) libft.a

.PHONY:
	all clean fclean re bonus