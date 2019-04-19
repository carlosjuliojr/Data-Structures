#ifndef NODE_H
#define NODE_H
#include <iostream>

template<class T>
class Node{

  public:
    T data;
    Node<T>* next;


   public:

    Node() {}
    Node(T a) : data(a), next(nullptr){}
    T getData() const{return this->data;}
    Node<T>* getNext(){return this->next;}
    void setNext(Node<T>* next){this->next=next;}

};


#endif // NODE_H
