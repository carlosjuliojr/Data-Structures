#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"node.h"

template<class T>
class Stack{

    unsigned size;
    Node<T>* top;

  public:
    Stack() { this->size = 0; this->top=nullptr;}
    Stack(unsigned size, Node<T>* top) : size(size), top(top) {}
    ~Stack(){}

    //getters and setters
    unsigned getSize(){return this->size;}
    Node<T>* getTop(){return this->top;}

    void setSize(unsigned value){this->size = value;}
    void setTop(Node<T>* top) {this->top = top;}

    /**
     * @brief push
     * @param value
     */
    void push(const T& value){

      Node<T>* newNode = new Node<T>(value);

      if(this->size == 0){
        this->top = newNode;
        this->size++;
        return;
      }else{

        newNode->next = top;
        this->top = newNode;
        this->size++;
        return;
      }
      return;

    }

    /**
   * @brief pop
   */
  void pop(){

    Node<T>* tem;

    if(this->size >= 1){
      tem = this->top;
      this->top = tem->next;
      this->size--;
      delete tem;
      return;
    }
    return;

  }

  /**
   * @brief isEmpty
   * @return
   */
  bool isEmpty(){
    if(this->size == 0)
      return true;

    return false;
  }

   T&  peek(){
    return this->top->data;
  }


};

#endif // STACK_H
