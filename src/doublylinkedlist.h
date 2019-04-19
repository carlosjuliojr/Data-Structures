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

    /**
     * @brief begin
     * @return
     */
    Node2<T>* begin(){
      return this->head;
    }

    /**
     * @brief end
     * @return
     */
    Node2<T>* end(){
      return this->tail;
    }

    /**
     * @brief insert
     * @param value
     */
    void insert(T value){
      this->push_front(value);
    }

    /**
     * @brief insert
     * @param it
     * @param value
     */
    void insert(Node2<T>* it,const T& value){

      Node2<T>* tem,*curr, *prev;
      Node2<T>* newNode = new Node2<T>(value);

      if(this->head == it){

        tem = this->head;
        this->head = newNode;
        this->head->next = tem;
        tem->prev = this->head;
        this->size++;
        return;

      }else if(this->tail == it){

        prev = this->tail->prev;
        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = this->tail;
        this->tail->prev = newNode;
        this->size++;
        return;


      }else{

        curr = this->head;

        while(curr != this->tail && curr != it){
          curr = curr.next;
        }

        if(curr == it){

          prev = curr->prev;
          prev->next = newNode;
          newNode->prev = prev;
          newNode->next = curr;
          curr->prev = newNode;
          this->size++;
          return;
        }
        return;
      }


      return;
    }

    /**
     * @brief remove
     * @param value
     */
    void remove(const T& value){

      Node2<T>* curr = this->head;
      Node2<T>* tem;


      while(curr != nullptr){


        if(curr->data == value){
          if(this->size == 1){

            tem = this->head;
            this->tail = nullptr;
            this->head = nullptr;
            this->size--;
            curr = curr->next;
            delete tem;

          }else if(curr == this->tail){
            if(this->size == 2){

              tem = this->tail;
              this->tail = this->head;
              this->head->next = nullptr;
              this->size--;
              curr = curr->next;
              delete tem;

            }
          }else{

            if(curr == this->head){
              tem = curr;
              curr = curr->next;
              this->head = curr;
              this->head->prev = nullptr;
              this->size--;
              delete tem;
            }else{
              tem = curr;
              curr = curr->next;
              tem->prev->next = curr;
              this->size--;
              delete tem;
            }
          }


        }else{
          curr = curr->next;

        }


      }

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

