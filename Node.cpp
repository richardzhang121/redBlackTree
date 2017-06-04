#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int newdata){
  data = newdata;
  left = NULL;
  right = NULL;
  parent= NULL;
  red = true;
}

Node::Node(){
  cout << "What's the data of the node?" << endl;
  cin >> data;
  red = true;
  parent = NULL;
}

Node::~Node(){
  delete &data; 
}
//getter functions
Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}


Node* Node::getParent(){
  return parent;
}

int Node::getData(){
  return data;
}
//settter functions
void Node::setData(int newData){
  data = newData;
}



void Node::setLeft(Node* node){
  left = node;
  if (left!= NULL){
    left->setIsRight(false);
    left->setParent(this);
  }  
}

void Node::setRight(Node* node){
  right = node;
  if (right != NULL){
    right->setIsRight(true);
    right->setParent(this);
  }
 }

void Node::setParent(Node* node){
  parent = node;
}

Node* Node::getUncle(){
  if (parent != NULL){
    if (parent->getParent() != NULL){
      if (parent->isRight()){
	return parent->getParent()->getLeft();
      }
      else{
	return parent->getParent()->getRight();
      }
    }
  }
  else {
    return NULL;
  }
}

bool Node::isRed(){
  if(this){
    return red;
  }
  else {
    return false;
  }
}


void Node::setRed(bool isRed){
  red = isRed;
}

bool Node::isRight(){
  return rightChild;
}

void Node::setIsRight(bool isRight){
  rightChild = isRight;
}
