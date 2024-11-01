# NOTE: == ChatGPT CODE ==
CC = gcc
CFLAGS = -Wall -I../charm_/progressbar
LDFLAGS = -L../charm_/progressbar -lprogressbar -Wl,-rpath=../charm_/progressbar
TARGET = main
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
# NOTE: == ChatGPT CODE END ==

