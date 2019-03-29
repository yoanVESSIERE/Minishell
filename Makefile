##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC = main.c function.c environ.c str_comp.c cd.c funct_cd.c

OBJ = main.o function.o environ.o str_comp.o cd.o funct_cd.o

CFLAGS = -W -Wall -Wextra

all: compi

compi: $(OBJ)
	gcc $(OBJ) -o mysh

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm $(OBJ)

fclean:
	rm mysh

re : clean fclean all