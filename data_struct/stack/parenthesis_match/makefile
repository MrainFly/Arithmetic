CC = gcc
SRCS = $(wildcard *.c) ../linear_stack/LinearStack.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
FLAG = -g -Wall
INCLUDE = -I../../. -I../linear_stack
LIBS_DIR =
LIBS = -lm
TARGET = $(shell basename `pwd`)

.PHONY: clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(FLAG) -static $(LIBS_DIR) $(LIBS)
	
$(OBJS):%.o:%.c
	$(CC) -o $@ -c $^ $(INCLUDE) $(FLAG)

clean:
	rm -rf $(TARGET) $(OBJS)

