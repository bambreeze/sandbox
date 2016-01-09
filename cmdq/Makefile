CC = gcc
CFLAGS = -pthread

DEPS = 
OBJ = cmdq.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cmdq: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	csct

clean:
	rm -rf *.o cmdq
	rm -rf cscope* tags
	rm -rf cmd_file*
