# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:01:52 by njaros            #+#    #+#              #
#    Updated: 2022/05/24 13:20:26 by njaros           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = materia
CC = g++
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

PATH_SRCS		=	src
PATH_DEP		=	dep
PATH_OBJS		=	obj
PATH_INCLUDES	=	includes

LST_SRCS		=	AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					MateriaSource.cpp \
					main.cpp
LST_OBJS		=	${LST_SRCS:.cpp=.o}
LST_DEP			=	${LST_SRCS:.cpp=.d}
LST_INCLUDES	=	AMateria.hpp \
					Character.hpp \
					Cure.hpp \
					Ice.hpp \
					ICharacter.hpp \
					IMateriaSource.hpp \
					MateriaSource.hpp
SRC =		$(addprefix ${PATH_SRCS}/,${LST_SRCS})
DEP =		$(addprefix ${PATH_DEP}/,${LST_DEP})
OBJS =		$(addprefix ${PATH_OBJS}/,${LST_OBJS})
INCLUDES =	$(addprefix ${PATH_INCLUDES}/,${LST_INCLUDES})

all :				${NAME} Makefile

${NAME} :			${OBJS}
					${CC} ${FLAGS} ${OBJS} -o $@

${PATH_DEP}/%.d :	${PATH_SRCS}/%.cpp Makefile | ${PATH_DEP}
					${CC} ${FLAGS} -MM -MF $@ -MT "${PATH_OBJS}/$*.o $@" $<


${PATH_OBJS}/%.o:	${PATH_SRCS}/%.cpp Makefile | ${PATH_OBJS}
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

${PATH_DEP}:
					mkdir dep

${PATH_OBJS}:
					mkdir obj

clean :
					rm -rf obj dep

fclean :			clean
					rm -f ${NAME}

re :				fclean all

-include ${DEP}

.PHONY: all re clean fclean