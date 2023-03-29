# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:39:35 by ahamrad           #+#    #+#              #
#    Updated: 2023/03/25 20:45:40 by ahamrad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
HEADER = minitalk.h

SRC = utils.c
SRC_S = server.c
SRC_C = client.c

OBJ = utils.o
OBJ_S = server.o
OBJ_C = client.o

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ) $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ) $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_S) -o $(NAME_S)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	$(RM) $(OBJ) $(OBJ_C) $(OBJ_S)
	
fclean: clean
	$(RM) $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re