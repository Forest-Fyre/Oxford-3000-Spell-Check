CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES= word.cpp spell_checker.cpp hash_table.h bs_tree.h main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=SpellChecker

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
