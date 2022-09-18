#include <iostream>
#include <vector>

class Btree
{
  public:
    class Node
    {
      private: 
        Node* _left;
        Node* _right;
        int _value;
      public:
        Node(int value);
        int value();
        void setValue(int value);
        Node* right();
        Node* left();
        void setRight(Node* node);
        void setLeft(Node* node);
    };
    Btree(int rootValue);
    Node* root();
    void inOrderPrint();
    void postOrderPrint(Node* rootNode);
    bool operator == (Btree &bTree1)
    {
      bTree1._inOrderVector.clear();
      this->_inOrderVector.clear();
      inOrderVectorCreate(bTree1.root());
      inOrderVectorCreate(this->root());
      return bTree1._inOrderVector == this->_inOrderVector;
    };

  private:
    Node* _rootNode;
    std::vector<int> _inOrderVector;
    void inOrderVectorCreate(Node* node);
};

Btree::Btree(int rootValue)
{
  _rootNode = new Node(rootValue);
}

void Btree::postOrderPrint(Node* rootNode)
{
  if (rootNode->left() != NULL)
  {
    postOrderPrint(rootNode->left());
  }
  if (rootNode->right() != NULL)
  {
    postOrderPrint(rootNode->right());
  }
  std::cout<<rootNode->value()<<" ";
}

void Btree::inOrderVectorCreate(Node* rootNode)
{
  if (rootNode->left() != NULL)
  {
    inOrderVectorCreate(rootNode->left());
  }
  _inOrderVector.push_back(rootNode->value());
  if (rootNode->right() != NULL)
  {
    inOrderVectorCreate(rootNode->right());
  }
}

Btree::Node* Btree::root()
{
  return _rootNode; 
}

void Btree::inOrderPrint()
{
  _inOrderVector.clear();
  inOrderVectorCreate(this->root());
  std::cout << "v = { ";
  for (int n : _inOrderVector) {
      std::cout << n << ", ";
  }
  std::cout << "}; \n";
}

Btree::Node::Node(int value)
{
  _value = value;
  _right = NULL;
  _left = NULL;
}

int Btree::Node::value()
{
  return _value;
}

void Btree::Node::setValue(int value)
{
  _value = value;
}

Btree::Node* Btree::Node::left()
{
  return _left;
}

Btree::Node* Btree::Node::right()
{
  return _right;
}

void Btree::Node::setLeft(Node* node)
{
  _left = node;
}

void Btree::Node::setRight(Node* node)
{
  _right = node;
}

//                     10
//                /          \
//               9            7
//              / \
//             8   6
int main()
{
  Btree tree0(10), tree1(10);
  tree0.root()->setLeft(new Btree::Node(9));
  tree0.root()->left()->setLeft(new Btree::Node(8));
  tree0.root()->setRight(new Btree::Node(7));
  tree0.root()->left()->setRight(new Btree::Node(6));
  tree1.root()->setRight(new Btree::Node(7));
  tree1.root()->setLeft(new Btree::Node(9));
  tree1.root()->left()->setRight(new Btree::Node(6));
  tree1.root()->left()->setLeft(new Btree::Node(8));
  tree0.inOrderPrint();
  std::cout<<std::endl;
  tree1.inOrderPrint();
  std::cout<<std::boolalpha;
  std::cout<<(tree1 == tree0)<<std::endl; 
}

