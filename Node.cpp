//Node.cpp file
#include "Node.h"
#include <iostream>

using namespace std;

Node* Node::getLeft(){ //gets left node
  return left;
}

Node* Node::getRight(){ //gets right node
  return right;
}

Node* Node::getParent(){ //gets parent node
  return parent;
}

Node* Node::getUncle(){ //gets uncle node
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

int Node::getData(){ //gets data
  return data;
}

void Node::setLeft(Node* node){//sets new left node
  left = node;
  if (left){
    left->setIsRight(false);
    left->setParent(this);
  }
}
void Node::setRight(Node* node){//sets right node
  right = node;
  if (right){
    right->setIsRight(true);
    right->setParent(this);
  }
}

void Node::setParent(Node* node){ //sets parent node
  parent = node;
}

Node::Node(int number){ // initializes node
  data = number;
  red = true;
}

Node::Node(){ //node function (inputs user data)
  cout << "Data for New Node?" << endl;
  cin >> data;
  red = true;
}

Node::~Node(){ // deconstructor
  delete &data;
}

bool Node::isRed(){ //if node is red
  return red;
}

bool Node::isRight(){//returns the right child
  return rightChild;
}

void Node::setRed(bool isRed){//sets new red node
  red = isRed;
}

void Node::setIsRight(bool Right){//sets right child node
  rightChild = Right;
}