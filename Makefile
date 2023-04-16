# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2023/04/16 10:18:55 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT := client
NAME_SERVER	:= server
NAME_CLIENT_B := client_bonus
NAME_SERVER_B	:= server_bonus

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS        libraries to be used
# LIBS_TARGET libraries to be built
#
# INCS        header file locations
#
# SRC_DIR     source directory
# SRCS        source files
#
# BUILD_DIR   build directory
# OBJS        object files
# DEPS        dependency files
#
# CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
# LDFLAGS     linker flags
# LDLIBS      libraries name

LIBS        := ft  
LIBS_TARGET := lib/libft/libft.a 

INCS        := include \
	lib/libft/include

SRC_DIR     	:= src
SRCS_SERVER 	:= server.c
SRCS_CLIENT 	:= client.c
SRCS_SERVER_B	:= server_bonus.c
SRCS_CLIENT_B 	:= client_bonus.c
SRCS_SERVER 	:= $(SRCS_SERVER:%=$(SRC_DIR)/%)
SRCS_CLIENT 	:= $(SRCS_CLIENT:%=$(SRC_DIR)/%)
SRCS_SERVER_B 	:= $(SRCS_SERVER_B:%=$(SRC_DIR)/%)
SRCS_CLIENT_B 	:= $(SRCS_CLIENT_B:%=$(SRC_DIR)/%)

BUILD_DIR   := .build
OBJS_SERVER := $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SERVER := $(OBJS_SERVER:.o=.d)
OBJS_CLIENT := $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_CLIENT := $(OBJS_CLIENT:.o=.d)
OBJS_SERVER_B := $(SRCS_SERVER_B:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SERVER_B := $(OBJS_SERVER_B:.o=.d)
OBJS_CLIENT_B := $(SRCS_CLIENT_B:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_CLIENT_B := $(OBJS_CLIENT_B:.o=.d)

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> archive
# $(LIBS)   build libraries
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# run       run the program
# info      print the default goal recipe

all: $(NAME_CLIENT) $(NAME_SERVER)
bonus: $(NAME_CLIENT_B) $(NAME_SERVER_B)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)
	$(info CREATED $(NAME_CLIENT))

$(NAME_SERVER): $(OBJS_SERVER) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SERVER) $(LDLIBS) -o $(NAME_SERVER)
	$(info CREATED $(NAME_SERVER))

$(NAME_CLIENT_B): $(OBJS_CLIENT_B) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_CLIENT_B) $(LDLIBS) -o $(NAME_CLIENT_B)
	$(info CREATED $(NAME_CLIENT_B))

$(NAME_SERVER_B): $(OBJS_SERVER_B) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SERVER_B) $(LDLIBS) -o $(NAME_SERVER_B)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS_SERVER) $(DEPS_CLIENT) $(DEPS_SERVER_B) $(DEPS_CLIENT_B)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(DEPS_SERVER) $(DEPS_CLIENT)
	$(RM) $(OBJS_SERVER_B) $(OBJS_CLIENT_B) $(DEPS_SERVER_B) $(DEPS_CLIENT_B)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER_B) $(NAME_CLIENT_B)

re:
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re
.SILENT:
