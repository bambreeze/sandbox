CC = gcc
#CFLAGS = -pthread
ifeq ($(ARCH), XX)
CFLAGS = -DTEST1
else ifeq ($(ARCH), YY)
CFLAGS = -DTEST2
else
CFLAGS = -DTEST_UNKNOWN
endif

DEPS = 
OBJ = macro.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: macro
macro: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	csct

.PHONY: clean
clean:
	rm -rf *.o macro
	rm -rf cscope* tags
