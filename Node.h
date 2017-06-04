//node.h file
class Node{
 public:
  Node(int newdata);
  Node();
  ~Node();
  Node* getParent();
  Node* getRight();
  Node* getLeft();
  Node* getUncle();

  int getData(); 
  void setData(int newData);
  void setLeft(Node* node);
  void setRight(Node* node);
  void setParent(Node* node);

  bool isRed();
  void setRed(bool isRed);
  bool isRight();
  void setIsRight(bool isRight);
 private:
  int data;
  Node* left;
  Node* right; 
  Node* parent;
  bool red;
  bool rightChild;
};
