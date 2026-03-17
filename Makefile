CC = clang
CFLAGS = -Wall -std=c17

SRC = cpt_occurence.c
OBJ = $(SRC:.c = .o)

all : clm

Jeu: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)


%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o Jeu
