# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 11:55:23 by bvarea-k          #+#    #+#              #
#    Updated: 2025/10/22 12:30:26 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#Colours
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#Directories
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE = -I include

#Files
SRC_FILES = init ft_atoi error checker

#Full paths
SRC_DIR = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ_DIR = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_OBJ)))

#Rules
all: $(NAME)

DIRS:
	@mkdir -p $(OBJ_DIR)
	@echo "$(MAGENTA)[DIRS] Created obj/ directory$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[BUILD] Executable created: $(NAME)$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | DIRS
	@echo "$(CYAN)[COMPILING] $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[CLEAN] Object files removed$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Cleaned all files and executables$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re