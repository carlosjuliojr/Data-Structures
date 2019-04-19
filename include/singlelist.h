#ifndef SINGLELIST_H
#define SINGLELIST_H
#include <iostream>

template<typename T>
class Node{
    int data;
    Node<T>* next;


   public:
   Node(T a);
   T getData() const;


};


#endif // SINGLELIST_H
