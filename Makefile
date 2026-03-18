CC = clang
CFLAGS = -Wall -std=c17

SRC = nb_occurence.c clm.c tri_lexico.c tri_nb_occurence.c mot_suivant.c mot_precedent.c
OBJ = $(SRC:.c=.o)

all : clm

clm: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)


%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o clm test_runner test

test: Test.c nb_occurence.o tri_lexico.o tri_nb_occurence.o mot_suivant.o mot_precedent.o
	$(CC) $(CFLAGS) -o test_runner Test.c nb_occurence.o tri_lexico.o tri_nb_occurence.o mot_suivant.o mot_precedent.o && ./test_runner
