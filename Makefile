#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020#06#22 10:19:48 by matrus            #+#    #+#             *#
#*   Updated: 2020#06#22 10:19:48 by matrus           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=libftprintf.a
INCLUDES=ft_printf.h

DIRIDU=print_idu
DIRCS=print_cs
DIRXX=print_xx
DIRPCT=print_pct
DIRP=print_p
DIRF=print_f

SRCROOT=./parse.c ./ft_printf.c
SRCIDU=$(wildcard $(DIRIDU)/*.c)
SRCCS=$(wildcard $(DIRCS)/*.c)
SRCXX=$(wildcard $(DIRXX)/*.c)
SRCPCT=$(wildcard $(DIRPCT)/*.c)
SRCP=$(wildcard $(DIRP)/*.c)
SRCF=$(wildcard $(DIRF)/*.c)

OBJDIR=obj
OBJROOT=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCROOT)))
OBJCS=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCCS)))
OBJIDU=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCIDU)))
OBJXX=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCXX)))
OBJPCT=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCPCT)))
OBJP=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCP)))
OBJF=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRCF)))
OBJALL=$(OBJROOT) $(OBJIDU) $(OBJCS) $(OBJXX) $(OBJPCT) $(OBJP) $(OBJF)

LIBFTNAME=libft.a
LIBFTDIR=libft

CCFLAGS=-Wall -Werror -Wextra
CC=gcc

.PHONY: all
all: libft $(NAME)

$(NAME): $(OBJDIR) $(OBJALL)
	cd $(OBJDIR) && ar -x ../$(LIBFTDIR)/$(LIBFTNAME) && ar rc ../$(NAME) *.o

$(OBJROOT): $(OBJDIR)/%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

$(OBJIDU): $(OBJDIR)/%.o: $(DIRIDU)/%.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

$(OBJCS): $(OBJDIR)/%.o: $(DIRCS)/%.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

$(OBJPCT): $(OBJDIR)/%.o: $(DIRPCT)/%.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

$(OBJXX): $(OBJDIR)/%.o: $(DIRXX)/%.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

$(OBJP): $(OBJDIR)/%.o: $(DIRP)/%.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

$(OBJF): $(OBJDIR)/%.o: $(DIRF)/%.c $(INCLUDES)
	$(CC) $(CCFLAGS) -I. -I./$(LIBFTDIR) -c $< -o $@

.PHONY: libft
libft:
	cd $(LIBFTDIR) && make

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	cd $(LIBFTDIR) && make clean
	cd $(BONUSDIR) && rm -rf *.o
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	cd $(LIBFTDIR) && make fclean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
