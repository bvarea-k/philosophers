# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 11:55:23 by bvarea-k          #+#    #+#              #
#    Updated: 2025/10/25 16:27:10 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Colours
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
CYAN = \033[0;96m
MAGENTA = \033[0;95m

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE = -I include

# Source files (sin extensiones ni path)
SRC_FILES = main init ft_atol error checker free routine actions

# Full paths
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Rules
all: $(NAME)

DIRS:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[BUILD] Executable created: $(NAME)$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | DIRS
	@echo "$(CYAN)[COMPILING] $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Cleaned all files and executables$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re DIRS

