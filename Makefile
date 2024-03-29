# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:31:23 by sguzman           #+#    #+#              #
#    Updated: 2024/01/22 00:00:00 by sguzman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #    

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		= push_swap
BNAME		= checker
CC 		= cc
CFLAGS		= -Wall -Wextra -Werror -g
DFLAGS		= -MMD -MF $(@:.o=.d)

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_PATH	= ./src

OBJS_PATH 	= ./build

EXT_PATH	= ./external

INCLUDE_PATH	= ./include

HEADER		= $(INCLUDE_PATH)/push_swap.h

EXT_HEADER  	= $(EXT_PATH)/get_next_line.h

SRCS 		= data_parsing.c instructions.c output.c push.c reverse.c rotate.c setup_stack.c shaker.c smash.c stack_methods.c swap.c

EXT_SRCS 	= get_next_line.c get_next_line_utils.c

MAIN 		= push_swap.c 

BMAIN 		= checker.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

OBJS		= $(addprefix $(OBJS_PATH)/, ${SRCS:.c=.o})

EXT_OBJS	= $(addprefix $(OBJS_PATH)/, ${EXT_SRCS:.c=.o})

OBJS_MAIN	= $(addprefix $(OBJS_PATH)/, ${MAIN:.c=.o})

OBJS_BMAIN	= $(addprefix $(OBJS_PATH)/, ${BMAIN:.c=.o})

DEPS		= $(addprefix $(OBJS_PATH)/, ${SRCS:.c=.d})

EXT_DEPS	= $(addprefix $(OBJS_PATH)/, ${EXT_SRCS:.c=.d})

DEPS_MAIN	= $(addprefix $(OBJS_PATH)/, ${MAIN:.c=.d})

DEPS_BMAIN	= $(addprefix $(OBJS_PATH)/, ${BMAIN:.c=.d})

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

ELEMENTS ?= 3
TESTS ?= 10
INSTRUCTIONS_LIST :=

define run_test
	$(eval ARG := $(shell shuf -i 0-$(ELEMENTS) -n $(ELEMENTS)))
	$(eval INSTRUCTIONS := $(shell ./$(NAME) $(ARG) | wc -l))
	@if ./$(NAME) $(ARG) | ./$(BNAME) $(ARG) | grep -q "OK"; then \
		printf "\n%b%s\n%b%s%s\n%b%s%s\t%b%s%b\n" "$(YELLOW)" "Running Test:" "$(CYAN)" "ARG=" "$(ARG)" "$(PURPLE)" "Instructions:" "$(INSTRUCTIONS)" "$(GREEN)" "[✓]" "$(RESET)"; \
		$(eval INSTRUCTIONS_LIST += $(INSTRUCTIONS)) \
	else \
		printf "\n%b%s\n%b%s%s\n%b%s%s\t%b%s%b\n" "$(YELLOW)" "Error in Test:" "$(CYAN)" "ARG=" "$(ARG)" "$(PURPLE)" "Instructions:" "$(INSTRUCTIONS)" "$(RED)" "[✗]" "$(RESET)" >&2; \
		exit 1; \
	fi
endef

################################################################################
#                                 Makefile rules                               #
################################################################################

all: banner $(NAME) 

bonus:	banner $(BNAME)
                                                             
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

-include $(DEPS) $(EXT_DEPS) $(DEPS_BMAIN)
$(NAME):	$(OBJS) $(OBJS_MAIN)
			@$(CC) $(CFLAGS) $(DFLAGS) -I $(INCLUDE_PATH) -o $@ $^
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building program:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"

$(BNAME):	$(OBJS) $(EXT_OBJS) $(OBJS_BMAIN)
			@$(CC) $(CFLAGS) $(DFLAGS) -I $(INCLUDE_PATH) -o $@ $^
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Building program:" "$(CYAN)" $@ "$(GREEN)" "[✓]" "$(RESET)"
			
$(OBJS_PATH)/%.o: 	$(SRCS_PATH)/%.c $(HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Compiling:" "$(CYAN)" $< "$(GREEN)" "[✓]" "$(RESET)"

$(OBJS_PATH)/%.o: 	$(EXT_PATH)/%.c $(EXT_HEADER) Makefile
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(EXT_PATH)
			@printf "%b%-42s%-42b%-24s%b%s%b\n" "$(BLUE)" "Compiling:" "$(CYAN)" $< "$(GREEN)" "[✓]" "$(RESET)"

test:		all bonus
			@$(foreach _, $(shell seq $(TESTS)), $(call run_test)) 
			@$(eval MIN := $(shell echo $(INSTRUCTIONS_LIST) | tr ' ' '\n' | sort -n | head -n 1))
			@$(eval MAX := $(shell echo $(INSTRUCTIONS_LIST) | tr ' ' '\n' | sort -n | tail -n 1))
			@$(eval AVERAGE := $(shell echo $(INSTRUCTIONS_LIST) | tr ' ' '\n' | awk '{sum += $$1} END {print sum / NR}'))
			@printf "\n%b%s%b\n" "$(YELLOW)" "TEST SUMMARY" "$(RESET)"
			@printf "%b%s\t%b%s%b\n" "$(PURPLE)" "MIN :" "$(CYAN)" "$(MIN)" "$(RESET)"
			@printf "%b%s\t%b%s%b\n" "$(PURPLE)" "MAX :" "$(CYAN)" "$(MAX)" "$(RESET)"
			@printf "%b%s\t%b%s%b\n" "$(PURPLE)" "AVG :" "$(CYAN)" "$(AVERAGE)" "$(RESET)"
		        

clean:		banner
			@rm -rf $(OBJS_PATH)
			@printf "%b%-42s%-42b%b%s%b\n" "$(BLUE)" "$@:" "$(CYAN)" "$(GREEN)" "[✓]" "$(RESET)"

fclean:		banner clean
			@rm -rf $(NAME) $(BNAME)
			@printf "%b%-42s%-42b%b%s%b\n" "$(BLUE)" "$@:" "$(CYAN)" "$(GREEN)" "[✓]" "$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re banner bonus




