#include<gtest/gtest.h>
#include"singlelinkedlist.h"

/**
 * @brief TEST
 */
TEST(test1, test_pust_front)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_front(1);


      ASSERT_EQ(myList->front(),1);

      myList->push_front(10);
      ASSERT_EQ(myList->front(),10);
      myList->push_front(10);
      myList->push_front(0);


      ASSERT_EQ(myList->front(),0);

delete myList;
}

/**
 * @brief TEST
 */
TEST(test2, test_back)
{

    SingleLinkedList<int>* myList = new SingleLinkedList<int>;


      myList->push_back(1);
      myList->push_back(11);
      myList->push_back(10);


      ASSERT_EQ(myList->back(),10);
      ASSERT_EQ(myList->front(),1);
      ASSERT_EQ(myList->getHead()->getNext()->getData(),11);

      delete myList;

}
/**
 * @brief TEST
 */
TEST(test3, test_push_back)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_back(2);
      myList->push_back(4);
      myList->push_back(6);


      Node<int>* tmp = myList->begin();

      int i = 2;
      while(tmp != nullptr){


          ASSERT_EQ(tmp->getData(),i);
          tmp = tmp->getNext();
          i+=2;

      }

      delete myList;

}

/**
 * @brief TEST
 */
TEST(test4, test_push_front)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_front(2);
      myList->push_front(4);
      myList->push_front(6);


      Node<int>* tmp = myList->begin();
      int i = 6;
      while(tmp != nullptr){

          ASSERT_EQ(tmp->getData(),i);
          tmp = tmp->getNext();
          i-=2;

      }
      delete myList;

}

/**
 * @brief TEST
 */
TEST(test5, test_empty)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;


      ASSERT_TRUE(myList->empty());

      myList->push_front(2);
      myList->push_front(2);

      ASSERT_FALSE(myList->empty());

      myList->pop_front();

      ASSERT_FALSE(myList->empty());

      myList->pop_front();
      ASSERT_TRUE(myList->empty());
      delete myList;

}

/**
 * @brief TEST
 */
TEST(test6, test_pop_front)
{

     SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_front(2);
      myList->push_front(3);


      // 3 => 2 => null
      myList->pop_front();

      ASSERT_EQ(myList->front(), 2);
      // 2 => null
      myList->pop_front();
        // null therefore the list is empty
       ASSERT_TRUE(myList->empty());

delete myList;

}

/**
 * @brief TEST
 */
TEST(test7, test_pop_back)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_front(2);
      myList->push_front(3);
      myList->push_front(4);
      myList->push_front(5);


      // 5 => 4 => 3 => 2 => null
      myList->pop_back();

      myList->pop_back();


      ASSERT_EQ(myList->back(), 4);
      // 5 => 4 => null
      myList->pop_back();
      ASSERT_EQ(myList->back(), 5);

      myList->pop_back();
     ASSERT_TRUE(myList->empty());

delete myList;

}

/**
 * @brief TEST
 */
TEST(test8, test_insert)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_front(4);
      myList->push_front(9);



      // 9 => 4 => null

      ASSERT_EQ(myList->front(),9);
      ASSERT_EQ(myList->back(),4);
      ASSERT_EQ(myList->getSize(),2);


      myList->insert(myList->getHead(),3);
       //3 => 9 => 4 => null
      //it    ^
      ASSERT_EQ(myList->begin()->getData(),3);
      ASSERT_EQ(myList->getSize(),3);
      myList->push_back(-2);
      myList->push_back(-7);


      // 3 => 9 => 4 => -2 => -7 => null
      ASSERT_EQ(myList->front(),3);
      ASSERT_EQ(myList->back(),-7);

//******************************************************************

      Node<int>* it = myList->begin();


      // 3 => 9 => 4 => -2 => -7 => null
      // ^
      myList->insert(it,0);

      // 0 => 3 => 9 => 4 => -2 => -7 => null
   //it       ^
      ASSERT_EQ(myList->front(),0);
      ASSERT_EQ(myList->begin()->getNext()->getData(),3);

      it = it->getNext();

      // 0 => 3 => 9 => 4 => -2 => -7 => null
      //it         ^

      myList->insert(it,10);

      // 0 => 3 => 10 => 9 => 4 => -2 => -7 => null
      //it               ^

      ASSERT_EQ(myList->getHead()->getNext()->getNext()->getData(),10);

      it = myList->end();

      // 9 => 0 => 10 => 3 => 4 => -2 => -7 => null
      //it                                ^
      myList->insert(it,25);

      // 9 => 0 => 10 => 3 => 4 => -2 => 25 => -7 => null
      //it                                      ^

      ASSERT_EQ(it->getData(),-7);
      ASSERT_EQ(myList->getSize(),8);

      delete myList;

}


TEST(test9, test_erase)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

      myList->push_front(4);
      myList->push_front(3);
      myList->push_front(2);
      myList->push_front(1);

      // 1  => 2  => 3  => 4 => null

      Node<int>* it = myList->begin();

      // 1  => 2  => 3  => 4 => null
      // ^
      Node<int>* itReturn = myList->erase(it);

      // 2  => 3  => 4 => null
      // ^
      ASSERT_EQ(itReturn->data,2);


      it = it->next->next;

      // 2  => 3  => 4 => null
            // ^

      itReturn = myList->erase(it);

      // 2  => 4 => null
      // ^
      ASSERT_EQ(itReturn->data,4);

      it =myList->end();

      // 2  => 4 => null
            // ^

      itReturn = myList->erase(it);

      // 2  => null
      // ^
      ASSERT_EQ(itReturn->data,2);


      // 2  => null
      // ^

      itReturn = myList->erase(itReturn);


      ASSERT_EQ(itReturn,nullptr);

      delete myList;

}

TEST(test10, test_remove)
{

   SingleLinkedList<int>* myList = new SingleLinkedList<int>;

   myList->push_front(10);
   myList->remove(10);

   ASSERT_EQ(myList->getSize(),0);


      myList->push_front(4);
      myList->push_front(3);
      myList->push_front(3);
      myList->push_front(1);

      // 1  => 3  => 3  => 4 => null
      // ^
       myList->remove( 1 );
       ASSERT_EQ(myList->begin()->getData(),3);

        //  3  => 3  => 4 => null
                     // ^
       myList->remove( 4 );

       ASSERT_EQ(myList->end()->getData(),3);


//         3  => 3  => null
//         ^     ^


       myList->remove( 3 );

       ASSERT_TRUE(myList->empty());


      delete myList;

}


