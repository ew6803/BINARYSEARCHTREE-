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

void add(Node* head, int wadd);
void print(Node* head, int format);
Node* deleteN(Node* head, int wadd);
void search(Node* head, bool rsearch, int wsearch); 

int main() {
  char* input = new char[1000];
  cout << "File, Console? Take your Pick, you have a variety of options \n";
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
      add(head, array[i]); 
    }
    //Further Command Line
    while (running == true) {
      cout << "\nYou can do stuff now, you can ADD, DELETE, PRINT, SEARCH, EXIT \n";
      char* getInput = new char[50];
      cin.getline(getInput, 50);
      int wadd = 0;
      int wsearch = 0;
      bool rsearch = false; 
      if (strcmp(getInput, "ADD") == 0) {
	cout << "Enter number you would like to add \n";
	cin >> wadd;
	cin.get();
	add(head, wadd); 
	}
      else if (strcmp(getInput, "DELETE") == 0) {
	//Function!
	
	}
      else if (strcmp(getInput, "PRINT") == 0) {
        //Function!
	if (head-> getData() == NULL) {
	  cout << "Nothing to Print \n";
	}
	else {
	  print(head, 0);
	}
      }
      else if (strcmp(getInput, "SEARCH") == 0) {
	cout << "What number would you like to search for? \n";
	cin >> wsearch;
	cin.ignore(9999, '\n');
	search(head, rsearch, wsearch);
      }
      else if (strcmp(getInput, "EXIT") == 0) {
	running = false; 
      }
    }


  return 0; 
}

void add(Node* head, int wadd) {
  if (head -> getData() == NULL) {
    head -> setData(wadd);
    return; 
  }
  else if (head -> getData() < wadd) {
    if (head -> getRight() != NULL) {
      Node* temp = head -> getRight();
      add(temp, wadd); 
    }
    else {
      Node* temp = new Node();
      temp -> setData(wadd);
      head -> setRight(temp);
      return; 
    }
  }
  else if (head -> getData() > wadd) {
    if (head -> getLeft() != NULL) {
      Node* temp = head -> getLeft();
      add(temp, wadd); 
    }
    else {
      Node* temp = new Node();
      temp -> setData(wadd);
      head -> setLeft(temp);
      return; 
    }
  }
  return; 
}

void print(Node* head, int format) {
  if (head == NULL) 
    return;
  format = format + 3;
  print(head -> getRight(), format);
  cout << '\n';
  for (int i = 3; i < format; i++)
    cout << " ";
    cout << head -> getData();
    print(head -> getLeft(), format); 
}

Node* deleteN(Node* head, int wadd) {
  //This seems hard, i will leave it for now. 
}

void search(Node* head, bool rsearch, int wsearch) { 
  Node* filler = NULL;
  int tracker = 0;
  if (head == NULL) {
    cout << "Nothing";
    return; 
  }
  if (head != NULL) {
    if (head -> getData() > wsearch) {
      search(head -> getLeft(), rsearch, wsearch);
    }
    else if (head -> getData() < wsearch) {
      search(head -> getRight(), rsearch, wsearch);
    }
   else if (head -> getData() == wsearch) {
      cout << "Match found";
      rsearch = true;
      tracker = 1; 
      return; 
      }
  }
    
}
