#include <iostream>
#include <fstream>
#include "Node.h"
#include "RedBlackTree.h"

using namespace std;

void toLower(char* a){ //converts words to lower case
  while(*a){
    *a = tolower(*a);
    a++;
  }
}
void configureInput(ifstream &stream, bool &isFile){ 
  //Asks weather to take in input from text or from file
  //outputs through ifstream parameter

  char input[128];
  isFile = false;

  cout << "Read from File or Input text?" << endl;
  cin.getline(input,128);
  toLower(input);

  if(input[0] == 'f'){
    cout << "What file?" << endl;
    cin.getline(input,128);
    stream.open(input);
    if(stream.is_open()){
      isFile = true;
    }
    else{
      cout << "Could not open file" << endl;
      cout << "Enter by command line" << endl;
    }
  }
  else{
    cout << "Enter by command line" << endl;
  }
}
void addNumbers(istream &from, RedBlackTree* tree){
  //goes through a stream and adds them to the heap
  int newInput;
  from >> newInput;
  tree->add(tree->getHead(),newInput);
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


int main(){
  //main program loop
  RedBlackTree* tree = new RedBlackTree();
  char input[128];
  bool running = true;


  while(running){

    cin.getline(input, 128);
    toLower(input);
    
    if(input[0] == 'a') {
      ifstream stream;
      bool isFile;
      configureInput(stream, isFile);
      addNumbers(isFile ? stream : cin, tree);      
      if(isFile) stream.close();
      cin.ignore();
      
    }
    else if(input[0] == 'd'){
      cout << "Deletion has not been implemented yet" << endl;
    }
    else if(input[0] == 'p'){
      if (tree->getHead()){
	tree->print(tree->getHead());
      }
      else cout << "Empty Tree" << endl;
    } 
    else if(input[0] == 'q'){
      running = false;
    }
    else{
      cout << "I don't understand" << endl;
      cout << "The possible commands are:\nAdd\nDelete\nPrint\nQuit" << endl;
    }
  }
}
