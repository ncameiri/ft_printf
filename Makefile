NAME = libftprintf.a
SOURCES = ./sources/structs_init.c ./sources/hexaconvert.c \
./sources/mng_specifier.c ./sources/precision.c\
./sources/print_string.c ./sources/whitespaces_width.c\
./sources/read_width.c ./sources/print_char.c\
./sources/print_i_d.c ./sources/print_hexa.c\
./sources/print_uint.c ./sources/ft_put_unsign.c \
./sources/pointers.c\
./sources/ft_put_unsign.c ./sources/null_string.c\
./sources/pointers.c ./sources/symbols_arg.c\
./sources/zer_write.c

SOURCES_ROOT = ft_printf.c
ROOT_CLEAN = structs_init.o hexaconvert.o mng_specifier.o\
precision.o print_string.o whitespaces_width.o read_width.o\
print_char.o print_i_d.o print_hexa.o putsandcount.o\
print_uint.o ft_put_unsign.o null_string.o\
pointers.o ft_put_unsign.o pointers.o symbols_arg.o zer_write.o
OBJS = $(SOURCES:.c=.o) $(SOURCES_ROOT:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I./includes 

all : $(NAME)

$(NAME) :	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) $(SOURCES_ROOT) 
			ar -rcs $(NAME) $(OBJS)

clean :
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS) $(ROOT_CLEAN)

fclean :	clean
			$(MAKE) fclean -C ./libft 
			$(RM) $(NAME)

re :		fclean all
