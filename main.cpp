// This program is a binary search tree, it does something. Good Comment.
// Ethan Wang
// 3/9/20

#include "Node.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
int main() {
  char* input = new char[1000];
  cout << "File, Console? Take your Pick, you have a variety of options";
  cin.getline(input, 1000);
  int count = 0;
  bool running = true; 
  int* array = new int[1000];
  if(strcmp(input, "CONSOLE") == 0) {
      cout << "Enter numbers with spaces to seperate \n";
      char* input2 = new char[1000];
      cin.getline(input2, 1000);
      char* token = strtok(input2, " ");
      while (token != NULL) {
	array[count] = atoi(token);
        token = strtok(NULL, " ");
	count++;
      }
    }
    if (strcmp(input, "FILE") == 0) {
      cout << "Enter File Name: /n";
      char* fileName = new char[1000];
      cin.getline(fileName, 1000);
      ifstream inFile;
      inFile.open(fileName);
      int count2 = 0;
      while (inFile >> count2) {
	array[count] = count2;
	count++; 
      }
    }
    Node* head = new Node();
    for (int i = 0; i < count; i++) {
      //addnode each time
    }
    //Further Command Line
    while (running == true) {
      cout << "You can do stuff now, you can ADD, DELETE, PRINT, EXIT /n";
      char* getInput = new char[50];
      cin.getline(getInput, 50);
      int wadd = 0;
      if (strcmp(getInput, "ADD") == 0) {
	//Function!
	}
      else if (strcmp(getInput, "DELETE") == 0) {
	//Function!
	}
      else if (strcmp(getInput, "PRINT") == 0) {
        //Function!
      }
      else if (strcmp(getInput, "EXIT") == 0) {
	running = false; 
      }
      else {
        cout << "Valid Input Plz \n"; 
      }
    }


  return 0; 
}
