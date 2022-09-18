#include <iostream>
#include <string>

using namespace std;

class LinkedList
{
  public:
    class Node
    {
      private: 
        Node* _next;
        Node* _prev;
        int _data;
      public:
        Node(int data);
        Node(int data, LinkedList::Node* next);
        Node(int data, LinkedList::Node* next, LinkedList::Node* prev);
        int getValue();
        Node* next();
        Node* prev();
        void setNext(Node* newNext);
        void setPrev(Node* newPrev);
    };
    
    LinkedList(int headVal);
    void insert(int value, LinkedList::Node* next, LinkedList::Node* prev);
    void prepend(int value);
    void append(int value);
    LinkedList::Node* head();
    LinkedList::Node* tail();
    LinkedList::Node* current();
    int getValue(Node* node);
    void advance();
    void retreat(); 

  private:
    LinkedList::Node* _head;
    LinkedList::Node* _tail;
    LinkedList::Node* _current;
};

LinkedList::Node::Node(int data)
{
  _next = NULL;
  _prev = NULL;
  _data = data;
}

LinkedList::Node::Node(int data, LinkedList::Node* next)
{
  _next = next;
  _prev = NULL;
  _data = data;
}

LinkedList::Node::Node(int data, LinkedList::Node* next, 
    LinkedList::Node* prev)
{
  _next = next;
  _prev = prev;
  _data = data;
}

LinkedList::LinkedList(int headVal)
{
  _head = new LinkedList::Node(headVal);
  _tail = _head;
  _current = _head;
}

void LinkedList::insert(int value, LinkedList::Node* next, 
    LinkedList::Node* prev)
{
  LinkedList::Node* newNode = new LinkedList::Node(value, next, prev);
}

LinkedList::Node* LinkedList::head()
{
  return _head;
}

LinkedList::Node* LinkedList::tail()
{
  return _tail;
}

void LinkedList::prepend(int value)
{
  LinkedList::Node* newNode = new LinkedList::Node(value, _head);
}

void LinkedList::append(int value)
{
  LinkedList::Node* newNode = new LinkedList::Node(value, NULL, _tail);
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

void LinkedList::Node::setPrev(Node* newPrev)
{
  _prev = newPrev;
}

void LinkedList::advance()
{
  if (_current->next() != NULL) _current = _current->next();
}

LinkedList::Node* LinkedList::Node::next()
{
  return _next;
}

LinkedList::Node* LinkedList::Node::prev()
{
  return _prev;
}

LinkedList::Node* LinkedList::current()
{
  return _current;
}

int main()
{
  LinkedList list(10);
  list.insert(9, list.tail(), list.head());
  list.append(8);
  list.prepend(7);
  while (list.current()->next() != NULL)
  {
    cout<<list.current()->getValue()<<" ";
    list.advance();
  }
}

