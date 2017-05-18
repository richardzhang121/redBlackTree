#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree(){
  head = NULL;
}

void RedBlackTree::rotateLeft(Node* current){
  Node* newHead = current->getRight();
  if (current == head){
    head = newHead;
      }
  else if (current->isRight()){
    current->getParent()->setRight(newHead);
  }
  else{
    current->getParent()->setLeft(newHead);
  }
  current->setRight(newHead->getLeft());
  newHead->setLeft(current);
}
void RedBlackTree::rotateRight(Node* current){
  Node* newHead = current->getLeft();
  if (current == head){
    head = newHead;
      }
  else if (current->isRight()){
    current->getParent()->setRight(newHead);
  }
  else{
    current->getParent()->setLeft(newHead);
  }
  current->setLeft(newHead->getRight());
  newHead->setRight(current);
}

void RedBlackTree::fix(Node* current){
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

void RedBlackTree::fix2Black(Node* black,Node* parent){
  if (black == head) return;
  if (parent->getLeft() == black){
   if (parent->getRight()->isRed()){
      rotateLeft(parent);
      parent->setRed(true);
      parent->getParent()->setRed(false);
      fix2Black(black,parent);
    }
    else if (!parent->isRed() && 
	     !parent->getRight()->getRight()->isRed() &&
	     !parent->getRight()->getLeft()->isRed()){
      parent->getRight()->setRed(true);
      fix2Black(parent,parent->getParent());
    }
    else if (parent->isRed() && 
	     !parent->getRight()->getRight()->isRed() &&
             !parent->getRight()->getLeft()->isRed()){
      parent->setRed(false);
      parent->getRight()->setRed(true);
      return;
    }
    else if(parent->getRight()->getLeft()->isRed()){
      rotateRight(parent->getRight());
      parent->getRight()->getRight()->setRed(true);
      parent->getRight()->setRed(false);
      fix2Black(black,parent);
    }
    else if (parent->getRight() -> getLeft() -> isRed()){
      rotateRight(parent->getRight());
      parent -> getRight() -> getRight()->setRed(true);
      parent -> getRight()->setRed(false);
      fix2Black(black, parent);
    }
    else{
      rotateLeft(parent);
      parent->getParent()->setRed(parent->isRed());
      parent->setRed(false);
      parent->getParent()->getRight()->setRed(false);
      return;
    }
  }
  else{
    if (parent->getLeft()->isRed()){
      rotateRight(parent);
      parent->setRed(true);
      parent->getParent()->setRed(false);
      fix2Black(black,parent);
    }
    else if (!parent->isRed() &&
             !parent->getLeft()->getRight()->isRed() &&
             !parent->getLeft()->getLeft()->isRed()){
      parent->getLeft()->setRed(true);
      fix2Black(parent,parent->getParent());
    }
    else if(parent->getLeft()->getRight()->isRed()){
      rotateLeft(parent->getLeft());
      parent->getLeft()->getLeft()->setRed(true);
      parent->getLeft()->setRed(false);
      fix2Black(black,parent);
    }
    else{
      rotateRight(parent);
      parent->getParent()->setRed(parent->isRed());
      parent->setRed(false);
      parent->getParent()->getLeft()->setRed(false);
      return;
    }
  }
}
void RedBlackTree::remove(Node* toDelete){
  if(toDelete->getRight() && toDelete->getLeft()){
    Node* swap = toDelete->getRight();
    while (swap->getLeft()){
      swap = swap->getLeft();
    }
    toDelete->setData(swap->getData());
    toDelete = swap;
  } 
  Node* parent = toDelete->getParent();
  Node* child = toDelete->getRight();
  if(!child){
    child = toDelete->getLeft();
  }
 
  if (toDelete == head){
    head = child;
  }
  
  if (toDelete->isRight()){
    parent->setRight(child);
  }
  else parent->setLeft(child);
  
  if(!toDelete->isRed()){
    if(child->isRed()){
      child->setRed(false);
    }
    else{
      fix2Black(child,parent);
    }
  }
}
  
 
Node* RedBlackTree::search(int number, Node* current){
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
void RedBlackTree::add(Node* current, int number){
  if (head == NULL){
   
    head = new Node(number);
    head->setRed(false);
  }
  else{
 
    if (number < current->getData()){
      if (current->getLeft()){
	add(current->getLeft(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setLeft(newNode);
	fix(newNode);
      }
    }
    if (number > current->getData()){
      if (current->getRight()){
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
void RedBlackTree::print(Node* current, int indent){
  if(current->getRight()){
    print(current->getRight(), indent+1);
  }
  for (int i = 0; i < indent; i++){
    cout << "  ";
  }
  cout << current->getData() << " "; 
  current->isRed() ? cout << "R" << endl : cout << "B" << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}
Node* RedBlackTree::getHead(){
  return head;
}
