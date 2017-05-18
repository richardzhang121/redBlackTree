#include <iostream>
#include "Node.h"

using namespace std;

class RedBlackTree{
 private:
  Node* head;
  void rotateLeft(Node* current);
  void rotateRight(Node* current);
  void fix(Node* current);
  void fix2Black(Node* black, Node* parent);

 public:
  RedBlackTree();
  void add(Node* current, int number);  
  void print(Node* current, int indent = 0);
  Node* getHead();
  Node* search(int number, Node* current = NULL);
  void remove(Node* toDelete);

};
