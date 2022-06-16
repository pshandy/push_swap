NAME 			= push_swap
CHECKER 		= checker

SRC_DO 			= 	./default_operations/pa_pb.c \
					./default_operations/ra_rb_rr.c \
					./default_operations/rra_rrb_rrr.c \
					./default_operations/sa_sb_ss.c \
					./default_operations/stack_func.c \

SRC_SORT 		=	./sort/closest.c \
					./sort/index_all.c \
					./sort/markup.c \
					./sort/rotate.c \
					./sort/sort_3_5.c \
					./sort/sort_other.c \
					./sort/utils_1.c \
					./sort/utils_2.c \

SRC_INPUT_CHECK	= 	./input_check.c
SRC_MAIN		=	./main.c
SRC_CHECKER		=	./checker.c 

OBJS_DO			= ${SRC_DO:.c=.o}
OBJS_SORT		= ${SRC_SORT:.c=.o}
OBJ_INPUT_CHECK	= ${SRC_INPUT_CHECK:.c=.o}
OBJ_MAIN		= ${SRC_MAIN:.c=.o}
OBJ_CHECKER		= ${SRC_CHECKER:.c=.o}


INCLUDE = ./includes
LIBS	= -L./libft -lft
CFLAGS 	= -Wall -Wextra -Werror

CC = gcc
RM = rm -f

all: $(LIBFT) ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_DO) $(OBJS_SORT) $(OBJ_MAIN) $(OBJ_INPUT_CHECK)
			make -C libft
			${CC} $(CFLAGS) $(LIBS) -I$(INCLUDE) -o $(NAME) $(OBJS_DO) $(OBJS_SORT) $(OBJ_MAIN) $(OBJ_INPUT_CHECK)

$(CHECKER): $(OBJS_DO) $(OBJS_CHECKER) $(OBJ_CHECKER) $(OBJ_INPUT_CHECK)
			make -C libft
			${CC} $(CFLAGS) $(LIBS) -I$(INCLUDE) -o $(CHECKER) $(OBJS_DO) $(OBJS_CHECKER) $(OBJ_CHECKER) $(OBJ_INPUT_CHECK)

clean:
			make clean -C libft
			${RM} ${OBJS_DO} ${OBJS_SORT} ${OBJS_CHECKER} $(OBJ_MAIN) $(OBJ_INPUT_CHECK) $(OBJ_CHECKER)

fclean: clean
			make fclean -C libft
			${RM} ${NAME} ${CHECKER}

re: fclean all

bonus: checker

.PHONY:		checker bonus all clean fclean re