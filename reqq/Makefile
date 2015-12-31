CC = gcc
#CFLAGS = -std=c99 -I. -pthread
CFLAGS = -pthread

DEPS = 
OBJ = reqq.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

reqq: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o reqq
