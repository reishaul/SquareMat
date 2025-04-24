//reishaul1@gmail.com
#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <stdexcept>
#include <iostream>

namespace mat {

class SquareMat {
private:
    int size;
    double** val;

public:
    SquareMat(int n);
    ~SquareMat();
    SquareMat(const SquareMat& other);//copy constructor

    SquareMat& operator=(const SquareMat& a);
    SquareMat operator-() const;
    SquareMat operator+(const SquareMat& a) const;
    SquareMat operator-(const SquareMat& a) const;

    SquareMat operator*(const SquareMat& a)const;
    SquareMat operator*(double scalar) const;

    // scalar* matrix
    friend SquareMat operator*(double scalar,const SquareMat& a ){
        SquareMat sol(a.size); 
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                sol.val[i][j] = scalar * a.val[i][j];  
            }
        }
        return sol;
    }

    // scalar* matrix
    friend SquareMat operator*(double scalar, const SquareMat& mat); 

    SquareMat operator%(const SquareMat& a)const;
    SquareMat operator%(int a)const;

    SquareMat operator/(double a)const;
    SquareMat operator^(int a) const;
    SquareMat operator--();
    SquareMat operator++();
    SquareMat operator--(int);
    SquareMat operator++(int);
    SquareMat operator~() const;

    double* operator[](int i);
    const double* operator[](int i)const;

    bool operator==(const SquareMat& a)const;
    bool operator!=(const SquareMat& a)const;
    bool operator>(const SquareMat& a)const;
    bool operator<(const SquareMat& a)const;
    bool operator<=(const SquareMat& a)const;
    bool operator>=(const SquareMat& a)const;

    SquareMat operator+=(const SquareMat& a);
    SquareMat operator-=(const SquareMat& a);
    SquareMat operator*=(double a);
    SquareMat operator*=(const SquareMat& a);
    SquareMat operator/=(double a);
    SquareMat operator%=(int a);
    SquareMat operator%=(const SquareMat& a) ;

    double operator!()const;
    double sum()const;
    SquareMat minor(int row, int col)const;

    friend std::ostream& operator<<(std::ostream& o, const SquareMat& a);
    
};
}

#endif
    


