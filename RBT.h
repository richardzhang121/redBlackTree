#include <iostream>
#include "Node.h"

using namespace std;

class RBT{
    public:
        RBT();
        void print(Node* current, int index);
        Node* getHead();
    private:
        Node* head;
}