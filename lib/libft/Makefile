# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/04/14 10:53:02 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRC_DIR   source directory
# SRCS      source files
#
# BUILD_DIR object directory
# OBJS      object files
# DEPS      dependency files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

SRC_DIR     := src
SRCS        :=  \
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
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    bonus/ft_lstnew_bonus.c \
    bonus/ft_lstadd_front_bonus.c \
    bonus/ft_lstsize_bonus.c \
    bonus/ft_lstlast_bonus.c \
    bonus/ft_lstadd_back_bonus.c \
    bonus/ft_lstdelone_bonus.c \
    bonus/ft_lstclear_bonus.c \
    bonus/ft_lstiter_bonus.c \
    bonus/ft_lstmap_bonus.c

SRCS        := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I include
AR          := ar
ARFLAGS     := -r -c -s

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> library
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re
.SILENT:
