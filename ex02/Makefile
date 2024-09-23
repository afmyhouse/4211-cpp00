# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 21:23:27 by antoda-s          #+#    #+#              #
#    Updated: 2024/04/19 15:30:35 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compilation, linking and cleaning commands/flags
CXX	= c++
CF	= -Wall -Wextra -Werror -pedantic -std=c++98
MKF	= --no-print-directory
AR	= ar -rcs

# sources and objects folders

INCSD 	= include/
SRCSD 	= sources/
SUBSD	= .
VPATH	= $(SRCSD) $(addprefix $(SRCSD)/, $(SUBSD))
OBJSD 	= build/

# files
NAME 	= bank
FILES	= tests Account
OBJS	= $(FILES:%=%.o)
TARGET	= $(addprefix $(OBJSD), $(OBJS))

# valgrind
LEAKS 		= valgrind
LEAKS_FILE	= valgrind-log.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./$(NAME)

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
CYN		=	\33[1;36m
RESET	=	\033[0m
BOLD	=	\033[1m

# messages
_INFO		=	$(WTH)[$(CYN) INFO$(WTH)]
_SUCCESS	=	$(WTH)[$(GRN)$(BOLD)READY$(WTH)]
_WARNING	=	$(WTH)[$(YLW)WARNING$(WTH)]
_ERROR		=	$(WTH)[$(RED)ERROR$(WTH)]

# rules
all: $(NAME)
	@printf "\n$(_SUCCESS) $(GRN)$(NAME) executable ready!$(WTH)\n\n"

$(NAME): $(OBJSD) $(TARGET)
	@printf "\n$(_SUCCESS) $(GRN)$(NAME) objects ready!                $(WTH)\n"
	@printf "\n$(_INFO) $(CYN)Linking $(NAME) executable...$(WTH)\n"
	$(CXX) $(CF) $(TARGET) -o $@ -I $(INCSD)
	@printf "$(GRN)█$(WHT)"

$(OBJSD)%.o: $(SRCDIR)%.cpp
	@printf "$(_INFO) $(CYN)Compiling source files...$(WTH)%-33.33s\r" $@
	$(CXX) $(CF) -c $< -o $@ -I $(INCSD)
	@printf "$(YLW)█$(WHT)"

$(OBJSD):
	@mkdir -p $(OBJSD)
#	@printf "\n$(_INFO) $(CYN)Compiling source files...$(WTH)\n"

leaks:
	$(LEAKS) $(LF)
	@printf "$(GRN)Leaks log ready! Check valgrind-out.txt $(WTH)\n\n"

cleanleaks:
	@$(RM) $(LEAKS_FILE)

clean:
	@printf "\n$(YLW)Cleaning all object files from project...$(WTH)\n"
	@$(RM) -rf $(OBJS)
	@$(RM) -rf $(OBJSD)
	@printf "$(GRN)All object files removed!$(WTH)\n\n"

fclean: clean
	@printf "\n$(YLW)Cleaning $(NAME) and additional files...$(WTH)\n"
	@$(RM) -rf $(NAME)
	@printf "$(GRN)$(NAME) and additional files removed!$(WTH)\n\n"
	@printf "$(YLW)Cleaning Leaks log file.$(WTH)\n"
	@make -s cleanleaks
	@printf "$(GRN)Leaks log file deleted.$(WTH)\n\n"

re: fclean all

run: re
	./$(NAME)

show:
	@printf "\n"
	@printf "$(YLW)ALL PATHS (*invoked with > make show*) $(WTH)]\n"
	@printf "\n"
	@printf "$(YLW)██ Current directory    : $(WTH)$(CURDIR) $(WTH)\n"
	@printf "$(RED)██ Sources directory    : $(WTH)./$(SRCSD)$(WTH)\n"
	@printf "$(YLW)██ Include directory    : $(WTH)./$(INCSD)\n"
	@printf "$(CYN)██ Objects Directory    : $(WTH)./$(OBJSD)$(WTH)\n"
	@printf "$(YLW)██ Executable directory : $(WTH)$(CURDIR) $(WTH)\n"
	@printf "\n"
	@printf "$(RED)██ Sources files        : $(WTH)$(notdir $(FILES))\n"
	@printf "$(CYN)██ Objects files        : $(WTH)$(notdir $(OBJS))\n"
	@printf "$(YLW)██ Executable file      : $(WTH)$(notdir $(NAME))\n"
	@printf "\n"

.PHONY: all leaks cleanleaks clean fclean re show

#.SILENT:
