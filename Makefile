# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 10:59:33 by danpalac          #+#    #+#              #
#    Updated: 2024/07/12 13:44:20 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================COLORS=============================================#

BOLD_BLACK		:= \033[1;30m
BOLD_RED		:= \033[1;31m
BOLD_GREEN		:= \033[1;32m
BOLD_YELLOW		:= \033[1;33m
BOLD_BLUE		:= \033[1;34m
BOLD_PURPLE		:= \033[1;35m
BOLD_CYAN		:= \033[1;36m
BOLD_WHITE		:= \033[1;37m
BLACK			:= \033[0;30m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
WHITE			:= \033[0;37m
GRAY			:= \033[0;90m
LIGHT_RED		:= \033[0;91m
LIGHT_GREEN		:= \033[0;92m
LIGHT_YELLOW	:= \033[0;93m
LIGHT_BLUE		:= \033[0;94m
LIGHT_PURPLE	:= \033[0;95m
LIGHT_CYAN		:= \033[0;96m
LIGHT_WHITE		:= \033[0;97m
NO_COLOR		:= \033[0m
DEF_COLOR		:= \033[0;39m

#==============================VARIABLES=============================================#

NAME	= push_swap
LIBFT	= $(LIBFT_DIR)libft.a

#===============================COMPILER============================================#

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -g3 -fsanitize=address
LDFLAGS	= -L$(LIBFT_DIR) -lft -lm
MKDIR	= mkdir -p
IFLAGS	= -I$(INC) -I$(LIBFT_INC) 

#==============================DIRECTORIES============================================#

SRCS_DIR		:= src/
OBJS_DIR		:= obj/
LIBFT_DIR		:= libft/
LIBFT_INC		:= $(LIBFT_DIR)inc/
INC				:= inc/

#==============================SOURCES============================================#

FILES := push_swap stack_utils

# ==============================FILES============================================#

SRCS_FILES += $(FILES)

SRCS		:= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		:= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
DEPS		:= $(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES)))

#==============================RULES=============================================#

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make fclean -sC $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)$(NAME) $(YELLOW) cleaned$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.SILENT: all clean fclean
