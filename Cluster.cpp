//
// Created by bhuwan sapkota on 2/18/16.
//

#include "Cluster.h"

using namespace Clustering;



void Cluster::__del() {
    if (__points != nullptr){
        LNodePtr current = __points;
        LNodePtr temp;

        while (current != nullptr){
            temp = current->next;
            delete current;
            current = temp;
            __size--;
        }
    }
}


void Cluster::__cpy(LNodePtr pts) {
    if(pts != nullptr){
        LNodePtr current = pts;
        LNodePtr copyCurrent = new LNode(current->point, nullptr);

        __points = copyCurrent;
        current = current->next;

        while(current != nullptr){
            copyCurrent = copyCurrent->next = new LNode(current->point, nullptr);
            current = current->next;
        }
    }

}

bool Cluster::__in(const Point &p) const {
    LNodePtr search = __points;
    while (search != nullptr){
        if(search->point == p){
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

Cluster::Cluster(const Cluster & entry) {
    __size = entry.__size;
    this->__cpy(entry.__points);
//    LNodePtr currentEntry = entry.__points;
//    __points = new LNode(currentEntry->point, nullptr);
//    LNodePtr current = __points;
//
//    for (int i = 0; i < entry.__size; ++i)
//    {
//        currentEntry = currentEntry->next;
//        current->next = new LNode(currentEntry->point, nullptr);
//        current = current->next;
//    }
}

Cluster &Cluster::operator=(const Cluster &entry) {
    __size = entry.__size;
    this->__cpy(entry.__points);
//    if(this != &entry) {
//        __size = entry.__size;
//        LNodePtr currentEntry = entry.__points;
//        __points = new LNode(currentEntry->point, nullptr);
//        LNodePtr current = __points;
//
//        for (int i = 0; i < entry.__size; ++i) {
//            currentEntry = currentEntry->next;
//            current->next = new LNode(currentEntry->point, nullptr);
//            current = current->next;
//        }
//    }
    return *this;
}

Cluster::~Cluster() {
    if (this->__points != nullptr) {
        this->__del();
    }
}

int Cluster::getSize() const {
    return __size;
}

void Cluster::add(const Point &point) {
    LNodePtr previous = nullptr;
    LNodePtr current = nullptr;
        for (current = __points; current != nullptr && point < current->point; current = current->next) {
            previous = current;
        }
        LNodePtr newNode = new LNode(point, nullptr);
        newNode->next = current;
        if (previous == nullptr) {
            __points = newNode;
        } else {
            previous->next = newNode;
        }
        __size++;

}

//const Point &Cluster::remove(const Point &point) {
//    return <#initializer#>;
//}
//
//bool Cluster::contains(const Point &point) {
//    return false;
//}
//
//const Point &Cluster::operator[](unsigned int index) const {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator+=(const Point &point) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator-=(const Point &point) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator+=(const Cluster &cluster) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator-=(const Cluster &cluster) {
//    return <#initializer#>;
//}
