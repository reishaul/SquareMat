//reishaul1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"


using namespace mat;

TEST_CASE("operator+ tests"){
    SUBCASE("for mat1+mat2 case"){

        SquareMat m1(2);
        SquareMat m2(2);
        m1[0][0]=1;
        m1[0][1]=2;
        m1[1][0]=3;
        m1[1][1]=2;
        m2[0][0]=1;
        m2[0][1]=2;
        m2[1][0]=3;
        m2[1][1]=2;
        SquareMat m3(2);
        m3=m1+m2;
        CHECK(m3[0][0]==2);
        CHECK(m3[0][1]==4);
        CHECK(m3[1][0]==6);
        CHECK(m3[1][1]==4);

        //check that the original matrix dosent change
        CHECK(m1[0][0] == 1);
        CHECK(m2[0][0] == 1);
    }

    SUBCASE("for mat og type 3X3") {
        SquareMat m1(3);
        SquareMat m2(3);
        
        //initialization
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m1[i][j] = i * 3 + j + 1; // ערכים 1-9
            }
        }
        
        // initialization
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m2[i][j] = 10;
            }
        }
        
        SquareMat m3 = m1 + m2;
        
        // check the results
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                CHECK(m3[i][j] == m1[i][j] + 10);
            }
        }
    }
    
    SUBCASE("similar matrix checking") {
        SquareMat m1(2);
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
        SquareMat m2 = m1 + m1;
        
        CHECK(m2[0][0] == 2);
        CHECK(m2[0][1] == 4);
        CHECK(m2[1][0] == 6);
        CHECK(m2[1][1] == 8);
    }
}

TEST_CASE("operator- tests") {
    SUBCASE("minus matrix type 2X2") {
        SquareMat m1(2);
        SquareMat m2(2);
        
        m1[0][0] = 10;
        m1[0][1] = 11;
        m1[1][0] = 12;
        m1[1][1] = 13;
        
        m2[0][0] = 1;
        m2[0][1] = 2;
        m2[1][0] = 3;
        m2[1][1] = 4;
        
        SquareMat m3 = m1 - m2;
        
        CHECK(m3[0][0] == 9);  
        CHECK(m3[0][1] == 9);  
        CHECK(m3[1][0] == 9);
        CHECK(m3[1][1] == 9); 
        
        // CHEACK THE ORIGINAL MATRIX
        CHECK(m1[0][0] == 10);
        CHECK(m2[0][0] == 1);
    }
    
    SUBCASE("minus of two same matrics") {
        SquareMat m1(3);
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m1[i][j] = i * 3 + j + 1;
            }
        }
        
        SquareMat m2 = m1 - m1;
        
        // the result need to be all zeros
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                CHECK(m2[i][j] == 0);
            }
        }
    }
}

TEST_CASE("operator unary tests") {
    SUBCASE("check 2x2 type") {
        SquareMat m1(2);
        
        m1[0][0] = 1;
        m1[0][1] = -2;
        m1[1][0] = 3;
        m1[1][1] = -4;
        
        SquareMat m2 = -m1;
        
        CHECK(m2[0][0] == -1);
        CHECK(m2[0][1] == 2);
        CHECK(m2[1][0] == -3);
        CHECK(m2[1][1] == 4);
        
        // check the origin matrix
        CHECK(m1[0][0] == 1);
        CHECK(m1[0][1] == -2);
    }
    
    SUBCASE("special edge case:") {
        SquareMat m1(2);
        
        m1[0][0] = 5;
        m1[0][1] = 6;
        m1[1][0] = 7;
        m1[1][1] = 8;
        
        SquareMat m2 = -(-m1);
        
        // need to be like no change
        CHECK(m2[0][0] == 5);
        CHECK(m2[0][1] == 6);
        CHECK(m2[1][0] == 7);
        CHECK(m2[1][1] == 8);
    }
}

TEST_CASE("matrix multiplication") {
    SUBCASE("of type 2x2") {
        SquareMat m1(2);
        SquareMat m2(2);
        
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
        m2[0][0] = 5;
        m2[0][1] = 6;
        m2[1][0] = 7;
        m2[1][1] = 8;
        
        SquareMat m3 = m1 * m2;
        
        
        CHECK(m3[0][0] == 19); // 1*5 + 2*7 = 5 + 14 = 19
        CHECK(m3[0][1] == 22); 
        CHECK(m3[1][0] == 43); 
        CHECK(m3[1][1] == 50); 
    }
    
    SUBCASE("the one matrix") {
        SquareMat m1(3);
        SquareMat identity(3);
        
        // create some matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m1[i][j] = i * 3 + j + 1;
            }
        }
        
        // create the one matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                identity[i][j] = (i == j) ? 1 : 0;
            }
        }
        
        SquareMat m2 = m1 * identity;
        
        //check if the res is the origin matrix
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                CHECK(m2[i][j] == m1[i][j]);
            }
        }
    }
}

TEST_CASE("scalar multiplication") {
    SUBCASE("matrix*scalar") {
        SquareMat m1(2);
        
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
        double scalar = 2.5;
        SquareMat m2 = m1 * scalar;
        
        CHECK(m2[0][0] == 2.5);   
        CHECK(m2[0][1] == 5.0);   
        CHECK(m2[1][0] == 7.5);   
        CHECK(m2[1][1] == 10.0);  
        
        CHECK(m1[0][0] == 1);
    }
    
    SUBCASE("scalar*matrix") {
        SquareMat m1(2);
        
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
        double scalar = 2.5;
        SquareMat m2 = scalar * m1;
        
        CHECK(m2[0][0] == 2.5);   
        CHECK(m2[0][1] == 5.0);   
        CHECK(m2[1][0] == 7.5);   
        CHECK(m2[1][1] == 10.0);  
    }
    
    SUBCASE("matrix*scalar==?scalar*matrix") {
        SquareMat m1(3);
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m1[i][j] = i * 3 + j + 1;
            }
        }
        
        double scalar = 3.5;
        SquareMat left = scalar * m1;
        SquareMat right = m1 * scalar;
        
        // chek every cell if same
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                CHECK(left[i][j] == right[i][j]);
            }
        }
    }

    SUBCASE("negative scalar") {
        SquareMat m1(2);
        
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
        double scalar = -2.0;
        SquareMat m2 = scalar * m1;
        
        CHECK(m2[0][0] == -2.0);  
        CHECK(m2[0][1] == -4.0);  
        CHECK(m2[1][0] == -6.0);  
        CHECK(m2[1][1] == -8.0); 
        
        // combination with minus unary:
        SquareMat m3 = 2.0 * (-m1);
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                CHECK(m2[i][j] == m3[i][j]);
            }
        }
    }
}

TEST_CASE("special tests") {
    SUBCASE("special no1:") {
        SquareMat m1(2);
        SquareMat m2(2);
        
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
        m2[0][0] = 5;
        m2[0][1] = 6;
        m2[1][0] = 7;
        m2[1][1] = 8;
        
        SquareMat result1 = (m1 + m2) * 2.0;
        
        CHECK(result1[0][0] == 12);  
        CHECK(result1[0][1] == 16);  
        CHECK(result1[1][0] == 20);  
        CHECK(result1[1][1] == 24);  
        
        
        SquareMat result2 = m1 * m2 + m1;
        
        CHECK(result2[0][0] == 20);  // 19+1 = 20
        CHECK(result2[0][1] == 24);  
        CHECK(result2[1][0] == 46); 
        CHECK(result2[1][1] == 54);  
    }
    
    SUBCASE("special no2:") {
        SquareMat m1(2);
        
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        
    
        SquareMat result = -m1 * 2.0;
        
        CHECK(result[0][0] == -2);  
        CHECK(result[0][1] == -4);  
        CHECK(result[1][0] == -6);  
        CHECK(result[1][1] == -8);  
    }
}

TEST_CASE("operator % test") {
    SUBCASE("test no1:") {
        SquareMat m1(2), m2(2);

        m1[0][0] = 3;
        m1[0][1] = 4;
        m1[1][0] = 2;
        m1[1][1] = 6;

        m2[0][0] = 5;
        m2[0][1] = 6;
        m2[1][0] = 7;  
        m2[1][1] = 8;

        SquareMat result = m1 % m2;

        CHECK(result[0][0] == 15);
        CHECK(result[0][1] == 24);
        CHECK(result[1][0] == 14);
        CHECK(result[1][1] == 48);
    }

    SUBCASE("test no2:") {
        SquareMat m1(2), m2(2);

        m1[0][0] = -3;
        m1[0][1] = -4;
        m1[1][0] = -2;
        m1[1][1] = -6;

        m2[0][0] = 5;
        m2[0][1] = 6;
        m2[1][0] = 7;  
        m2[1][1] = 8;

        SquareMat result = m1 % m2;

        CHECK(result[0][0] == -15);
        CHECK(result[0][1] == -24);
        CHECK(result[1][0] == -14);
        CHECK(result[1][1] == -48);
    }
}

TEST_CASE("operator% and scalar") {
    SUBCASE("test no1:") {

        SquareMat m(2);
        m[0][0] = 10;
        m[0][1] = 11;
        m[1][0] = 12;
        m[1][1] = 13;

        SquareMat result = m % 5;

        CHECK(result[0][0] == 0);
        CHECK(result[0][1] == 1);
        CHECK(result[1][0] == 2);
        CHECK(result[1][1] == 3);
    }

    SUBCASE("test no2:") {
        SquareMat m(2);
        m[0][0] = 10;
        m[0][1] = 11;
        m[1][0] = 12;
        m[1][1] = 13;

        SquareMat result = m % 2;

        CHECK(result[0][0] == 0);
        CHECK(result[0][1] == 1);
        CHECK(result[1][0] == 0);
        CHECK(result[1][1] == 1);
    }
}

TEST_CASE("operator/)") {
    SUBCASE("test no1:") {

        SquareMat m(2);
        m[0][0] = 2;
        m[0][1] = 6;
        m[1][0] = 16;
        m[1][1] = 8;

        SquareMat result = m / 2;

        CHECK(result[0][0] == 1);
        CHECK(result[0][1] == 3);
        CHECK(result[1][0] == 8);
        CHECK(result[1][1] == 4);
    }
    SUBCASE("test no2:") {
        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 3;
        m[1][0] = 5;
        m[1][1] = 7;

        SquareMat result = m / 2;

        CHECK(result[0][0] == 0.5);
        CHECK(result[0][1] == 1.5);
        CHECK(result[1][0] == 2.5);
        CHECK(result[1][1] == 3.5);
    }
}
TEST_CASE("operator^") {
    SUBCASE("test no1:") {

        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 1;
        m[1][0] = 1;
        m[1][1] = 0;

        SquareMat result = m ^ 3;

        CHECK(result[0][0] == 3);
        CHECK(result[0][1] == 2);
        CHECK(result[1][0] == 2);
        CHECK(result[1][1] == 1);
    }

    SUBCASE("test no2:") {

        SquareMat m(2);
        m[0][0] = 2;
        m[0][1] = 1;
        m[1][0] = 3;
        m[1][1] = 2;

        SquareMat result = m ^ 3;

        CHECK(result[0][0] == 26);
        CHECK(result[0][1] == 15);
        CHECK(result[1][0] == 45);
        CHECK(result[1][1] == 26);
    }
}

TEST_CASE("Increment and Decrement Operators") {
    using namespace mat;

    SUBCASE("Prefix increment") {
        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        ++m;

        CHECK(m[0][0] == 2);
        CHECK(m[0][1] == 3);
        CHECK(m[1][0] == 4);
        CHECK(m[1][1] == 5);
    }

    SUBCASE("Postfix increment") {
        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3; 
        m[1][1] = 4;

        SquareMat copy = m++;
        
        CHECK(copy[0][0] == 1);
        CHECK(copy[1][1] == 4);

        CHECK(m[0][0] == 2);
        CHECK(m[1][1] == 5);
    }

    SUBCASE("Prefix decrement") {
        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        --m;

        CHECK(m[0][0] == 0);
        CHECK(m[0][1] == 1);
        CHECK(m[1][0] == 2);
        CHECK(m[1][1] == 3);
    }

    SUBCASE("Postfix decrement") {
        SquareMat m(2);
        m[0][0] = 2;
        m[0][1] = 1;
        m[1][0] = 9;
        m[1][1] = 5;

        SquareMat copy = m--;

        CHECK(copy[0][0] == 2);
        CHECK(copy[1][1] == 5);

        CHECK(m[0][0] == 1);
        CHECK(m[1][1] == 4);
    }
}

TEST_CASE("operator ~") {
    using namespace mat;

    SUBCASE("2x2 matrix") {
        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        SquareMat t = ~m;

        CHECK(t[0][0] == 1);
        CHECK(t[0][1] == 3);
        CHECK(t[1][0] == 2);
        CHECK(t[1][1] == 4);
    }

    SUBCASE("identity matrix") {
        SquareMat m(3);
        m[0][0] = 1;
        m[1][1] = 1;
        m[2][2] = 1;

        SquareMat t = ~m;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                CHECK(t[i][j] == m[j][i]);
    }
}
TEST_CASE("operator []") {
    using namespace mat;

    SquareMat m(2);

    SUBCASE("Set and get") {
        m[0][0] = 5;
        m[0][1] = 6;
        m[1][0] = 7;
        m[1][1] = 8;

        CHECK(m[0][0] == 5);
        CHECK(m[0][1] == 6);
        CHECK(m[1][0] == 7);
        CHECK(m[1][1] == 8);
    }

    SUBCASE("more case:") {
        m[1][1] = 10;
        CHECK(m[1][1] == 10);

        m[1][1] += 2;
        CHECK(m[1][1] == 12);
    }
}
TEST_CASE("== and != operators") {
    using namespace mat;

    SUBCASE("check equals matrics") {
        SquareMat m1(2), m2(2);

        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[1][0] = 3;
        m1[1][1] = 4;
        m2[0][0] = 0;
        m2[0][1] = 0;
        m2[1][0] = 5;
        m2[1][1] = 5;

        CHECK(m1 == m2);
        CHECK_FALSE(m1 != m2);
    }

    SUBCASE("check unequal matrices") {
        SquareMat m1(2), m2(2);

        m1[0][0] = 1; 
        m1[0][1] = 1;
        m1[1][0] = 1; 
        m1[1][1] = 1; 
        m2[0][0] = 0; 
        m2[0][1] = 0;
        m2[1][0] = 0; 
        m2[1][1] = 5; 

        CHECK_FALSE(m1 == m2);
        CHECK(m1 != m2);
    }
}
TEST_CASE("Comparison operators (<, >, <=, >=) based on sum of elements") {
    using namespace mat;

    SquareMat m1(2), m2(2), m3(2);

    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    m2[0][0] = 1;
    m2[0][1] = 1;
    m2[1][0] = 1;
    m2[1][1] = 2;

    m3[0][0] = 2; 
    m3[0][1] = 2;
    m3[1][0] = 3; 
    m3[1][1] = 3;

    SUBCASE("<") {
        CHECK(m2 < m1);
        CHECK_FALSE(m1 < m2);
    }
    SUBCASE(">") {
        CHECK(m1 > m2);
        CHECK_FALSE(m2 > m1);
    }

    SUBCASE("<=") {
        CHECK(m2 <= m1);
        CHECK(m1 <= m3); 
        CHECK_FALSE(m1 <= m2);
    }

    SUBCASE(">=") {
        CHECK(m1 >= m2);
        CHECK(m1 >= m3); 
        CHECK_FALSE(m2 >= m1);
    }
}

TEST_CASE("Determinant operator!") {
    using namespace mat;

    SUBCASE("2x2 matrix determinant") {
        SquareMat m(2);
        m[0][0] = 4;  
        m[0][1] = 6;
        m[1][0] = 3;  
        m[1][1] = 8;

        CHECK(!m ==14);
    }

    SUBCASE("3x3 matrix") {
        SquareMat m(3);
        m[0][0] = 6;  
        m[0][1] = 1;  
        m[0][2] = 1;
        m[1][0] = 4;  
        m[1][1] = -2; 
        m[1][2] = 5;
        m[2][0] = 2;  
        m[2][1] = 8;  
        m[2][2] = 7;

        CHECK( !m == -306.0);
    }

    SUBCASE("1x1 matrix ") {
        SquareMat m(1);
        m[0][0] = 7;
        CHECK( !m == 7.0);
    }

    SUBCASE("Zero") {
        SquareMat m(3);
        CHECK( !m ==0.0);
    }
}
TEST_CASE("test operators +=, -=, *=, /=, %=") {
    using namespace mat;

    SUBCASE("operator +=") {
        SquareMat m1(2), m2(2);
        m1[0][0] = 1; 
        m1[0][1] = 2;
        m1[1][0] = 3; 
        m1[1][1] = 4;

        m2[0][0] = 5; 
        m2[0][1] = 6;
        m2[1][0] = 7; 
        m2[1][1] = 8;

        m2 += m1;

        CHECK(m2[0][0] == 6);
        CHECK(m2[0][1] == 8);
        CHECK(m2[1][0] == 10);
        CHECK(m2[1][1] == 12);
    }

    SUBCASE("operator -=") {
        SquareMat m1(2), m2(2);
        m1[0][0] = 1; 
        m1[0][1] = 2;
        m1[1][0] = 3; 
        m1[1][1] = 4;

        m2[0][0] = 1; 
        m2[0][1] = 4;
        m2[1][0] = 5; 
        m2[1][1] = 8;

        m2 -= m1;

        CHECK(m2[0][0] == 0);
        CHECK(m2[0][1] == 2);
        CHECK(m2[1][0] == 2);
        CHECK(m2[1][1] == 4);
    }

    SUBCASE("Operator *= matrix*matrix") {
        SquareMat m1(2), m2(2);
        m1[0][0] = 1; 
        m1[0][1] = 2;
        m1[1][0] = 3; 
        m1[1][1] = 4;

        m2[0][0] = 2; 
        m2[0][1] = 2;
        m2[1][0] = 2; 
        m2[1][1] = 2;

        m1 *= m2; 

        CHECK(m1[0][0] == 6);
        CHECK(m1[0][1] == 6);
        CHECK(m1[1][0] == 14);
        CHECK(m1[1][1] == 14);
    }

    SUBCASE("Operator *= matrix*scalar") {
        SquareMat m(2);
        m[0][0] = 1; 
        m[0][1] = 2;
        m[1][0] = 3; 
        m[1][1] = 4;

        m *= 3;
        CHECK(m[0][0] == 3);
        CHECK(m[0][1] == 6);
        CHECK(m[1][0] == 9);
        CHECK(m[1][1] == 12);
    }

    SUBCASE("Operator /=") {
        SquareMat m(2);
        m[0][0] = 4; 
        m[0][1] = 10;
        m[1][0] = 12; 
        m[1][1] = 6;

        m /= 4;

        CHECK(m[0][0] == 1);
        CHECK(m[0][1] == 2.5);
        CHECK(m[1][0] == 3);
        CHECK(m[1][1] == 1.5);
    }

    SUBCASE("Operator %= one types") {
        SquareMat m(2);
        m[0][0] = 10; 
        m[0][1] = 11;
        m[1][0] = 19; 
        m[1][1] = 20;

        m %= 5;

        CHECK(m[0][0] == 0);
        CHECK(m[0][1] == 1);
        CHECK(m[1][0] == 4);
        CHECK(m[1][1] == 0);
    }

    SUBCASE("Operator %= second type") {
        SquareMat m1(2), m2(2);
        m1[0][0] = 10;
        m1[0][1] = 20;
        m1[1][0] = 30; 
        m1[1][1] = 40;

        m2[0][0] = 2; 
        m2[0][1] = 3;
        m2[1][0] = 4; 
        m2[1][1] = 5;

        m1 %= m2;

        CHECK(m1[0][0] == 0); 
        CHECK(m1[0][1] == 2);  
        CHECK(m1[1][0] == 2);  
        CHECK(m1[1][1] == 0);  
    }
}
TEST_CASE("operator << ") {
    SUBCASE("case1:") {

        using namespace mat;

        SquareMat m(2);
        m[0][0] = 1.1; 
        m[0][1] = 2.2;
        m[1][0] = 3.3; 
        m[1][1] = 4.4;

        std::ostringstream oss;
        oss << m;

        std::string expected =
            "1.1 2.2\n"
            "3.3 4.4\n";

        CHECK(oss.str() == expected);
    }
    SUBCASE("case2:") {

        using namespace mat;
        SquareMat m(3);
        m[0][0] = 1;  
        m[0][1] = 0;  
        m[0][2] = 0;
        m[1][0] = 0;  
        m[1][1] = 1; 
        m[1][2] = 0;
        m[2][0] = 0;  
        m[2][1] = 0;  
        m[2][2] = 1;

        std::ostringstream oss;
        oss << m;

        std::string expected =
            "1 0 0\n"
            "0 1 0\n"
            "0 0 1\n";

        std::string no_expected =
            "1 0 0"
            "0 1 0"
            "0 0 1";

        CHECK(oss.str() == expected);
        CHECK_FALSE(oss.str() == no_expected);
    }

}
















