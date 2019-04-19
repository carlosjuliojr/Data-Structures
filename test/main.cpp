#include<iostream>
#include"../src/node.h"
#include"../src/singlelinkedlist.h"


using namespace std;

int main(){

  std::cout<<"testings"<<std::endl;



  SingleLinkedList<int> list;

  list.push_front(212);
  list.push_front(1);
  list.push_front(3);
  list.push_front(4);
  list.push_back(55);

  cout<< list.getTail()->getData()<<endl;
  cout<< "size of the list: "<< list.getSize()<<endl;



//  Node<int> node(12);

//  Node valor;

//  Node<int> hp(23);

//  Node tes(2);

//   cout << node.getData();

  return 0;
}
