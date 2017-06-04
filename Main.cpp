#include <iostream>
#include <fstream>
#include <cstring>
#include "RBT.h"

using namespace std;
//This reads the files in
void checkInput(ifstream &stream, bool &isFile){ 
  char input[128];
  isFile = false;
  cout << "Choose whether to input manually or from a file (input/file)" << endl;
  cin.getline(input,128);
  if (0== strcmp(input, "file")){
    char name[128];
    cout << "What file?" << endl;
    cin.getline(name, 128);
    stream.open(name);
    if(stream.is_open()){
      isFile = true;
      cout << "Enter a command above." << endl;
    }
    else {
      cout << "The file could not be opened" << endl;
    }
  }
  if (0==strcmp(input, "input")){
    cout << "Enter the numbers please." << endl;
  }
}
void addNumbers(istream &from, RBT* tree){
 
  int newInput;
  from >> newInput;
  tree->add(tree->getHead(), newInput);
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){
      from >> newInput;
      tree->add(tree->getHead(),newInput);
    }
    else{
      from.ignore();
    }
  }
}


// main method
int main(){
 
  RBT* tree = new RBT();
  char input[128];
  bool running = true;
  while(running == true){
    cout << "add, delete, print, search and quit are all valid commands" << endl;
    cin.getline(input, 128);
    if(0==strcmp(input, "add")){//adding the node.
      ifstream stream;
      bool isFile;
      checkInput(stream, isFile);
      addNumbers(isFile ? stream : cin, tree);
      if(isFile) stream.close();
      cin.ignore();
    }
    else if(0==strcmp(input, "print")){//prints
      if (tree->getHead() == NULL){
	cout << "There's nothing to print" << endl;
      }
      else{ 
	tree->print(tree->getHead());
      } 
    }
    else if(0==strcmp(input, "quit")){
      running = false;
    }
    else if (0==strcmp(input, "delete")){//delete
      if (tree->getHead() == NULL){
        cout << "There is nothing in the list!" << endl;
      }
      else{
        cout << "What number are you trying to delete?" << endl;
        int number;
        cin >> number;
	cin.ignore();
	Node* deleted = tree->search(number);
	if(deleted){
	  tree->remove(deleted);
	}
        else{
	  cout << "The number you chose is not in the tree." << endl;
	}
      }
    }
    else if (0==strcmp(input, "search")){//search
      if(tree->getHead()==NULL){
	cout << "The list is empty" << endl;
      }
      else {
	cout << "What number do you want to search for?" << endl;
	int number;
	cin >> number;
	cin.ignore();
	if(tree->search(number)){
	  cout << "The number is in the tree" << endl;
	}
	else{
	  cout << "The number is not in the tree." << endl;
	}
      }
    }
  }
}
