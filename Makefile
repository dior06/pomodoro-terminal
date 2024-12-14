CC = gcc
CFLAGS = -Wall -O2
SRC = src/main.c
TARGET = pomodoro

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) stats.txt

.PHONY: clean
