CC = gcc #mpicc
CFLAGS = -g -O3 -Wall

TARGET = a

all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET).out $(TARGET).c

clean:
	$(RM) $(TARGET)