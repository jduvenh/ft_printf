# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 11:11:55 by jduvenh           #+#    #+#              #
#    Updated: 2018/08/05 13:15:56 by jduvenh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src/

LIB_DIR = libft/


SRC_FILES = ft_print_attr.c \
		   	ft_print_bin.c \
			ft_print_hex.c \
			ft_print_nbr.c \
			ft_print_oct.c \
			ft_print_signed.c \
			ft_print_spec.c \
			ft_print_text.c \
			ft_print_unsigned.c \
			ft_printf.c
LIBFT_FILES = ft_atoi.c \
			  ft_bzero.c \
			  ft_isdigit.c \
			  ft_memalloc.c \
			  ft_putchar.c \
			  ft_putnchar.c \
			  ft_putstr.c \
			  ft_putunbr.c \
			  ft_putwchar.c \
			  ft_putwstr.c \
			  ft_strdup.c \
			  ft_strlen.c \
			  ft_strncpy.c \
			  ft_strrev.c \
			  ft_strsub.c \
			  ft_strtolower.c \
			  ft_wclen.c \
			  ft_wcscpy.c \
			  ft_wcsdup.c \
			  ft_wcslen.c \
			  ft_wcsncpy.c \
			  ft_wcsnew.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))

OBJ = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

INC = -Iincludes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "Compiling... PLESE BE PATIENT........."
	@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf.a created".

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

# phony
.PHONY: all clean fclean re
