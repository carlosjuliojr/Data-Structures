#include<gtest/gtest.h>
#include"stack.h"

/**
 * @brief TEST
 */
TEST(test1, test_pust)
{

   Stack<int>* myStack = new Stack<int>;

      myStack->push(1);


      ASSERT_EQ(myStack->peek(),1);

      myStack->push(10);
      ASSERT_EQ(myStack->peek(),10);
      myStack->push(10);
      myStack->push(0);


      ASSERT_EQ(myStack->peek(),0);

delete myStack;
}


/**
 * @brief TEST
 */
TEST(test2, test_pop)
{

     Stack<int>* myStack = new Stack<int>;

      myStack->push(2);
      myStack->push(3);


      // 3 => 2 => null
      myStack->pop();

      ASSERT_EQ(myStack->peek(), 2);
      // 2 => null
      myStack->pop();
        // null therefore the list is empty
       ASSERT_TRUE(myStack->isEmpty());

delete myStack;

}

TEST(test3, test_isEmpty)
{

     Stack<int>* myStack = new Stack<int>;

      myStack->push(2);
      myStack->push(3);


      ASSERT_FALSE(myStack->isEmpty());

      // 3 => 2 => null
      myStack->pop();
      myStack->pop();
        // null therefore the list is empty
       ASSERT_TRUE(myStack->isEmpty());

delete myStack;

}

TEST(test4, test_peek)
{

     Stack<int>* myStack = new Stack<int>;

      myStack->push(2);
      myStack->push(3);


      // 3 => 2 => null
      myStack->peek() += 3;

      ASSERT_EQ(myStack->peek(), 6);
      // 2 => null
      myStack->pop();
      myStack->peek() += 10;
      ASSERT_EQ(myStack->peek(), 12);
      ASSERT_EQ(myStack->getSize(), 1);
      ASSERT_FALSE(myStack->isEmpty());

delete myStack;

}



