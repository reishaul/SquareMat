#reishaul1@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g

TARGET = out
TESTS_TARGET =test_runner

# using variables to store the files
SRCS = Main.cpp SquareMat.cpp
OBJS = Main.o SquareMat.o 

EXEC = main

$(EXEC): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp -o SquareMat.o

Main.o: Main.cpp SquareMat.hpp 
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

# for make Main
Main: $(EXEC)
	./$(EXEC)

#for the testing section
TEST_SRC = Tests.cpp  
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_EXEC = test_runner

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) SquareMat.o
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) SquareMat.o -o $(TEST_EXEC)

$(TEST_OBJ): $(TEST_SRC) SquareMat.hpp 
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

# cleaning the o files
clean:  
	rm -f $(OBJS) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)

#for make valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)
	
