# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 09:33:30 by alecott           #+#    #+#              #
#    Updated: 2018/01/29 17:50:24 by rkrief           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

LIB_PATH = ./libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

NAME = rkrief.filler

CFLAGS = -Wall -Werror -Wextra 

INC = filler.h

SRCS_PATH = ./srcs

ALL_SRCS = 	main.c ft_istab.c ft_find_player.c ft_ally.c ft_rival.c \
			ft_checkplace.c ft_fill_map.c ft_take_score.c \
			ft_heat_map.c ft_copy_all.c

SRCS = $(addprefix $(SRCS_PATH)/, $(ALL_SRCS))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(MAKE) -C libft
	gcc $(CFLAGS) $(OBJ) -L libft -lft -o $(NAME)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -f $(LIB_OBJ)
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
