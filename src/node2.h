#ifndef NODE2_H
#define NODE2_H

template<class T>
class Node2{

  public:
    T data;
    Node2<T>* next;
    Node2<T>* prev;


   public:

    Node2() {}
    Node2(T a) : data(a), next(nullptr), prev(nullptr) {}
    T getData() const{return this->data;}
    Node2<T>* getNext(){return this->next;}
    Node2<T>* getPrev(){return this->prev;}
    void setNext(Node2<T>* next){this->next=next;}
    void setPrev(Node2<T>* prev){this->prev=prev;}

};
#endif // NODE2_H
