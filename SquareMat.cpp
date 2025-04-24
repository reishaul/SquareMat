//reishaul1@gmail.com
#include <stdexcept>
#include <iostream>

#include "SquareMat.hpp"
#include <cmath>


namespace mat{

    //according to the rule of three we need constructor, destructor and placement operator
SquareMat::SquareMat(int n):size(n){//constuctor
    if(n<=0){
        throw std::invalid_argument("size need to be bigger then zero");
    }
    val= new double*[size];//head array
    for (int i=0; i<size; ++i){
        val[i]=new double[size];//sub array
        for(int j=0;j<size; ++j){
            val[i][j]=0;//initialization

        }
    }
}

SquareMat::SquareMat(const SquareMat& a): size(a.size) {//copy constructor for the rule of tree
    val = new double*[size];
    for (int i = 0; i < size; ++i) {
        val[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            val[i][j] = a.val[i][j];
        }
    }
}


//the placement operator
SquareMat& SquareMat::operator=(const SquareMat& a){//we need to do a deep copy

    //first we check if it is the same object 
    if(this==&a){
        return *this;
    }

    //first we need to clear the old values
    int i;
    for(i=0;i<size; ++i){
        delete[] val[i];

    }
    delete[] val;

    //now we need to perform a deep copy
    size = a.size;
    val = new double*[size];
    for (int i = 0; i < size; ++i) {
        val[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            val[i][j] = a.val[i][j];//for each cell
        }
    }
    return *this;
}

SquareMat SquareMat::operator+(const SquareMat& a)const{
    //condition to validate
    if(size!=a.size){
        throw std::invalid_argument("both of the matrix must to be in the same size ");
    }

    SquareMat sol(a.size);
    int i,k;
    for(i=0; i<size; ++i){
        for(k=0; k<size;++k){
            sol.val[i][k]=a.val[i][k]+this->val[i][k];

        }
    }
    return sol;

}

SquareMat SquareMat::operator-(const SquareMat& a)const{
    //condition to validate
    if(size!=a.size){
        throw std::invalid_argument("both of the matrix must to be in the same size ");
    }

    SquareMat sol(a.size);
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            sol.val[i][k]=this->val[i][k] -(a.val[i][k]);

        }
    }
    return sol;

}

SquareMat SquareMat::operator-() const{
    SquareMat sol(this->size);
    int i,k;
    for(i=0; i<size; ++i){
        for(k=0; k<size;++k){
            sol.val[i][k]=-(val[i][k]);
        }
    }
    return sol;
}

SquareMat SquareMat::operator*(const SquareMat& a)const{

    if(size!=a.size){
        throw std::invalid_argument("both of the matrix must to be in the same size ");
    }
    SquareMat sol(this->size);
    
    for(int i=0; i<size; ++i){
        for(int j=0; j<size;++j){
            sol.val[i][j] = 0;
            for(int k=0; k<size;++k){
                sol.val[i][j]+=(a.val[k][j])*(this->val[i][k]);

            }
        }
    }
    return sol;
}

//matrix * scalar
SquareMat SquareMat::operator*(double a)const{
    SquareMat sol(this->size);
    int i,k;
    for(i=0; i<size; ++i){
        for(k=0; k<size;++k){
            sol.val[i][k]=(val[i][k])*a;
        }
    }
    return sol;
}

    
//implementation of scalar * matrix appear in the SquareMat.hpp file 

SquareMat SquareMat::operator%(const SquareMat& a)const{

    if(size!=a.size){
        throw std::invalid_argument("both of the matrix must to be in the same size ");
    }
    SquareMat sol(this->size);
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            sol.val[i][k]=this->val[i][k]*a.val[i][k];
        }
    }
    return sol;
}

SquareMat SquareMat::operator%(int a)const{//using with function from cmath library

    if(a==0){
        throw std::invalid_argument("the scalar most be bigger then zero");
    }
    SquareMat sol(this->size);
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){

            sol.val[i][k]=std::fmod(val[i][k],a);
        }
    }
    return sol;
}

SquareMat SquareMat::operator/(double a)const{
    if(a==0){
        throw std::invalid_argument("cannot divide by zero");
    }

    SquareMat sol(this->size);
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            sol.val[i][k]=(val[i][k])/a;
        }
    }
    return sol;
}

SquareMat SquareMat::operator^(int a) const{
    if(a<0){
        throw std::invalid_argument("cannot perform negative power");
    }
    SquareMat sol(this->size);

    if(a==0){//the unity matrix
        for(int i=0; i<size;++i){
            sol.val[i][i]=1;//all the slant is unity
        }
        return sol;
    }

    if(a==1){//return the original matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sol.val[i][j] = this->val[i][j];
            }
        }
        return sol;
    }

    //using recursion
    if(a%2==0){
        SquareMat half = (*this)^(a/2);
        return half * half;
    }
    else {
        return  (*this)* ((*this)^(a - 1));
    
    }
}

//return the mat after the decrement
SquareMat SquareMat::operator--(){//predecrescment
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            val[i][k]=val[i][k]-1;
        }
    }
    return *this;
}

//return the mat after the increment
SquareMat SquareMat::operator++(){//preincrement
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            val[i][k]=val[i][k]+1;
        }
    }
    return *this;
}

SquareMat SquareMat::operator--(int){//postdecrescment
    SquareMat temp(*this);//save the origin
    --(*this);//decrement
    return temp;//return the mat which before the decrement
}

SquareMat SquareMat::operator++(int){//postincrement
    SquareMat temp(*this);//save the origin
    ++(*this);//increment
    return temp;//return the mat which before the increment
}

SquareMat SquareMat::operator~() const{//transpose

    SquareMat sol(this->size);

    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            sol.val[i][k]=val[k][i];
        }
    }
    return sol;
}

double* SquareMat::operator[](int i){
    if(i>=size || i<0){
        throw std::invalid_argument("out of range of the matrix");}
    return val[i];
}

const double* SquareMat::operator[](int i)const{
    if(i>=size || i<0){
        throw std::invalid_argument("out of range of the matrix");}
    return val[i];
}

bool SquareMat::operator==(const SquareMat& a)const{

    double origin=a.sum();
    double other=this->sum();

    if(origin!=other){return false;}
    return true;
    
}

bool SquareMat::operator!=(const SquareMat& a)const{
    bool ans=(*this==a);
    return !ans;
}

bool SquareMat::operator>(const SquareMat& a)const{
    double origin=this->sum();
    double other=a.sum();
    return origin>other;
}

bool SquareMat::operator<(const SquareMat& a)const{
    double origin=this->sum();
    double other=a.sum();
    return origin<other;
}

bool SquareMat::operator<=(const SquareMat& a)const{
    double origin=this->sum();
    double other=a.sum();
    return origin<=other;
}

bool SquareMat::operator>=(const SquareMat& a)const{
    double origin=this->sum();
    double other=a.sum();
    return origin>=other;
}

double SquareMat::sum()const{
    double sum=0;
    for(int i=0; i<size; ++i){
        for(int j=0; j<size;++j){
            sum+=val[i][j];
        }
    }
    return sum;
}


double SquareMat::operator!()const{

    double a=0;
    
    if(this->size==1){
        return val[0][0];

    }
    if(this->size==2){
        return val[0][0]*val[1][1]-val[0][1]*val[1][0];
    }

    for(int i=0; i<size; ++i){
        int k=(i%2==0)?1:-1;
        SquareMat mi=minor(0,i);//calculate det according to the first line
        a+=k* (val[0][i])*(!mi); 
    }

    return a;

}

SquareMat SquareMat::minor(int row, int col)const{

    SquareMat m(size-1);
    int a=0;
    for(int i=0;i<size;i++){
        if(i==row){
            continue;
        }
        int b=0;
        for(int j=0;j<size;j++){
            if(j==col){continue;}

            m[a][b]=val[i][j];
            ++b;
        }
        ++a;
    }
    return m;

}

SquareMat SquareMat::operator+=(const SquareMat& a){
    if(a.size!=this->size){
        throw std::invalid_argument("for this operation both of the matrices must be same size ");
    }
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            val[i][k]=val[i][k]+a.val[i][k];
        }
    }
    return *this;
}

SquareMat SquareMat::operator-=(const SquareMat& a){
    if(a.size!=this->size){
        throw std::invalid_argument("for this operation both of the matrices must be same size ");
    }
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            val[i][k]-=a.val[i][k];
        }
    }
    return *this;
}

SquareMat SquareMat::operator*=(double a){//matrix * scalar
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            val[i][k]*=a;
        }
    }
    return *this;
}

SquareMat SquareMat::operator*=(const SquareMat& a){//matrix*matrix
    if(a.size!=this->size){
        throw std::invalid_argument("for this operation both of the matrices must be same size ");
    }
    
    SquareMat temp(a.size);
    for(int i=0; i<size; ++i){
        for(int j=0; j<size;++j){
            
            for(int k=0; k<size;++k){

                temp[i][j]+=val[i][k]*a.val[k][j];
            }
        }
    }
    *this=temp;
    return *this;
}

SquareMat SquareMat::operator/=(double a){//matrix / scalar

    if(a==0){throw std::invalid_argument("cannot divide by zero");}
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            val[i][k]/=a;
        }
    }
    return *this;
}

SquareMat SquareMat::operator%=(int a){//using with function from cmath library

    if(a==0){
        throw std::invalid_argument("the scalar cannot be zero");
    }
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){

            val[i][k]=std::fmod(val[i][k],a);
        }
    }
    return *this;
}

SquareMat SquareMat::operator%=(const SquareMat& a){//using with function from cmath library
    if(a.size!=this->size){
        throw std::invalid_argument("for this operation both of the matrices must be same size ");
    }
    
    for(int i=0; i<size; ++i){
        for(int k=0; k<size;++k){
            if(a.val[i][k]==0){
                throw std::invalid_argument("cannot perform 'mod0'");
            }

            val[i][k]=std::fmod(val[i][k],a.val[i][k]);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o ,const SquareMat& a){
    for(int i=0; i<a.size; ++i){
        for(int k=0; k<a.size;++k){
            o<<a.val[i][k];
            if(k<a.size-1){o<<" ";}//if we dident want space at the last item
        }
        o<<"\n";
    }
    return o;
}


SquareMat::~SquareMat(){
    for(int i=0; i<size; ++i){
        delete[] val[i];
    }
    delete[] val;
}


}

