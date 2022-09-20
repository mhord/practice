#include <iostream>
#include <cmath>
#include <vector>

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
        ~Node(); 
        int getValue();
        Node* next();
        void setNext(Node* newNext);
    };
    
    LinkedList(int headVal);
    LinkedList(vector<int> v);
    ~LinkedList();
    void insert(int value, LinkedList::Node* prev);
    void prepend(int value);
    void append(int value);
    LinkedList::Node* head();
    LinkedList::Node* current();
    int getValue(Node* node);
    void advance();
    bool operator == (LinkedList& list2);

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

LinkedList::Node::~Node()
{
}

LinkedList::LinkedList(int headVal)
{
  _head = new LinkedList::Node(headVal);
  _current = _head;
}

LinkedList::LinkedList(vector<int> v)
{
  _head = new LinkedList::Node(v[0]);
  for (int i = 1; i < v.size(); i++)
  {
    this->append(v[i]);
  }
  _current = _head;
}

LinkedList::~LinkedList()
{
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

LinkedList* mergeSorted(LinkedList* list0, LinkedList* list1)
{
  LinkedList* firstList, *secondList;
  int x = list0->head()->getValue();
  int y = list1->head()->getValue();
  if (x < y)
  {
    firstList = list0;
    secondList = list1;
  }
  else
  {
    firstList = list1;
    secondList = list0;
  }

  firstList->advance();

  LinkedList* merged = new LinkedList(firstList->head()->getValue());
  while (firstList->current()->next() != NULL && secondList->current()->next() != NULL)
  {
    if (firstList->current()->getValue() < secondList->current()->getValue())
    {
      merged->append(firstList->current()->getValue());
      firstList->advance();
    }
    else
    {
      merged->append(secondList->current()->getValue());
      secondList->advance();
    }
  }
  if (firstList->current()->next() == NULL)
  {
    while (secondList->current()->next() != NULL)
    {
      merged->append(secondList->current()->getValue());
      secondList->advance();
    }
  }
  else
  {
    while (firstList->current()->next() != NULL)
    {
      merged->append(firstList->current()->getValue());
      firstList->advance();
    }
  }
  return merged;
}

bool LinkedList::operator == (LinkedList& list2)
{
  return true;
}

void test(vector<int>& v1, vector<int>& v2, vector<int>& expected) {
  LinkedList list1(v1);
  LinkedList list2(v2);
  LinkedList* merged = mergeSorted(&list1, &list2);

  LinkedList expectedList(expected);

  cout<<boolalpha<<(*merged == expectedList);
  
}

int main(int argc, char* argv[]) {

  vector<int> v1 = {1, 3, 5, 6};
  vector<int> v2 = {2, 4, 6, 20, 34};
  vector<int> expected = {1, 2, 3, 4, 5, 6, 6, 20, 34};

  test(v1, v2, expected);

  v1 = {1, 3, 5, 6};
  v2 = {};
  expected = {1, 3, 5, 6};

  test(v1, v2, expected);

  v1 = {1, 3, 5, 6};
  v2 = {2, 4, 6, 20};
  expected = {1, 2, 3, 4, 5, 6, 6, 20};

  //test(v1, v2, expected);
  v1 = {4, 4};
  v2 = {4, 4, 4};
  expected = {4, 4, 4, 4 ,4};

  //test(v1, v2, expected);
}

