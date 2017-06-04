//Nodes that will be used in a red Black tree
#ifndef NODE_H
#define NODE_H

using namespace std;


class Node{
 public:
  Node(int newData);
  Node();
  ~Node();
  Node* getParent();
  Node* getLeft(); //returns the next node
  Node* getRight();
  Node* getUncle();
  int getData(); //returns the student the node points to
  void setData(int newData);
  void setLeft(Node* node); //sets the pointer to the next node
  void setRight(Node* node);
  void setParent(Node* node);
  bool isRed();
  void setRed(bool isRed);
  bool isRight();
  void setIsRight(bool isRight);
 protected:
  int data;
  Node* left;
  Node* right;
  Node* parent;
  bool red;
  bool rightChild;
};


#endif
