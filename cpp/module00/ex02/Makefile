# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:01:52 by njaros            #+#    #+#              #
#    Updated: 2022/05/13 18:37:42 by njaros           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = exe
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

PATH_SRCS = src
PATH_OBJS = obj
PATH_INCLUDES = includes

LST_SRCS =	tests.cpp \
			Account.cpp
LST_OBJS =	${LST_SRCS:.cpp=.o}
LST_INCLUDES =	Account.hpp

SRC =		$(addprefix ${PATH_SRCS}/,${LST_SRCS})
OBJS =		$(addprefix ${PATH_OBJS}/,${LST_OBJS})
INCLUDES =	$(addprefix ${PATH_INCLUDES}/,${LST_INCLUDES})

all :				${NAME} Makefile

${NAME} :			${OBJS}
					${CC} ${FLAGS} ${OBJS} -o $@

${PATH_OBJS}/%.o:	${PATH_SRCS}/%.cpp ${INCLUDES} Makefile | ${PATH_OBJS}
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

${PATH_OBJS}:
					mkdir obj

clean :
					rm -rf obj

fclean :			clean
					rm ${NAME}

re :				fclean all

.PHONY: all re clean fclean