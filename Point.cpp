//
// Created by bhuwan sapkota on 2/16/16.
//

#include "Point.h"
#include <cmath>
#include <sstream>
#include <cstdlib>

//using namespace Clustering;


unsigned int Clustering::Point::__idGen =0;

Clustering::Point::Point(int dim)
{
    __id = __idGen;
    ++__idGen;

    __dim = dim;
    __values = new double[__dim];
    for (int i = 0; i < __dim; ++i) {
        __values[i] = 0.0;
    }
}

Clustering::Point::Point(int dim, double * value)
{
    __id = __idGen;
    ++__idGen;

    __dim = dim;
    __values = new double[__dim];
    for (int i = 0; i < __dim; ++i) {
        __values[i] = value[i];
    }
}

Clustering::Point::Point(const Clustering::Point & entry)
{
    __id = entry.__id;
    __dim = entry.__dim;
    __values = new double[__dim];
    for (int i = 0; i < __dim; ++i)
    {
        __values[i] = entry.__values[i];
    }
}


Clustering::Point & Clustering::Point::operator=(const Clustering::Point & entry)
{
    if(this != &entry)
    {
        __id = entry.__id;
        __dim = entry.__dim;
        __values = new double[__dim];
        for (int i = 0; i < __dim; ++i)
        {
            __values[i] = entry.__values[i];
        }
    }
    return *this;
}


Clustering::Point::~Point()
{
    if(__values != nullptr)
    {
        delete[] __values;
        __values = nullptr;
    }

}


int Clustering::Point::getId() const {

    return __id;
}

int Clustering::Point::getDims() const {
    return __dim;
}

void Clustering::Point::setValue(int i, double d) {

    __values[i]= d;
}

double Clustering::Point::getValue(int i) const
{
    return __values[i];
}

double Clustering::Point::distanceTo(const Clustering::Point & PointTo) const
{
    double SqreOfDistance =0;
    for (int i = 0; i < __dim; ++i)
    {
        SqreOfDistance +=((PointTo.__values[i] - __values[i]) *  (PointTo.__values[i] - __values[i]));
    }
    return (sqrt(SqreOfDistance));
}

Clustering::Point & Clustering::Point::operator *=(double d) {
    for (int i = 0; i < __dim; ++i)
        __values[i] = ((__values[i] * d));
    return *this;
}

Clustering::Point & Clustering::Point::operator /=(double d) {
    if (d != 0.0) {
        for (int i = 0; i < __dim; ++i)
            __values[i] = (__values[i] / d);
    }
    return *this;
}

const Clustering::Point Clustering::Point::operator*(double d) const {

    for (int i = 0; i < __dim; ++i) {
        __values[i] *=d;
    }
    return *this ;
}

const Clustering::Point Clustering::Point::operator/(double d) const {

    for (int i = 0; i < __dim; ++i) {
        __values[i] /=d;
    }
    return *this;
}

double & Clustering::Point::operator[](int index) {

    return __values[index];
}

Clustering::Point& Clustering::operator+=(Clustering::Point& lhs, const Clustering::Point& rhs)
{
    for (int i = 0; i < lhs.__dim; ++i) {
        lhs.__values[i] +=rhs.__values[i];
    }
    return lhs;
}

Clustering::Point& Clustering::operator-=(Clustering::Point& lhs, const Clustering::Point& rhs)
{
    for (int i = 0; i < lhs.__dim; ++i) {
        lhs.__values[i] -=rhs.__values[i];
    }
    return lhs;
}

Clustering::Point const Clustering::operator+(const Clustering::Point& lhs, const Clustering::Point& rhs)
{
    Clustering::Point temp(lhs);
    temp +=rhs;
    return temp;

}

Clustering::Point const Clustering::operator-(const Clustering::Point& lhs, const Clustering::Point& rhs)
{
    Clustering::Point temp(lhs);
    temp -=rhs;
    return temp;

}

bool Clustering::operator==(const Clustering::Point &a, const Clustering::Point &b) {

    bool answer = false;
    if (a.__id == b.__id){
        answer = true;
            for (int i = 0; i < a.__dim; ++i) {
                if(a.__values[i] != b.__values[i]) {
                    return false;
                }
            }
    }
    return answer;
}

bool Clustering::operator!=(const Clustering::Point& a, const Clustering::Point &b)
{
    return !(a == b);
}

bool Clustering::operator<(const Clustering::Point& a, const Clustering::Point &b){

    bool answer = true;
        for (int i = 0; i < a.__dim ; ++i) {
            if(a.__values[i] > b.__values[i]) {
                answer = false;
                break;
            }
            else if(a.__values[i]> b.__values[i]){
                break;
            }
        }

    return answer;
}

bool Clustering::operator>(const Clustering::Point& a, const Clustering::Point &b){
    return !(a < b);
}

bool Clustering::operator>=(const Clustering::Point& a, const Clustering::Point &b){
    return (b < a);
}
bool Clustering::operator<=(const Clustering::Point& a, const Clustering::Point &b) {
    return !(a > b);
}

std::ostream & Clustering::operator<<(std::ostream & output, const Clustering::Point & somePoint){
    for (int i = 0; i < somePoint.__dim; ++i) {

        output << somePoint.__values[i];
        if(i !=(somePoint.__dim-1))
        output << ", ";
    }
    return output;
}

std::istream & Clustering::operator >>(std::istream & input, Clustering::Point & somePoint) {

    std::string temp;
    for (int i = 0; i < somePoint.__dim; ++i) {
        getline(input, temp, ',');
        somePoint.__values[i] = stod(temp);
    }
    return input;
}