NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRCS = sources/ft_printf.c \
	sources/base.c \
	sources/ft_recup_flags.c \
	sources/ft_treat_character.c \
	sources/ft_treat_hexa.c \
	sources/ft_treat_integer.c \
	sources/ft_treatment.c \
	sources/ft_treat_pointeur.c \
	sources/ft_treat_pourcent.c \
	sources/ft_treat_string.c \
	sources/ft_treat_uinteger.c \

LIBFT = libft/ft_strlen.c \
	libft/ft_strdup.c \
	libft/ft_isdigit.c \
	libft/ft_atoi.c \

OBJ = sources/ft_printf.o \
	sources/base.o \
	sources/ft_recup_flags.o \
	sources/ft_treat_character.o \
	sources/ft_treat_hexa.o \
	sources/ft_treat_integer.o \
	sources/ft_treatment.o \
	sources/ft_treat_pointeur.o \
	sources/ft_treat_pourcent.o \
	sources/ft_treat_string.o \
	sources/ft_treat_uinteger.o \
	libft/ft_strlen.o \
	libft/ft_strdup.o \
	libft/ft_isdigit.o \
	libft/ft_atoi.o \

all: $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRCS)
	mv *.o sources/
	gcc $(CFLAGS) -c $(LIBFT)
	mv *.o libft/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)