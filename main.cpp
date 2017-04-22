#include <iostream>
#include <fstream>
#include <cstring>
#include "RBT.h"
#include "Node.h"

using namespace std;

void addNode(Node* head, int number, Node* &treeHead);
void printTree(Node* head, int level);
bool nodeDelete(Node* head, int number);



int main(){
    RedBlackTree* tree = new RedBlackTree();
    char input[128];
    bool running = true;
    
    while (running == true){
        cout << "Please type in ADD, PRINT, DELETE(which is still in progress ahahahaha), or QUIT to continue << endl;
        cin.get(input, 30);
        if (!strcmp(input, "ADD"){
            addNode();
        else if(!strcmp(input, "PRINT")){
            if (head){
                printTree(head, 0);
            }
        }
        else if (!strcmp(input, "QUIT")) {
            running = false;
        }
        else{
            cout << "I am not sure what you mean. Sorry. Please type in ADD, SEARCH, PRINT, or QUIT to continue (the DELETE command is still in progress)" << endl;
        }
    }
}
