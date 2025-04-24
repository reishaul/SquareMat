//reishaul1@gmail.com
#include <stdexcept>
#include "SquareMat.hpp"

using namespace mat;

int main(){
    SquareMat m1(2);
    SquareMat m2(2);

    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[1][0] = 1;
    m2[1][1] = 1;

    std::cout << "matrix m1:\n" << m1;
    std::cout << "matrix m2:\n" << m2;

    std::cout<<"example of : +, - on matrix\n";
    SquareMat sum = m1 + m2;
    std::cout << "m1 + m2:\n" << sum;

    SquareMat minus = m1 - m2;
    std::cout << "m1 - m2:\n" << minus;

    std::cout<<"example of unary minus\n";
    SquareMat neg = -m1;
    std::cout << "-m1:\n" << neg;

    std::cout<<"example of matrix muliplaction and matrix*scalar \n";
    SquareMat mul = m2 * m1;
    std::cout << "m2 * m1:\n" << mul;

    SquareMat scalarMul = m1 * 2;
    std::cout << "m1 * 2:\n" << scalarMul;

    std::cout<<"example of %(multiplaction),%(modulo scalar) \n";
    SquareMat e = m1 % m2;
    std::cout << "m1 % m2 :\n" << e;
    SquareMat mod = m1 % 5;
    std::cout << "m1 % 5:\n" << mod;

    std::cout<<"example of /divide and ^ \n";
    SquareMat div = m1 / 2;
    std::cout << "m1 / 2:\n" << div;

    SquareMat po = m1 ^ 3;
    std::cout << "m1 ^ 3:\n" << po;

    std::cout<<"example of ++ and -- on matrix: \n";
    std::cout << "matrix m1:\n" << m1;
    ++m1;
    std::cout << "after ++m1:\n" << m1;
    m1--;
    std::cout << "after m1--:\n" << m1;

    std::cout<<"example of ~ and accsess with []: \n";

    SquareMat trans = ~m1;
    std::cout << "transpose of m1:\n" << trans;
    std::cout << " m1[1][0]= " << m1[1][0] << std::endl;
    m1[1][0] = 9;
    std::cout << "after using [] m1[1][0] to 9:\n" << m1;

    std::cout<<"example of == and != : \n";
    SquareMat m4(2);
    m4[0][0] = 5;
    m4[0][1] = 5;
    m4[1][0] = 3;
    m4[1][1] = 6;

    SquareMat m5(2);
    m4[0][0] = 2;
    m4[0][1] = 4;
    m4[1][0] = 11;
    m4[1][1] = 2;

    std::cout << "matrix m4:\n" << m4;
    std::cout << "matrix m5:\n" << m5;
    if(m4==m5){
        std::cout << "m1 and m4 are equal because same sum of elements\n";
    }

    if (m1 == m4) {
        std::cout << "m1 and m4 are equal because same sum of elements\n";
    } else {
        std::cout << "m1 and m4 are not equal\n";
    }
   
    if (m1 != m4) {
        std::cout << "m1 and m4 are not equal because different sum of elements\n";
    } else {
        std::cout << "m1 and m4 are equal\n";
    }

    std::cout<<"example of >,<,<=,>= : \n";
    SquareMat a(2), b(2);
    a[0][0] = 1; 
    a[0][1] = 2;
    a[1][0] = 3; 
    a[1][1] = 4;

    b[0][0] = 5; 
    b[0][1] = 5;
    b[1][0] = 0; 
    b[1][1] = 0;
    std::cout << "matrix a:\n" << a;
    std::cout << "matrix b:\n" << b;
    std::cout<<"check if a>b or a<b, a<=b or a>=b : \n";

    if (a > b) std::cout << "a > b\n";
    if (a < b) std::cout << "a < b\n";
    if (a >= b) std::cout << "a >= b\n";
    if (a <= b) std::cout << "a <= b\n";

    std::cout<<"example of ! determinant: \n";
    SquareMat c(3);
    c[0][0] = 6;  c[0][1] = 1;  c[0][2] = 1;
    c[1][0] = 4;  c[1][1] = -2; c[1][2] = 5;
    c[2][0] = 2;  c[2][1] = 8;  c[2][2] = 7;

    std::cout << "matrix c:\n" << c;
    std::cout << "determinant of the matrix c: " << !c << std::endl;

    std::cout<<"example of using operators +=, -=, *= \n";
    SquareMat r(2), l(2);
    r[0][0] = 1; r[0][1] = 2;
    r[1][0] = 3; r[1][1] = 4;

    l[0][0] = 5; l[0][1] = 6;
    l[1][0] = 7; l[1][1] = 8;

    std::cout << "matrix r:\n" << r;
    std::cout << "matrix l:\n" << l;

    l += r;
    std::cout << "after l += r:\n" << l;

    l-= r;
    std::cout << "after l -= r:\n" << l;

    l *= r;
    std::cout << "After l *= r ( matrix multiplication):\n" << l;

    l = SquareMat(2);
    l[0][0] = 10; l[0][1] = 20;
    l[1][0] = 30; l[1][1] = 40;

    l *= 2;
    std::cout << "after l *= 2 (scalar multiplication):\n" << l;
    std::cout<<"example of using operators  /=, %= \n";
    l /= 10;
    std::cout << "after l /= 10 :\n" << l;


    l %= 4;
    std::cout << "after l %= 4  with scalar:\n" << l;

    std::cout << "matrix l:\n" << l;
    std::cout << "matrix r:\n" << r;

    l %= r;
    std::cout << "after l %= r element-wise modulo:\n" << l;


    std::cout<<"example of using operator << \n";
    SquareMat ml(2);
    
    ml[0][0] = 10; ml[0][1] = 20;
    ml[1][0] = 30; ml[1][1] = 40;

    std::cout << "print new matrix the matrix cell: ml[0][0]=10, ml[0][1]=20, ml[1][0]=30, ml[1][1]=40 \n";
    std::cout << ml;

    return 0;


}