# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 14:44:13 by azahajur          #+#    #+#              #
#    Updated: 2023/07/23 16:36:54 by azahajur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c\
		ft_putnbr_hex.c ft_putnbr_ptr.c	ft_putnbr_u.c\

# Genera los archivos .o para cada archivo .c
OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
# Solo se compilan los archivos que han cambiado. (Es una regla de cancelación, evita que se recompilen archivos que no se han actualizado).
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
	
# Borra todos los archivos de la variable OBJ
clean:
	rm -f $(OBJ)
	
# Borra todos los archivos de la variable OBJ y NAME
fclean: clean
	rm -f $(NAME) $(OBJ)
	
# Hace un re-make, borra todo y ejecuta el Make como si fuera la primera vez.
re: fclean all 

# le dice al make que estos nombres no son archivos
.PHONY: re all fclean clean