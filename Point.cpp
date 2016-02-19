//
// Created by bhuwan sapkota on 2/16/16.
//

#include "Point.h"
#include <cmath>

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
    for (int i = 0; i < __dim; ++i)
        __values[i] = ((__values[i] / d));
    return *this;
}

const Clustering::Point Clustering::Point::operator*(double d) const {

    for (int i = 0; i < __dim; ++i) {
        __values[i] *=d;
    }
    return *this ;
}

const Clustering::Point Clustering::Point::operator/(double d) const {

    for (int i = 0; i < -__dim; ++i) {
        __values[i] /=d;
    }
    return *this;
}

double & Clustering::Point::operator[](int index) {

    return __values[index];
}

