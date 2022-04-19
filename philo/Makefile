# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 07:33:54 by ael-korc          #+#    #+#              #
#    Updated: 2022/04/10 07:33:55 by ael-korc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM	= rm -f

CC = gcc -Wall -Wextra -Werror

NAME= philo

SRC	=	./main.c\
		./parser_arg.c\
		./cycle_philosopher.c\
		./utils.c\
		./utils2.c\
		./init.c\

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) 

clean	:
	rm -f $(NAME) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re	: clean all