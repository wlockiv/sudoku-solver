SOURCES=$(shell find . -type f -iname '*.c')

OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

TARGET=bin/sudoku

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

clean:
	rm -r $(TARGET) $(OBJECTS)