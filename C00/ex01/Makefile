# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 10:03:28 by vduchi            #+#    #+#              #
#    Updated: 2024/02/22 23:40:32 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=-=-=-=-=-=-=- COLORS DEFINITION =-=-=-=-=-=-=-=-=-#

DEL_LINE		=	\033[2K
ITALIC			=	\033[3m
BOLD			=	\033[1m
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m

NAME		=	phonebook

SRCS_DIR	=	src
INCS_DIR	=	inc

SRCS		=	src/main.cpp
SRCS		+=	src/Contact.cpp
SRCS		+=	src/PhoneBook.cpp
OBJS		=	$(SRCS:.cpp=.o)
DEPS		=	$(SRCS:.cpp=.d)

CPPFLAGS	+=	-Wall -Werror -Wextra -std=c++98 -pedantic-errors -MMD $(addprefix -I , $(INCS_DIR))

CXX			=	c++
RM			=	rm -rf
MAKE		=	make --no-print-directory

%.o		:	%.cpp
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)$<	\tcompiled!$(DEF_COLOR)"

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CXX) $(CPPFLAGS) $^ -o $@
	@echo "$(GREEN)Executable $@ compiled!$(DEF_COLOR)"

clean	:
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)
	@echo "$(BLUE)Project cleaned!$(DEF_COLOR)"

re		:	fclean all

.PHONY: all clean fclean re

-include $(DEPS)
