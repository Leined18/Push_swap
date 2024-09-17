# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 00:46:39 by danpalac          #+#    #+#              #
#    Updated: 2024/09/18 00:50:50 by danpalac         ###   ########.fr        #
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
BONUS	= checker
LIBFT	= $(LIBFT_DIR)libft.a

#===============================COMPILER============================================#

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -g3 -fsanitize=address
LDFLAGS	= -L$(LIBFT_DIR) -lft -lm -fsanitize=address
MKDIR	= mkdir -p
IFLAGS	= -I$(INC) -I$(LIBFT_INC) 

#==============================DIRECTORIES=========================================#

SORT_DIR		:= sort_d/
STACK_DIR		:= stack_d/
PS_DIR			:= ps_d/
OP_DIR			:= op_d/
BONUS_DIR		:= bonus_d/
SRCS_DIR		:= src/
OBJS_DIR		:= obj/
LIBFT_DIR		:= libft/
LIBFT_INC		:= $(LIBFT_DIR)inc/
INC				:= inc/

#==============================SOURCES============================================#

PS_FILES	:= check parse
OP_FILES	:= op1 op2
SORT_FILES	:= ksort sort sort_utils
STACK_FILES	:= stack_utils1 stack_utils2
BONUS_FILES := checker_bonus

# ==============================FILES============================================#

# Archivos de Push_Swap (con el main en push_swap.c)
PS_SRCS_FILES := push_swap $(PS_FILES)
SRCS_FILES +=$(addprefix $(PS_DIR), $(PS_SRCS_FILES))
SRCS_FILES +=$(addprefix $(OP_DIR), $(OP_FILES))
SRCS_FILES +=$(addprefix $(SORT_DIR), $(SORT_FILES))
SRCS_FILES +=$(addprefix $(STACK_DIR), $(STACK_FILES))

# Archivos de Checker (sin push_swap.c, pero con checker_bonus.c)
BONUS_SRCS_FILES +=$(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_SRCS_FILES +=$(addprefix $(OP_DIR), $(OP_FILES))
BONUS_SRCS_FILES +=$(addprefix $(SORT_DIR), $(SORT_FILES))
BONUS_SRCS_FILES +=$(addprefix $(STACK_DIR), $(STACK_FILES))
BONUS_SRCS_FILES +=$(addprefix $(PS_DIR), $(PS_FILES))

SRCS	:= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
BONUS_SRCS := $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_SRCS_FILES)))

OBJS	:= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
BONUS_OBJS := $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_SRCS_FILES)))

DEPS	:= $(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES)))
BONUS_DEPS := $(addprefix $(OBJS_DIR), $(addsuffix .d, $(BONUS_SRCS_FILES)))

#==============================RULES=============================================#

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(BONUS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(BOLD_CYAN)[$(BOLD_PURPLE)$(NAME)$(DEF_COLOR)$(BOLD_CYAN)] compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS)
	@echo "$(BOLD_GREEN)[$(BOLD_PURPLE)$(BONUS)$(DEF_COLOR)$(BOLD_GREEN)] compiled!$(DEF_COLOR)"
	@echo "$(BOLD_GREEN)--------------------\n| Checker Done! 📝 |\n--------------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -rf $(NAME) $(BONUS)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(CYAN)[$(NAME)]:\texec. files $(GREEN) => Cleaned!$(DEF_COLOR)"
	
norm:
	@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

re: fclean all

rebonus: fclean bonus

-include $(DEPS)
-include $(BONUS_DEPS)

.SILENT: all clean fclean
