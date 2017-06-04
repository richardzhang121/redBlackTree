#include "Node.h"
#include <iostream>


class RBT{
 public://all the methods
  RBT();//constructor
  ~RBT();//deconstructor
  void rotateRight(Node* current);
  void rotateLeft(Node* current);
  void print(Node* current, int indent = 0);
  void add(Node* current, int data);
  void fix(Node* current);
  Node* getHead();
  Node* search(int number, Node* current = NULL);
  void fixToBlack(Node* black, Node* parent);
  void remove (Node* deleted);
 private://the variables
  Node* head;
};
