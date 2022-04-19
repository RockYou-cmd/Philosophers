# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 03:12:05 by ael-korc          #+#    #+#              #
#    Updated: 2022/04/10 07:28:32 by ael-korc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM	= rm -f

CC = gcc -Wall -Wextra -Werror

NAME= philo_bonus

SRC	=	./main.c\
		./parser_arg.c\
		./cycle_philosopher.c\
		./utils.c\
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
