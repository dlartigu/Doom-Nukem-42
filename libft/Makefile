# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 10:39:25 by dlartigu          #+#    #+#              #
#    Updated: 2020/11/18 22:25:16 by dlartigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## FLAGS ##################

NAME= libft.a
CC = clang
CFLAGS = -Werror -Wall -Wextra
HEADER=libft.h
############## FILES ##################

SRC= ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_range.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_atol.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strclr.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_strndup.c \
		ft_is_word.c \
		ft_wds_nb.c \
		ft_wdl.c \
		ft_strrev.c \
		ft_abs.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_sqrt.c \
		ft_max_2.c \
		ft_swap_int_2.c \
		ft_dmap.c \
		ft_calloc.c \
		ft_tabdel.c \
		ft_min_2.c \
		ft_lstaddend.c \
		ft_lstdelm.c \
		ft_lstnewd.c \
		ft_dmapi.c
############## PATH ##################

OBJECTS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "[OK] Tous les objets sont generes\r"
	@ar rc $(NAME) $(OBJECTS) || printf "\n[ERREUR] Une est erreur est survenue $(NAME)\n"
	@ranlib $(NAME)
	@echo "[OK] Compilation de $(NAME)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS)  -o $@ -c $< && printf "[OK] Generation de %-50s\r" "$@" || \
		(echo "[ERREUR] Une est erreur est survenue sur $<, $(NAME) non compilé(e)\n" && exit 1)

clean:
	@rm -rf $(OBJECTS)
	@echo "[OK] Supression de tous les objets"

fclean: clean
	@rm -rf $(NAME) $(EXE)
	@echo "[OK] Supression de $(NAME)"
	@echo "[OK] Supression de tous les fichiers"

re: fclean all
	@echo "[OK] Success"

.PHONY: clean fclean re all

