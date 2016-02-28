//
// Created by bhuwan sapkota on 2/18/16.
//

#include "Cluster.h"

using namespace Clustering;



void Cluster::__del(){

    LNodePtr previous = __points;
    LNodePtr current = nullptr;

    while (previous != nullptr)
    {
        current = previous->next;
        delete previous;
        previous = current;
        --__size;
    }
}


void Cluster::__cpy(LNodePtr pts){

    if (pts != nullptr)
    {
        LNodePtr currentPts = pts;
        __points = new LNode(currentPts->point,nullptr);
        LNodePtr current = __points;
        currentPts = currentPts->next;
        while (currentPts != nullptr) {
            current->next = new LNode(currentPts->point,nullptr);
            current = current->next;
            currentPts = currentPts->next;
        }
    }
}

bool Cluster::__in(const Point & p) const
{
    LNodePtr search = __points;
    while (search != nullptr)
    {
        if(search->point == p)
        {
            return true;
        }
        search = search->next;
    }
    return false;
}

Cluster::Cluster() {
    __size = 0;
    __points = nullptr;
}

Cluster::Cluster(const Cluster & entry){
    __size = entry.__size;
    if(this != &entry) {
       __cpy(entry.__points);
   }
}

Cluster &Cluster::operator=(const Cluster &entry) {
    this->__size = entry.__size;
    if(this != &entry)
    {
        this->__cpy(entry.__points);
    }
    return *this;
}

Cluster::~Cluster() {
//    __del();
}

int Cluster::getSize() const {
    return __size;
}

void Cluster::add(const Point & point){

    LNodePtr newNode = new LNode(point,nullptr);
    if (__points == nullptr) {
        __points = newNode;
    }
    else{
        LNodePtr current = __points;
        LNodePtr prev = nullptr;
        while (current !=nullptr) {
            if (current->point >= point) {
                break;
            }
            else{
                prev = current;
                current = current->next;
            }
        }
        if (current == __points) {
            newNode->next = __points;
            __points = newNode;
        }
        else{
            newNode->next = current;
            prev->next = newNode;
        }

    }
    __size++;
}

const Point &Cluster::remove(const Point &point) {// problem
    LNodePtr prev = nullptr;
    LNodePtr current = __points;
    if (current !=nullptr && current->point == point)
    {
        __points = __points->next;
        delete current;
        __size--;
        return point;
    }
    while (current != nullptr && point != current->point)
    {
        prev =current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
    __size--;
    return point;
}

bool Cluster::contains(const Point &point) {
    bool answer = __in(point);
    return answer;
}
const Point &Cluster::operator[](unsigned int index) const {
    LNodePtr current = __points;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->point;
}

Cluster &Cluster::operator+=(const Point &point) {
    if(!__in(point))
    {
        add(point);
    }
}

Cluster &Cluster::operator-=(const Point &point) {
    if(__in(point))
    {
        remove(point);
    }
    return *this;
}

Cluster &Cluster::operator+=(const Cluster &cluster) {

    LNodePtr currentAdd = cluster.__points;

    while (currentAdd != nullptr){
        if(!contains(currentAdd->point)){
            add(currentAdd->point);
        }
        currentAdd = currentAdd->next;
    }
    return *this;
}

Cluster &Cluster::operator-=(const Cluster &cluster) {
    LNodePtr currentAdd = cluster.__points;
    while (currentAdd != nullptr){
        if(__in(currentAdd->point)){
            remove(currentAdd->point);
        }
        currentAdd = currentAdd->next;
    }
    return *this;
}

// Friends: IO
std::ostream &Clustering::operator<<(std::ostream & output, const Cluster & cluster){
    LNodePtr current = cluster.__points;
    while (current != nullptr){
        output << current->point << std::endl;
        current = current->next;
    }
    return output;}

std::istream &Clustering::operator>>(std::istream & input, Cluster & cluster){//TODO
    //    getline(input,cluster.__points->point);
    return input;
}

// Friends: Comparison

bool Clustering::operator==(const Cluster & lhs, const Cluster & rhs){
    LNodePtr currLhs = lhs.__points;
    LNodePtr currRhs = rhs.__points;
    while (currLhs != nullptr && currRhs != nullptr) {
        if (currLhs->point != currRhs->point) {
            return false;
        }
        currLhs = currLhs->next;
        currRhs = currRhs->next;
    }
    return (currLhs ==nullptr && currRhs == nullptr);
}
bool Clustering::operator!=(const Cluster & lhs, const Cluster & rhs){
    return !(lhs == rhs);
}

// Friends: Arithmetic (Cluster and Point)
const Cluster Clustering::operator+(const Cluster & lhs, const Point & rhs){
    Cluster temp(lhs);
    temp +=rhs;
    return temp ;
}
const Cluster Clustering::operator-(const Cluster & lhs, const Point & rhs){
    Cluster temp(lhs);
    temp -=rhs;
    return temp ;
}

// Friends: Arithmetic (two Clusters)
const Cluster Clustering::operator+(const Cluster & lhs, const Cluster & rhs){
    Cluster temp(lhs);
    temp +=rhs;
    return temp;
}
const Cluster Clustering::operator-(const Cluster & lhs, const Cluster & rhs){
    Cluster temp(lhs);
    temp -= rhs;
    return temp ;
}
