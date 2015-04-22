CC = gcc
CFLAGS = -pthread

DEPS = 
OBJ = reqq.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

reqq: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	csct

clean:
	rm -rf *.o reqq
	rm -rf cscope* tags
