CC = gcc
EXEC = fillit
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

%.o : %.c headerfile.h
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -Wall -Wextra -Werror -o $@ $^

clean :
	rm -rf *.o

mrproper : clean
	rm -rf rush-01

# $@ nom cible
# $< nom premiere dependance
# $^ liste dependances
# $? liste dependance plus recentes que la cible
# $* nom fichier, sans son extension