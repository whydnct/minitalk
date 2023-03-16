# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/03/09 17:45:01 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rsc

SRC_PATH = src/
SRC = \
	ft_atoi.c \
    ft_bzero.c \
    ft_isascii.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_strchr.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strncmp.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_tolower.c \
    ft_toupper.c \
    ft_calloc.c \
    ft_memchr.c \
    ft_strdup.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_itoa.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c

SRC_BONUS = \
    ft_lstnew_bonus.c \
    ft_lstadd_front_bonus.c \
    ft_lstsize_bonus.c \
    ft_lstlast_bonus.c \
    ft_lstadd_back_bonus.c \
    ft_lstdelone_bonus.c \
    ft_lstclear_bonus.c \
    ft_lstiter_bonus.c \
    ft_lstmap_bonus.c

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_PATH),$(SRC_BONUS:.c=.o))


all: $(NAME) bonus

$(OBJ_PATH):
	@mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) -c $(CFLAGS) $^ -o $@

bonus: $(OBJ_BONUS) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $^

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ) | $(OBJ_PATH)
	@$(AR) $(ARFLAGS) $(NAME) $^

.PHONY: all, clean, fclean, re, bonus
