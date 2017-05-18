#include "Node.h"
#include <iostream>

using namespace std;

Node* Node::getLeft(){
  return left;
}
Node* Node::getRight(){
  return right;
}
Node* Node::getParent(){
  return parent;
}
Node* Node::getUncle(){
  if (parent){
    if (parent->getParent()){
      if (parent->isRight()){
	return parent->getParent()->getLeft();
      }
      else{
	return parent->getParent()->getRight();
      }
    }
  }
  else return NULL;
}
int Node::getData(){
  return data;
}
void Node::setData(int newData){
  data = newData;
}

void Node::setLeft(Node* node){
  left = node;
  if (left){
    left->setIsRight(false);
    left->setParent(this);
  }
}
void Node::setRight(Node* node){
  right = node;
  if (right){
    right->setIsRight(true);
    right->setParent(this);
  }
}
void Node::setParent(Node* node){
  parent = node;
}
Node::Node(int number){
  data = number;
  red = true;
}
Node::Node(){
  cout << "Data for New Node?" << endl;
  cin >> data;
  red = true;
}
Node::~Node(){
  delete &data;
}
bool Node::isRed(){
  if (this){
    return red;
  }
  else return false;
}
bool Node::isRight(){
  return rightChild;
}
void Node::setRed(bool isRed){
  red = isRed;
}
void Node::setIsRight(bool Right){
  rightChild = Right;
}
