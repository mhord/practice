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
    
    LinkedList();
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

LinkedList::LinkedList()
{
  _head = NULL;
  _current = NULL;
}

LinkedList::LinkedList(int headVal)
{
  _head = new LinkedList::Node(headVal);
  _current = _head;
}

LinkedList::LinkedList(vector<int> v)
{
  if (v.empty()) 
  {
    _head = NULL;
    _current = NULL;
    return;
  }
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
  if (tempCurrent != NULL)
  {
    while (tempCurrent->next() != NULL) tempCurrent = tempCurrent->next();
    this->insert(value, tempCurrent); 
    return;
  }
  LinkedList::Node* newNode = new LinkedList::Node(value);
  _head = newNode;
  _current = _head;
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
  if (_current == NULL) return;
  _current = _current->next();
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
  int x, y;
  LinkedList* merged = new LinkedList();
  if (list0->head() != NULL && list1->head() != NULL)
  {
    x = list0->head()->getValue();
    y = list1->head()->getValue();
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

    merged->append(firstList->current()->getValue());
    firstList->advance();

    do
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
    } while (firstList->current() != NULL && secondList->current() != NULL);
  }
  else
  {
    firstList = list0;
    secondList = list1;
  }
  if (firstList->current() != NULL)
  {
    do
    {
      merged->append(firstList->current()->getValue());
      firstList->advance();
    } while (firstList->current() != NULL);
  }
  if (secondList->current() != NULL)
  {
    do
    {
      merged->append(secondList->current()->getValue());
      secondList->advance();
    } while (secondList->current() != NULL);
  }
  
  return merged;
}

bool LinkedList::operator == (LinkedList& list2)
{
  LinkedList::Node* temp1 = this->head();
  LinkedList::Node* temp2 = list2.head();

  while (temp1 != NULL && temp2 != NULL)
  {
    if (temp1->getValue() != temp2->getValue()) return false;
    temp1 = temp1->next();
    temp2 = temp2->next();
  }
  if (temp1 != NULL) return false;
  if (temp2 != NULL) return false;

  return true;
}

void printLinkedList(LinkedList* list)
{
  int limit = 0;
  if (list->head() != NULL)
  {
    while (list->current()->next() != NULL)
    {
      cout<<list->current()->getValue()<<" ";
      list->advance();
      if (limit > 20) break;
    }
    cout<<list->current()->getValue()<<endl;
  }
}

void test(vector<int>& v1, vector<int>& v2, vector<int>& expected) {
  LinkedList list1(v1);
  LinkedList list2(v2);
  LinkedList expectedList(expected);

  LinkedList* merged = mergeSorted(&list1, &list2);
  
  printLinkedList(&expectedList);
  printLinkedList(merged); 

  cout<<boolalpha<<(*merged == expectedList)<<endl;
  
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

  test(v1, v2, expected);
  v1 = {4, 4};
  v2 = {4, 4, 4};
  expected = {4, 4, 4, 4 ,4};

  test(v1, v2, expected);
}

