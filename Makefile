# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:31:23 by sguzman           #+#    #+#              #
#    Updated: 2024/01/04 19:28:06 by sguzman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #    

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		= push_swap
BNAME		= checker
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
DFLAGS	= -MMD -MF $(@:.o=.d)

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_PATH	= ./src

EXT_PATH	= ./external

INCLUDE_PATH	= ./include

HEADER	= $(INCLUDE_PATH)/push_swap.h

EXT_HEADER  = $(EXT_PATH)/get_next_line.h

SRCS =	data_parsing.c push.c reverse.c rotate.c setup_stack.c stack_methods.c swap.c

EXT_SRCS = get_next_line.c get_next_line_utils.c

MAIN =	push_swap.c 

BMAIN = checker.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

OBJS		= $(addprefix objs/, ${SRCS:.c=.o})

EXT_OBJS	= $(addprefix objs/, ${EXT_SRCS:.c=.o})

OBJS_MAIN	= $(addprefix objs/, ${MAIN:.c=.o})

OBJS_BMAIN	= $(addprefix objs/, ${BMAIN:.c=.o})

DEPS		= $(addprefix objs/, ${SRCS:.c=.d})

EXT_DEPS	= $(addprefix objs/, ${EXT_SRCS:.c=.d})

DEPS_MAIN	= $(addprefix objs/, ${MAIN:.c=.d})

DEPS_BMAIN	= $(addprefix objs/, ${BMAIN:.c=.d})

################################################################################
#                                 Makefile logic                               #
################################################################################

RED         	= \033[0;31m
GREEN       	= \033[0;32m
YELLOW      	= \033[0;33m
BLUE        	= \033[0;34m
PURPLE      	= \033[0;35m
CYAN        	= \033[0;36m
RESET       	= \033[m

################################################################################
#                                 Makefile rules                             #
################################################################################

all: banner $(NAME) 

banner:
	@printf "%b" "$(PURPLE)"
	@echo
	@echo "# **************************************************************************** #"
	@echo "#                                                                              #"
	@echo "#                                                         :::      ::::::::    #"
	@echo "#    push_swap                                          :+:      :+:    :+:    #"
	@echo "#                                                     +:+ +:+         +:+      #"
	@echo "#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #"
	@echo "#                                                 +#+#+#+#+#+   +#+            #"
	@echo "#                                                      #+#    #+#              #"
	@echo "#                                                     ###   ########.fr        #"
	@echo "#                                                                              #"
	@echo "# **************************************************************************** #"
	@echo
	@printf "%b" "$(RESET)"

-include $(DEPS) $(DEPS_MAIN)
$(NAME):	$(OBJS) $(OBJS_MAIN)
			@$(CC) $(CFLAGS) $(DFLAGS) -I $(INCLUDE_PATH) -o $@ $^
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building program:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"

-include $(DEPS) $(EXT_DEPS) $(DEPS_MAIN)
$(BNAME):	$(OBJS) $(EXT_OBJS) $(OBJS_BMAIN)
			@$(CC) $(CFLAGS) $(DFLAGS) -I $(INCLUDE_PATH) -o $@ $^
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building program:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"

bonus:		$(BNAME)
			
objs/%.o: 	$(SRCS_PATH)/%.c $(HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Compiling:" "$(CYAN)" $< "$(GREEN)" "[✓]" "$(RESET)"

objs/%.o: 	$(EXT_PATH)/%.c $(EXT_HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(EXT_PATH)
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Compiling:" "$(CYAN)" $< "$(GREEN)" "[✓]" "$(RESET)"

clean:		banner
			@rm -rf objs 
			@printf "%b%-42s%-42b%b%s%b\n" "$(BLUE)" "$@:" "$(CYAN)" "$(GREEN)" "[✓]" "$(RESET)"

fclean:		banner clean
			@rm -rf $(NAME) $(BNAME)
			@printf "%b%-42s%-42b%b%s%b\n" "$(BLUE)" "$@:" "$(CYAN)" "$(GREEN)" "[✓]" "$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re banner bonus



