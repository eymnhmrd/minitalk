# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:39:35 by ahamrad           #+#    #+#              #
#    Updated: 2023/03/18 03:09:19 by ahamrad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC = utils.c
SRC_S = server.c
SRC_C = client.c

OBJ = $(SRC:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ) $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ) $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_S) -o $(NAME_S)

clean:
	$(RM) $(OBJ) $(OBJ_C) $(OBJ_S)
	
fclean: clean
	$(RM) $(NAME_C) $(NAME_S)

re: fclean all
