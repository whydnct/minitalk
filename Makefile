# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/04/12 21:30:29 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = 	client
NAME_SRV = 		server


CC =        gcc
CFLAGS =    -Wall -Wextra -Werror #-g1 -fsanitize=address


AR =        ar
ARFLAGS =   rcs


#dirs
SRC_DIR =           ./src/
OBJ_DIR =           ./obj/
LIBFT_DIR =         ./libft/
INC =               ./include/


#files
SRC_FILES = client.c server.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIBFT_A = 	libft.a


#paths
SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT       = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

all: obj $(NAME_SRV) $(NAME_CLIENT) $(LIBFT)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I $(INC) -c -o $@ $<


$(LIBFT):
	@make -sC $(LIBFT_DIR)


$(NAME_SRV): $(LIBFT) $(OBJS)
	@echo "starting server compilation"
	@$(CC) $(CFLAGS) $(OBJ_DIR)server.o $(LIBFT) -o $(NAME_SRV)


$(NAME_CLIENT): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ_DIR)client.o -o $(NAME_CLIENT)


clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -Rf $(OBJ_DIR)


fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME_CLIENT)
	@rm -f $(NAME_SRV)


re: fclean all


.PHONY: all clean fclean re


# RULES

# target: prerequisites
#   command
#   command

# if there's a file with the same name of the target
# commands won't run. This is why .PHONY exists

# $@ = target
# $^ = all prerequisites
# $> = first prerequisite
# TODO: está bien meter la .PHONY $(NEW_LIB_A) para que
# recompile siempre la librería? como no tiene .o para comparar
# con src creo que va a recompilarla siempre, y no sé si eso es correcto
# esto viene de intentar incorporar cambios en libft.