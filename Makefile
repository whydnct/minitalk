# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/03/17 15:31:54 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME_SRV = server
NAME_CLIENT = client
BIN_PATH = bin

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g1 -fsanitize=address

AR = ar
ARFLAGS = rcs

SRC_CLIENT_PATH = src/client
SRC_SERVER_PATH = src/server
SRC = main.c

INCLUDE = $(SRC_PATH)/minitalk.h

OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# produces obj/moves_push.o obj/moves_reverse_rotate.o ...

LIB_PATH = lib
LIB_H = $(LIB_PATH)/libft.h
LIB_A = $(LIB_PATH)/libft.a
NEW_LIB_A = $(LIB_PATH)/libminitalk.a

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


all: $(NAME_SRV) $(NAME_CLIENT)

re: fclean all

clean:
	@rm -rf $(OBJ_PATH)
	@rm -f ./client
	@rm -f ./server

fclean:	clean
	@rm -rf $(BIN_PATH)
	@rm -rf *.dSYM

$(OBJ_PATH):
	@mkdir -p $@

$(BIN_PATH):
	@mkdir -p $@

$(LIB_PATH):
	@mkdir -p $@

#$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH) $(LIB_PATH)
#	$(CC) $(CFLAGS) -c $^ -o $@

$(LIB_A): $(LIB_PATH) 
	@make -C ./libft
	@cp libft/libft.a $(LIB_A)

$(NAME_SRV): $(LIB_A) | $(BIN_PATH)
	@$(CC) $(CFLAGS) $(SRC_SERVER_PATH)/main.c -L$(LIB_PATH) -lft -o $(BIN_PATH)/$(NAME_SRV)
	@$(CC) $(CFLAGS) $(SRC_SERVER_PATH)/main.c -L$(LIB_PATH) -lft -o $(NAME_SRV)

$(NAME_CLIENT): $(LIB_A) | $(BIN_PATH)
	@$(CC) $(CFLAGS) $(SRC_CLIENT_PATH)/main.c -L$(LIB_PATH) -lft -o $(BIN_PATH)/$(NAME_CLIENT)
	@$(CC) $(CFLAGS) $(SRC_CLIENT_PATH)/main.c -L$(LIB_PATH) -lft -o $(NAME_CLIENT)


.PHONY: clean fclean re $(NEW_LIB_A)
