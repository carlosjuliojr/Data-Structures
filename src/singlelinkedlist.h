#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include<iostream>
#include"node.h"

using namespace std;



/**
 * @brief The SingleLinkedList class
 */
template<class T>
class SingleLinkedList {

  private:

    Node<T>* head;
    Node<T>* tail;
    int size;

  public:

    ~SingleLinkedList(){}

    SingleLinkedList(){
      this->size = 0;
      this->head = nullptr;
      this->tail = nullptr;
      return;
    }

    SingleLinkedList(Node<T>* head, Node<T>* tail, int size) : head(head), tail(tail), size(size){}

    /**
     * @brief push_front
     * @param value
     */
    void push_front(const T value){

      Node<T>* newNode = new Node<T>(value);

      if(this->head == nullptr){

        this->head = newNode;
        this->tail = this->head;
        this->size++;

      }else{

        newNode->next = this->head;
        this->head = newNode;
        this->size++;

      }

    }

    /**
     * @brief push_back
     * @param value
     */
    void push_back(const T value){

      Node<T>* newNode = new Node<T>(value);

      if(this->tail == nullptr){

        this->head = newNode;
        this->tail = this->head;
        this->size++;

      }else{

        tail->next = newNode;
        tail = newNode;
        this->size++;

      }
    }

    /**
     * @brief pop_front
     */
    void pop_front() {

      Node<T>* tem;

      if(this->size == 1){

        tem = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        delete tem;

      }else if(this->size > 1){

        tem = this->head;
        this->head = tem->next;
        this->size--;
        delete tem;

      }else{
        return;
      }

    }

    /**
     * @brief pop_back
     */
    void pop_back() {

      Node<T>* tem;

      if(this->size == 0){
        return;
      }else if(this->size == 1){

        tem = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        delete tem;
        return;

      }else{

        tem = this->head;
        while(tem->next != this->tail){
          tem = tem->next;
        }

        this->tail = tem;
        tem= tem->next;
        this->size--;
        delete tem;
        return;

      }

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
     * @brief begin
     * @return
     */
    Node<T>* begin(){

      return this->head;
    }

    /**
     * @brief end
     * @return
     */
    Node<T>* end(){

      return this->tail;
    }

    /**
     * @brief empty
     * @return
     */
    bool empty(){
      if(this->size == 0)
        return true;

      return false;
    }

    /**
     * @brief insert
     * @param it
     * @param value
     */
    void insert(Node<T>* it, T value){

      Node<T>* tem, curr;

      if(this->head == it){

        Node<T>* newNode = new Node<T>(value);

        if(this->size == 1){
          this->head = newNode;
          newNode->next = tail;
        }else{
          tem = this->head;
          this->head = newNode;
          newNode->next = tem;
        }
        this->size++;
        return;

      }else{

        tem = this->head;

        while(tem->next != it && tem->next != nullptr){
          tem = tem->next;
        }

        if(tem->next == it){
          Node<T>* newNode = new Node<T>(value);
          newNode->next = it;
          tem->next = newNode;
          this->size++;
          return;
        }

      }
      return;
    }

    /**
     * @brief remove
     * @param value
     */
    void remove(const T& value){

      Node<T>* curr = this->head;
      Node<T>* tem;
      Node<T>* prev = this->head;


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
              this->size--;
              curr = curr->next;
              delete tem;

            }
          }else{

            if(curr == this->head){
              tem = curr;
              curr = curr->next;
              this->head = curr;
              prev = curr;
              this->size--;
              delete tem;
            }else{
              tem = curr;
              curr = curr->next;
              prev->next = curr;
              this->size--;
              delete tem;
            }
          }


        }else{
          prev = curr;
          curr = curr->next;

        }


      }

    }

    /**
     * @brief erase
     * @param it
     * @return
     */
    Node<T>* erase(Node<T>* it){

      Node<T>* tem;
      Node<T>* curr = this->head;
      Node<T>* prev;

      if(it == this->head){

        if(this->size > 1){

            tem = it;
            this->head = it->next;
            this->size--;
            delete tem;
            return this->head;
          }

          tem = it;
          this->head = nullptr;
          this->tail = nullptr;
          this->size--;
          delete tem;
          return nullptr;

        }else{

          while(curr != it && curr != nullptr){
            prev = curr;
            curr = curr->next;
          }

          if(curr == it){
            if(it == tail){
              tem = this->tail;
              this->tail = prev;
              prev->next = nullptr;
              this->size--;
              delete tem;
              return prev;

            }

            tem = curr;
            prev->next = curr->next;
            this->size--;
            delete tem;
            return prev->next;

          }

          return nullptr;

      }
  }

    //getter and setters

    Node<T>* getTail() const
    {
      return tail;
    }

    void setTail(Node<T>* value)
    {
      tail = value;
    }

    int getSize() const
    {
      return size;
    }

    void setSize(int value)
    {
      size = value;
    }

    Node<T>* getHead() const
    {
      return head;
    }

    void setHead(Node<T>* value)
    {
      head = value;
    }

};

#endif // SINGLELINKEDLIST_H
