CC = clang++

CC_FLAGS = -w -std=c++14

# INCLUDE_PATHS =

# LIBRARY_PATHS =

# LINKER_FLAGS =
EXEC = repl.bin

SOURCES = $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) -g $(OBJECTS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c -g $(CC_FLAGS) $(INCLUDE_PATHS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
