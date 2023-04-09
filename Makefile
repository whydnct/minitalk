# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/04/09 19:01:42 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

SRC = $(SERVER).c $(CLIENT).c
SRC_PATH = src

INCLUDE = $(SRC_PATH)/minitalk.h

OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# produces obj/moves_push.o obj/moves_reverse_rotate.o ...

LIB_PATH = lib
LIB_H = $(LIB_PATH)/libft.h
LIB_A = $(LIB_PATH)/libft.a

# RULES

# target: prerequisites
#	command
#	command

# if there's a file with the same name of the target
# commands won't run. This is why .PHONY exists

# $@ = target
# $^ = prerequisite
# TODO: está bien meter la .PHONY $(NEW_LIB_A) para que
# recompile siempre la librería? como no tiene .o para comparar
# con src creo que va a recompilarla siempre, y no sé si eso es correcto
# esto viene de intentar incorporar cambios en libft.


all: $(SERVER) $(CLIENT)

bonus: $(SERVER) $(CLIENT)

re: fclean all

clean:
	@rm -rf $(CLIENT) $(SERVER)

fclean:	clean
	@rm -rf $(BIN_PATH) $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $@

$(BIN_PATH):
	@mkdir -p $@

$(LIB_PATH):
	@mkdir -p $@

$(LIB_A): $(LIB_PATH) 
	@make -C ./libft
	@cp libft/libft.a $(LIB_A)

$(SERVER): $(LIB_A)
	@$(CC) $(CFLAGS) $(SRC_PATH)/$(SERVER).c -L$(LIB_PATH) -lft -o $@

$(CLIENT): $(LIB_A)
	@$(CC) $(CFLAGS) $(SRC_PATH)/$(CLIENT).c -L$(LIB_PATH) -lft -o $@

.PHONY: clean fclean re
