CC = gcc
SRCS = main.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
FLAG = -g -Wall
INCLUDE =
LIBS_DIR =
LIBS = -lm
TARGET = prog

.PHONY: clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(FLAG) -static $(LIBS_DIR) $(LIBS)
	
$(OBJS):%.o:%.c
	$(CC) -o $@ -c $^ $(INCLUDE) $(FLAG)

clean:
	rm -rf $(TARGET) $(OBJS)
	
	

