NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi ft_atol ft_bzero  ft_calloc ft_isalnum ft_isalpha \
	ft_isascii ft_isdigit ft_isprint ft_itoa \
	ft_lltoa \
	ft_memccpy ft_memchr \
	ft_memcmp ft_memcpy ft_memmove ft_memset ft_split ft_strchr \
	ft_strdup ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strncmp \
	ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper \
	ft_split ft_itoa ft_putchar_fd ft_putstr_fd \
	ft_putendl_fd ft_putnbr_fd ft_strmapi \
	btree_create_node btree_apply_prefix btree_apply_infix btree_apply_suffix \
	btree_search_item btree_level_count btree_insert_data

OBJS = $(addsuffix .o,$(SRCS))

SRCS_BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
ft_lstadd_back ft_lstclear ft_lstdelone ft_lstiter ft_lstmap

OBJS_BONUS = $(addsuffix .o,$(SRCS_BONUS))

CORE = ft_printf.o a_parsing.o b_sizing.o

CONV = conv/conv_format.o conv/c_conv.o conv/s_conv.o conv/p_conv.o\
	conv/di_conv.o conv/uxx_conv.o conv/n_conv.o conv/f_conv.o \
	conv/double_extraction.o conv/float_rounding.o conv/check_floats.o

PRINTF_OBJS = $(addprefix printf/, $(CORE) $(CONV))

.PHONY : clean fclean re all so bonus

all :	${NAME}
$(NAME) : ${OBJS} ${PRINTF_OBJS} bonus
		ar rcs ${NAME} ${OBJS} ${PRINTF_OBJS}

clean :
	rm -f ${OBJS} ${OBJS_BONUS} ${PRINTF_OBJS}

fclean : clean
	rm -f ${NAME} *.a *.so

re : fclean all

bonus : ${OBJS_BONUS}
	ar rcs ${NAME} ${OBJS_BONUS}

so : 
	rm *.o *.a
	gcc ft*.c -c -fpic
	gcc *.o -shared -o libft.so
