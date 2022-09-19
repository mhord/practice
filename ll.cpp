#include <iostream>
#include <cmath>

using namespace std;

class LinkedList
{
  public:
    class Node
    {
      private: 
        Node* _next;
        int _data;
      public:
        Node(int data);
        Node(int data, LinkedList::Node* prev);
        int getValue();
        Node* next();
        void setNext(Node* newNext);
    };
    
    LinkedList(int headVal);
    void insert(int value, LinkedList::Node* prev);
    void prepend(int value);
    void append(int value);
    LinkedList::Node* head();
    LinkedList::Node* current();
    int getValue(Node* node);
    void advance();

  private:
    LinkedList::Node* _head;
    LinkedList::Node* _current;
};

LinkedList::Node::Node(int data)
{
  _next = NULL;
  _data = data;
}

LinkedList::Node::Node(int data, LinkedList::Node* prev)
{
  _next = prev->next();
  prev->setNext(this);
  _data = data;
}

LinkedList::LinkedList(int headVal)
{
  _head = new LinkedList::Node(headVal);
  _current = _head;
}

void LinkedList::insert(int value, LinkedList::Node* prev) 
{
  LinkedList::Node* newNode = new LinkedList::Node(value, prev);
}

LinkedList::Node* LinkedList::head()
{
  return _head;
}

void LinkedList::prepend(int value)
{
  LinkedList::Node* newNode = new LinkedList::Node(value, NULL);
  newNode->setNext(_head);
  _head = newNode;
}

void LinkedList::append(int value)
{
  LinkedList::Node* tempCurrent = _head;
  while (tempCurrent->next() != NULL) tempCurrent = tempCurrent->next();
  this->insert(value, tempCurrent); 
}

int LinkedList::Node::getValue()
{
  return _data;
}

int LinkedList::getValue(Node* node)
{
  return node->getValue();
}

void LinkedList::Node::setNext(Node* newNext)
{
  _next = newNext;
}

void LinkedList::advance()
{
  if (_current->next() != NULL) 
  {
    _current = _current->next();
  }
}
 
LinkedList::Node* LinkedList::Node::next()
{
  return _next;
}

LinkedList::Node* LinkedList::current()
{
  return _current;
}

int main()
{
  int value0 = 0;
  int value1 = 0;
  int power = 1;
  LinkedList list0(8);
  list0.append(6);
  list0.append(4);
  list0.append(2);
  LinkedList list1(9);
  list1.append(7);
  list1.append(5);
  list1.append(3);
  value0 += list0.current()->getValue();
  do 
  {
    list0.advance();
    value0 += list0.current()->getValue()*pow(10,power++);
  } while (list0.current()->next() != NULL);
  power = 1;
  value1 += list1.current()->getValue();
  do
  {
    list1.advance();
    value1 += list1.current()->getValue()*pow(10,power++);
  }  while (list1.current()->next() != NULL);
  cout<<value0<<endl;
  cout<<value1<<endl;
  int sum = value0 + value1;
  cout<<sum<<endl;
  int remainder = sum % 10;
  LinkedList result(remainder);
  sum -= remainder;
  do
  {
    sum /= 10;
    remainder = sum % 10;
    sum -= remainder; 
    result.append(remainder);
  } while (sum > 0);
  cout<<result.current()->getValue()<<endl;
  do
  {
    result.advance();
    cout<<result.current()->getValue()<<endl;
  } while (result.current()->next() != NULL);
  return 1;
}
 
