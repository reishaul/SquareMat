# Implementation of Operators for Square Matrices

## Project Description

SquareMat is a C++ project that handles square matrices and performs various mathematical operations on them. The project includes support for addition, subtraction, multiplication, division, transposition, determinant calculation, ...and custom operations like scalar and element-wise modulus. Each matrix is fixed in size upon creation to ensure consistent structure.


## Project Structure

The project includes the following classes:

1. **SquareMat**  
   Represents a matrix and various of operation on matrices

2. **Tests**  
   Implements various test cases demonstrating the behavior and correctness of matrix operations through the doctest framework.


3. **Main**  
   Include examples of using of each operator.


## System Requirements

The project was compiled using the g++ compiler:
g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
C++11 compatible compiler (e.g., g++)


## AI Tools Used

For the **makefile** I provided my existing wrong compilation and I received a feedback how to fix the issue and adjust my approach.

## Answer
When you run make test, the compiler tries to compile the test file together with Main.o (which already contains a main function), causing the "multiple definition of main" error.
Here's the solution:
In your Makefile, line 37 should be changed from:
$(CXX) $(CXXFLAGS) $(TEST_OBJ) $(OBJS) -o $(TEST_EXEC)
To:
$(CXX) $(CXXFLAGS) $(TEST_OBJ) SquareMat.o -o $(TEST_EXEC)
The problem is that $(OBJS) includes both Main.o and SquareMat.o, but for your test executable, you only need SquareMat.o without Main.o to avoid the conflict between the two main functions.

Moreover I asked on the difreents between **post-decrement and pre-decrement**

##Answer
The difference between pre-decrement (--mat) and post-decrement (mat--) is not in what happens inside the matrix, but rather in what the operator returns

SquareMat B = --A;  // pre-decrement
SquareMat C = A--;  // post-decrement

After --A, both A and B will contain 4.

After A--, A will contain 3, but C will still contain 4.

## Compilation and Running

To build, compile, and run the project, you can use the following `make` commands:

- `make` - Builds the `.o` files after linking.
- `make Main` - Runs the sample file.
- `make test` - Runs the test file.
- `make valgrind` - Checks for memory leaks.
- `make clean` - Cleans the `.o` files created during compilation.

## Error Handling

Additionally, I implemented exception throwing for cases where invalid input is received. This helps ensure that the program handles incorrect data gracefully.

## Conclusion

This project illustrates the implementation of fundamental and custom matrix operations in C++, highlighting concepts such as operator overloading, exception handling, and matrix arithmetic within a fixed-size structure.

