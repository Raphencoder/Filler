# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 12:15:04 by rkrief            #+#    #+#              #
#    Updated: 2018/01/22 15:37:19 by rkrief           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rkrief.filler

SRC = srcs

F_SRC = main.c \ ft_find_player.c

OBJ =	$(patsubst %.c, %.o, $(F_SRC))

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAG) -L libft -lft $(OBJ)

%.o: $(SRC)/%.c
	gcc -c -o $@ $<

clean :
	make -C libft/ clean
		rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) a.out

re :	clean all

run :	re clean
