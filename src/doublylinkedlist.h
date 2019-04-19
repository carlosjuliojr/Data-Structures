#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include<iostream>
#include"node2.h"

using namespace std;

template <class T>
class DoublyLinkedList{

    Node2<T>* head;
    Node2<T>* tail;
    unsigned size;





  public:

    /**
     * @brief push_front
     * @param value
     */
    void push_front(T value){

      Node2<T>* newNode = new Node2<T>(value);

      if(this->size == 0){
        this->head = newNode;
        this->tail = newNode;
        this->size++;

      }else{
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
      }
      return;
    }

    /**
     * @brief push_back
     * @param value
     */
    void push_back(T value){
      Node2<T>* newNode = new Node2<T>(value);

      if(this->size == 0){
        this->head = newNode;
        this->tail = newNode;
        this->size++;

      }else{
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->size++;
      }
      return;


    }

    /**
     * @brief pop_front
     */
    void pop_front(){

      Node2<T>* tem;

      if(this->size == 1){

        tem = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        delete tem;
        return;


      }else{

        tem = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        this->size--;
        delete tem;
        return;
      }
      return;
    }

    /**
     * @brief pop_back
     */
    void pop_back(){

      Node2<T>* tem;

      if(this->size == 1){

        tem = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        delete tem;

        return;
      }else{

        tem = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        this->size--;
        delete tem;

        return;
      }

      return;
    }



    /**
     * @brief front
     * @return
     */
    const T front(){

      return this->head->data;

    }

    /**
     * @brief back
     * @return
     */

    const T back(){

      return this->tail->data;
    }

    /**
     * @brief empty
     * @return
     */
    bool empty(){

      if(this->size == 0){

        return true;

      }
          return false;
    }


    //constructors
    /**
     * @brief DoublyLinkedList
     */
    DoublyLinkedList(){

      this->head = nullptr;
      this->tail = nullptr;
      this->size = 0;
    }

    DoublyLinkedList(Node2<T>* head, Node2<T>* prev, unsigned size) :
      head(head), tail(tail), size(size) {}

    ~DoublyLinkedList(){}

    // getters and setters
    Node2<T>* getHead() const { return this->head;}
    Node2<T>* getPrev() const { return this->prev;}
    void setHead(Node2<T>* value) { this->head = value;}
    void setPrev(Node2<T>* value) { this->prev = value;}
    unsigned getSize() const {return this->size;}
    void setSize(unsigned value) {this->size = value;}

};

#endif

