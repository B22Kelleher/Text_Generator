CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
# Your .hpp files
DEPS = RandWriter.hpp
# Your compiled .o files
OBJECTS = RandWriter.o
# The name of your program
PROGRAM = TextWriter
STATIC_LIB = TextWriter.a
TEST_FILE = test.cpp
TEST_EXEC = test

.PHONY: all clean lint test


all: $(PROGRAM) $(TEST_EXEC)

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(STATIC_LIB): $(OBJECTS)
	ar rcs $@ $^
$(PROGRAM): TextWriter.o $(OBJECTS) $(STATIC_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(TEST_EXEC): $(TEST_FILE) $(STATIC_LIB)
	$(CC) $(CFLAGS) -o $@ $(TEST_FILE) $(STATIC_LIB) $(LIB)
clean:
	rm *.o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp