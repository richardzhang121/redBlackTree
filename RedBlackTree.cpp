#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree(){
  head = NULL;
}

void rotateLeft(Node* current, Node* &head){
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
void rotateRight(Node* current,Node* &head){
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
void fix(Node* current,Node* &head){
  if (current->getParent()){  
      if (current->isRed() && current->getParent()->isRed()){
	if (!current->getUncle()){
	  if(current->isRight()){       
	    if(current->getParent()->isRight()){
	      current->getParent()->getParent()->setRed(true);
	      current->getParent()->setRed(false);
	      rotateLeft(current->getParent()->getParent(),head);
	    }
	    else{
	      rotateLeft(current->getParent(),head);
	      fix(current->getLeft(),head);
	    }
	  }
	  else{
	    if (!current->getParent()->isRight()){
	      current->getParent()->getParent()->setRed(true);
              current->getParent()->setRed(false);
	      rotateRight(current->getParent()->getParent(),head);
	    }
	    else{
	      rotateRight(current->getParent(),head);
	      fix(current->getRight(),head);
	    }
	  }
	}
	else if (!current->getUncle()->isRed()){
          if(current->isRight()){
            if(current->getParent()->isRight()){
              current->getParent()->getParent()->setRed(true);
              current->getParent()->setRed(false);
              rotateLeft(current->getParent()->getParent(),head);
            }
            else{
              rotateLeft(current->getParent(),head);
              fix(current->getLeft(),head);
            }
          }
          else{
            if (!current->getParent()->isRight()){
              current->getParent()->getParent()->setRed(true);
              current->getParent()->setRed(false);
              rotateRight(current->getParent()->getParent(),head);
            }
            else{
              rotateRight(current->getParent(),head);
              fix(current->getRight(),head);
            }
          }
        }
	else if (current->getUncle()->isRed()){
	  current->getUncle()->setRed(false);
	  current->getParent()->setRed(false);
	  current->getParent()->getParent()->setRed(true);
	  fix(current->getParent()->getParent(),head);
	}
      }
    }
  head->setRed(false);
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
	fix(newNode,head);
      }
    }
    if (number > current->getData()){
      if (current->getRight()){
	add(current->getRight(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setRight(newNode);
	fix(newNode,head);
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
  cout << current->getData() << " " << current->isRed() << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}
Node* RedBlackTree::getHead(){
  return head;
}
