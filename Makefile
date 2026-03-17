CC = clang
CFLAGS = -Wall -std=c17

SRC = nb_occurence.c clm.c
OBJ = $(SRC:.c=.o)

all : clm

clm: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)


%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o clm test_runner

test: Test.c nb_occurence.o
	$(CC) $(CFLAGS) -o test_runner Test.c nb_occurence.o && ./test_runner
