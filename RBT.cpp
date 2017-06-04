#include "RBT.h"
#include <iostream>
//This cpp file is what actually does the labour. Its the algorithm that moves around the nodes and fixes everthing after.
using namespace std;
//constructor
RBT::RBT(){
  head = NULL;
}
//deconstructor
RBT::~RBT(){

}
//search function
Node* RBT::search(int number, Node* current){
  if (!current){
    current  = head;
  }
  if(number < current->getData()){
    if (current->getLeft()){
      return search(number, current->getLeft());
    }
    else return NULL;
  }
  else if(number > current->getData()){
    if (current->getRight()){
      return search(number, current->getRight());
    }
    else return NULL;
  }
  else return current;
}

//this fixes the node, changing them black
void RBT::fixToBlack(Node* black, Node* parent){
  if(black == head){
    return;
  }
  if(parent->getLeft() == black){
    if(parent->getRight()->isRed()){
      rotateLeft(parent);
      parent->setRed(true);
      parent->getParent()->setRed(false);
      fixToBlack(black, parent);
    }
    else if(!parent->isRed() && 
       !parent->getRight()->getLeft()->isRed() && 
       !parent->getRight()->getRight()->isRed()){
      parent->getRight()->setRed(true);
      fixToBlack(parent, parent->getParent());
    }
    else if(!parent->getRight()->getLeft()->isRed() &&
       !parent->getRight()->getRight()->isRed()){
      parent->getRight()->setRed(true);
      parent->setRed(false);
    }
    else if(!parent->getRight()->getRight()->isRed()){
      rotateRight(parent->getRight());
      parent->getRight()->setRed(false);
      parent->getRight()->getRight()->setRed(true);
      fixToBlack(black, parent);
    }
    else{
      rotateLeft(parent);
      parent->getParent()->getRight()->setRed(false);
      parent->getParent()->setRed(parent->isRed());
      parent->setRed(false);
    }
  }
  else {
    if(parent->getLeft()->isRed()){
      rotateRight(parent);
      parent->setRed(true);
      parent->getParent()->setRed(false);
      fixToBlack(black, parent);
    }
    else if (!parent->isRed() &&
	!parent->getLeft()->getRight()->isRed() &&
	!parent->getLeft() ->getLeft()->isRed()){
      parent->getLeft()->setRed(true);
      fixToBlack(parent, parent->getParent());
    }
    else if(!parent->getLeft()->getLeft()->isRed() &&
       !parent->getLeft()->getRight()->isRed()){
      parent->getLeft()->setRed(true);
      parent->setRed(false);
    }
    else if(!parent->getLeft()->getLeft()->isRed()){
      rotateLeft(parent->getLeft());
      parent->getLeft()->setRed(false);
      parent->getLeft()->getLeft()->setRed(true);
      fixToBlack(black, parent);
    }
    else{
      rotateRight(parent);
      parent->getParent()->getLeft()->setRed(false);
      parent->getParent()->setRed(parent->isRed());
      parent->setRed(false);
    }
  }
}
//this removes the node you want to delete
void RBT::remove(Node* deleted){
  if (deleted->getLeft() && deleted->getRight()){
    Node* swap = deleted->getRight();
    while(swap->getLeft()){
      swap = swap->getLeft();
    }
    deleted->setData(swap->getData());
    deleted = swap;
  }
  Node* parent = deleted->getParent();
  Node* child = deleted->getRight();
  if (child == NULL){
    child = deleted->getLeft();
  }
  if (deleted == head){
    head = child;
  }
  else if (deleted->isRight()){
    parent->setRight(child);
  }
  else{
    parent->setLeft(child);
  }
  if(!deleted->isRed()){
    if(child->isRed()){
      child->setRed(false);
    }
    else {
      fixToBlack(child, parent);
    }
  }
}

void RBT::fix(Node* current){//fix all the methods to balance tree
  if (current->isRed() && current->getParent()->isRed()){
    if (!current->getUncle()->isRed()){
      if(current->isRight()  && !current->getParent()->isRight()){
	rotateLeft(current->getParent());
	current = current->getLeft();
      }
      else if(!current->isRight() && current->getParent()->isRight()){
	rotateRight(current->getParent());
	current = current->getRight();
      }
      if(current->isRight()){
	current->getParent()->getParent()->setRed(true);
	current->getParent()->setRed(false);
	rotateLeft(current->getParent()->getParent());
      }
      else{
	current->getParent()->getParent()->setRed(true);
	current->getParent()->setRed(false);
	rotateRight(current->getParent()->getParent());
      }
    }
    else if (current->getUncle()->isRed()){
      current->getUncle()->setRed(false);
      current->getParent()->setRed(false);
      current->getParent()->getParent()->setRed(true);
      fix(current->getParent()->getParent());
    }
  }
  head->setRed(false);
}

void RBT::rotateRight(Node* current){ //rotates the tree to the right
  Node* nhead = current->getLeft();
  if (current == head ){
    head = nhead;
  }
  else if (current->isRight()){
    current->getParent()->setRight(nhead);
  }
  else{
    current->getParent()->setLeft(nhead);
  }
  current->setLeft(nhead->getRight());//sets the right and left after rotation
  nhead->setRight(current);
}

void RBT::rotateLeft(Node* current){//rotates the tree to the left
  Node* nhead = current->getRight();
  if (current == head){
    head = nhead;
  }
  else if(current->isRight()){
    current->getParent()->setRight(nhead);
  }
  else{
    current->getParent()->setLeft(nhead);
  }
  current->setRight(nhead->getLeft());//sets the left and right after rotation
  nhead->setLeft(current);
}

void RBT::add(Node* current, int number){//adds the number like binary search tree
  if (head == NULL){  
    head = new Node(number);
    head->setRed(true);
    fix(head);
  }
  else{
    if (number < current->getData()){//number is less than data inputted in tree
      if (current->getLeft()){//if its not null
	add(current->getLeft(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setLeft(newNode);
	fix(newNode);
      }
    }
    if (number > current->getData()){//number is greater than data inputted in tree
      if (current->getRight()){//if right is not null
	add(current->getRight(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setRight(newNode);
	fix(newNode);
      }
    }
  }
}

void RBT::print(Node* current, int indent){//print the tree
  if(current->getRight()){
    print(current->getRight(), indent+1);
  }
  for (int i = 0; i < indent; i++){
    cout << "  ";
  }
  cout << current->getData() << " " << current->isRed() << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}

Node* RBT::getHead(){
  return head;
}
