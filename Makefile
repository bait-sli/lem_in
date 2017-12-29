# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 06:45:12 by bait-sli          #+#    #+#              #
#    Updated: 2017/12/14 17:27:41 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem_in

SRCS_NAME =	main.c \
						add_pipe.c \
						check_line.c \
						print_path.c \
						add_room.c \
						ft_parsing.c \
						resolve.c \
						build_graph.c

SRCS_PATH       = srcs/
SRCS            = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME        = $(SRCS_NAME:.c=.o)
OBJ_PATH        = obj/
OBJ             = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS           =
INC             = -I./includes/ -I./libft/
LIB             = -L libft -lft\

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
				make -C libft/
				gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
				@mkdir -p obj
				gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
				make -C libft/ fclean
				/bin/rm -rf $(OBJ)

fclean: clean
				/bin/rm -rf $(NAME)

re: fclean all
