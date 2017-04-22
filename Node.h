#ifndef NODE_H
#define NODE_H

using namespace std;


class Node{
 public:
  Node(int newData);
  Node();
  ~Node();
  Node* getParent();
  Node* getLeft();
  Node* getRight();
  Node* getUncle();
  int getData();
  void setLeft(Node* node);
  void setRight(Node* node);
  void setParent(Node* node);
  bool isRed();
  void setRed(bool isRed);
  void isRight();
  void setIsRight(bool isRight);
 protected:
  int data;
  Node* parent;
  Node* left;
  Node* right;
  bool red;
  bool rightchild;
};

#endif