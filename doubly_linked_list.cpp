#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class DoublyLinkedList
{
  public:
    class Node
    {
      public:
        Node(int value);
        Node(int value, Node* prev);
        void moveAfter(Node* newPrev);
        void moveBefore(Node* newNext);
        Node* next();
        Node* prev();
        int getValue();
        void setValue(int value);
        void setNext(Node* newNext);
        void setPrev(Node* newPrev);
      private:
        int _value;
        Node* _prev;
        Node* _next;
    };
    DoublyLinkedList();
    DoublyLinkedList(int value);
    DoublyLinkedList(vector<int> & v);
    Node* head();
    Node* tail();
    Node* current();
    int value(Node* node);
    void replaceValue(Node* node, int value);
    void deleteNode(Node* node);
    void insert(int value, Node* prev);
    void append(int value);
    void prepend(int value);
    void moveToHead(Node* nodeToMove);
    void moveToTail(Node* nodeToMove);
    void advance();
    void retreat();
    void setCurrent(Node* newCurrent);
  private:
    Node* _head;
    Node* _tail;
    Node* _current;
};

DoublyLinkedList::Node::Node(int value)
{
  _value = value;
  _prev = NULL;
  _next = NULL;
}

DoublyLinkedList::Node::Node(int value, Node* prev)
{
  _value = value;
  _next = prev->next();
  if (prev->next() != NULL)
  {
    prev->next()->setPrev(this);
  }
  prev->setNext(this);
  _prev = prev;
}

DoublyLinkedList::Node* DoublyLinkedList::Node::next()
{
  return _next;
}

DoublyLinkedList::Node* DoublyLinkedList::Node::prev()
{
  return _prev;
}

int DoublyLinkedList::Node::getValue()
{
  return _value;
}

void DoublyLinkedList::Node::setValue(int value)
{
  _value = value;
}

void DoublyLinkedList::Node::setNext(Node* newNext)
{
  _next = newNext;
}

void DoublyLinkedList::Node::setPrev(Node* newPrev)
{
  _prev = newPrev;
}

void DoublyLinkedList::Node::moveAfter(Node* newPrev)
{
  if (newPrev != NULL)
  {
    if (newPrev->_next != NULL)
    {
      newPrev->_next->_prev = this;
    }
    _next = newPrev->_next;
    _prev = newPrev;
    newPrev->_next = this;
  }
}

void DoublyLinkedList::Node::moveBefore(Node* newNext)
{
  if (newNext != NULL)
  {
    _next = newNext;
    _prev = newNext->_prev;
    if (newNext->_prev != NULL)
    {
      newNext->_prev->_next = this;
    }
  }
}

DoublyLinkedList::DoublyLinkedList()
{
  _head = NULL;
  _tail = NULL;
  _current = NULL;
}

DoublyLinkedList::DoublyLinkedList(int value)
{
  DoublyLinkedList::Node* newNode = new Node(value);
  _head = newNode;
  _tail = _head;
  _current = _head;
}

DoublyLinkedList::DoublyLinkedList(vector<int> & v)
{
  if (v.empty())
  {
    _head = NULL;
    _tail = NULL;
    _current = NULL;
    return;
  }
  DoublyLinkedList::Node* newNode = new Node(v[0]);
  _head = newNode;
  _tail = newNode;
  _current = newNode;
  for (int i = 1; i < v.size(); i++)
  {
    this->append(v[i]);
  }
}

DoublyLinkedList::Node* DoublyLinkedList::head()
{
  return _head;
}

DoublyLinkedList::Node* DoublyLinkedList::tail()
{
  return _tail;
}

DoublyLinkedList::Node* DoublyLinkedList::current()
{
  return _current;
}

int DoublyLinkedList::value(Node* node)
{
  return node->getValue();
}

void DoublyLinkedList::insert(int value, Node* prev)
{
  DoublyLinkedList::Node* newNode = new Node(value, prev);
}

void DoublyLinkedList::prepend(int value)
{
  DoublyLinkedList::Node* newNode = new Node(value);
  newNode->setNext(_head);
  newNode->setPrev(NULL);
  _head->setPrev(newNode);
  _head = newNode;
}

void DoublyLinkedList::append(int value)
{
  DoublyLinkedList::Node* newNode = new Node(value);
  newNode->setPrev(_tail);
  newNode->setNext(NULL);
  _tail->setNext(newNode);
  _tail = newNode;
}

void DoublyLinkedList::moveToHead(Node* nodeToMove)
{
  if (nodeToMove == _head)
  {
    return;
  }
  nodeToMove->moveBefore(_head);
  _head = nodeToMove;
}

void DoublyLinkedList::moveToTail(Node* nodeToMove)
{
  if (nodeToMove == _tail)
  {
    return;
  }
  if (nodeToMove == _head)
  {
    _head = nodeToMove->next();
  }
  if (nodeToMove->prev())
  {
    nodeToMove->prev()->setNext(nodeToMove->next());
  }
  nodeToMove->next()->setPrev(nodeToMove->prev());
  nodeToMove->setNext(NULL);
  nodeToMove->setPrev(_tail);
  _tail->setNext(nodeToMove);
  _tail = nodeToMove;
}

void DoublyLinkedList::advance()
{
  _current = _current->next();
}

void DoublyLinkedList::retreat()
{
  _current = _current->prev();
}

void DoublyLinkedList::setCurrent(Node* newCurrent)
{
  _current = newCurrent;
}

void DoublyLinkedList::replaceValue(Node* node, int value)
{
  node->setValue(value);
}

void DoublyLinkedList::deleteNode(Node* node)
{
  if (node == _head)
  {
    _head = node->next();
    delete node;
    return;
  }
  if (node == _tail)
  {
    _tail = node->prev();
    delete node;
    return;
  }

  if (node != NULL)
  {
    if (node->prev() != NULL)
    {
      node->prev()->setNext(node->next());
    }
    if (node->next() != NULL)
    {
      node->next()->setPrev(node->prev());
    }
    delete node;
  }
}

void printDLL(DoublyLinkedList* list)
{
  int limit = 0;
  list->setCurrent(list->head());
  while (list->current() != NULL)
  {
    cout<<list->value(list->current())<<" ";
    list->advance();
    if (limit++ > 20)
    {
      break;
    }
  }
  cout<<endl;
}

void findInCache(DoublyLinkedList* list, int value)
{
  list->setCurrent(list->head());
  while (list->current() != NULL)
  {
    if (list->current()->getValue() == value)
    {
      break;
    }
    list->advance();
  }
  if (list->current() == NULL)
  {
    cout<<"Cache miss on "<<value<<endl;
    list->append(value);
    list->deleteNode(list->head());
  }
  else
  {
    cout<<"Cache hit on "<<value<<endl;
    list->moveToTail(list->current());
  }
}
  

int main()
{
  vector<int> v = {1, 2, 3, 4};
  vector<int> lookups = {5, 4, 7, 3, 9, 10};
  DoublyLinkedList cache(v);
  printDLL(&cache);

  for (int i = 0; i < lookups.size(); i++)
  {
    findInCache(&cache, lookups[i]);
    printDLL(&cache);
  }
}
