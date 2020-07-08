#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020#05#07 14:56:02 by matrus            #+#    #+#             *#
#*   Updated: 2020#05#07 14:56:02 by matrus           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a
INCLUDES = libft.h
RAWSRC = memset.c bzero.c memcpy.c memccpy.c memmove.c memchr.c memcmp.c \
	  strlen.c strlcpy.c strlcat.c strrchr.c strchr.c strnstr.c strncmp.c \
	  atoi.c atol.c\
	  isalpha.c isdigit.c isalnum.c isascii.c isprint.c toupper.c tolower.c \
	  calloc.c strdup.c \
	  substr.c strjoin.c strtrim.c split.c itoa.c strmapi.c \
	  putchar_fd.c putstr_fd.c putendl_fd.c putnbr_fd.c \
      lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c \
	  lstdelone.c lstclear.c lstiter.c lstmap.c \
	  ullen.c ilen.c llen.c \
	  lmax.c lmin.c

SRC = $(RAWSRC:%=ft_%)
OBJDIR = ./obj/
OBJ = $(SRC:%.c=$(OBJDIR)%.o)
CCFLAGS = -Wall -Werror -Wextra
CC = gcc

.PHONY: all
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): $(OBJDIR)%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
