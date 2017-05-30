#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void addVertex(char* vertex[20], int &vertexCount, char vertexInput[20]);
void printGraph(char* vertex[20], float adTable[20][20]);
void addEdge(char* vertex[20], float adTable[20][20], float weight, char firstVertex[20], char secondVertex[20]);
void removeEdge(float adTable[20][20], char firstVertex[20], char secondVertex[20], char* vertex[20]);
void removeVertex(char* vertex[20], char removedVertex[20], float adTable[20][20]);
int lookupVertex(char* vertex[20], char vertexInput[20]);

int main(){

  int vertexCount = 0;
  int inLoop = 1;
  char input[20];
  char vertexInput[20];
  float table[20][20];
  char* vertex[20];
  char vertex1[20];
  char vertex2[20];
  float weight = 0;
  
  for(int i = 0; i < 20; i++){
    vertex[i] = NULL;
  }
  
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      table[i][j] = 0;
    }
  }
 

  //Menu
  while(inLoop == 1){
    cout << "Enter: addvertex, addedge, removevertex, removeedge, findpath, print, exit" << endl;
    cin >> input;
    cin.ignore();
    
    if(strcmp(input, (char*)"addvertex") == 0){
      cout << "Enter vertex label for graph" << endl;
      cin.getline(vertexInput, 20);      
      //cout << (char*) vertexInput << endl;
      addVertex(vertex, vertexCount, vertexInput);
    }

    if(strcmp(input, (char*)"addedge") == 0){
      cout << "Enter the label of the first vertex" << endl;
      cin >> vertex1;
      cout << "Enter the label of the second vertex" << endl;
      cin >> vertex2;
      cout << "Enter weight of edge" << endl;
      cin >> weight;
      addEdge(vertex, table, weight, vertex1, vertex2);
      /*
      int position1 = lookupVertex(vertex, vertex1);
      int position2 = lookupVertex(vertex, vertex2);
      if (position1>-1 && position2 >-1) {
	table[position1][position2] = weight;
	cout << "Edge added with weight " << table[position1][position2] << endl; 
      }
      else {
        cout << "Not valid vertex." << endl;
      }
      */
	  
    }

    if(strcmp(input, (char*)"removevertex") == 0){
      cout << "Enter the label of the vertex" << endl;
      cin >> vertex1;
      removeVertex(vertex, vertex1, table);
    }

    if(strcmp(input, (char*)"removeedge") == 0){
      cout << "Enter the label of the first vertex" << endl;
      cin >> vertex1;
      cout << "Enter the label of the second vertex" << endl;
      cin >> vertex2;
      removeEdge(table, vertex1, vertex2, vertex);
      
    }

    if(strcmp(input, (char*)"findpath") == 0){

    }

    if(strcmp(input, (char*)"print") == 0){
      printGraph(vertex, table);
    }
    if(strcmp(input, (char*)"exit") == 0){
      inLoop = 0;
      cout << "Exited" << endl;
    }
    
  }
}

//Add a vertex
void addVertex(char* vertex[20], int &vertexCount, char vertexInput[20]){
  int check = 0;
  int length = strlen(vertexInput);

  //Check for duplicate vertex
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL && strcmp((char*)vertex[i], (char*)vertexInput) == 0){
      check++;
    }
  }

  //There is a duplicate
  if (check > 0){
    cout << "Vertex label has already been entered" << endl;
    return;
  }

  //Add vertex label
  if (check ==0) {
    vertex[vertexCount]= new char[length + 1];
    strcpy(vertex[vertexCount], vertexInput);
    vertexCount ++;
    cout << "Vertex " << vertexInput << " is added. " << endl << endl;
  }
  
}

//Print 
void printGraph(char* vertex[20], float adTable[20][20]){
  cout << "Vertex list: ";

  //Print vertex labels
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL){
      cout << vertex[i] << ", ";
    }
  }
  cout << endl;

  //Print top vertices

  cout << "       ";
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL){
      printf("%7s ", vertex[i]);
    }
  }
  cout << endl;
  //Print edges
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL){
      printf("%7s ", vertex[i]);
      for(int j = 0; j < 20; j++){
	if(vertex[j] != NULL){
	  printf("%5f ", adTable[i][j]);
	}
      }
      cout << endl;
    }
  }
}

// lookup vertex label for the array position
int lookupVertex(char* vertex[20], char vertexInput[20]) {
  
  int position = -1;
  for (int i = 0; i < 20; i++) {
    if (vertex[i] != NULL && strcmp(vertex[i], vertexInput) ==0) {
      position =i;
      return position;
    }
  }

  return position;
}


//Function to add edge using two inputed vertex and weight
void addEdge(char* vertex[20], float adTable[20][20], float weight, char firstVertex[20], char secondVertex[20]){
  
  int position1 = -1;
  int position2 = -1;

  //Find first index of the vertex
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL && strcmp(vertex[i], firstVertex) == 0){
      position1 = i;
      break;
    }
  }

  //Find second index of the vertex
   for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL && strcmp(vertex[i], secondVertex) == 0){
      position2 = i;
      break;
    }
  }

   //Make sure vertex names are entered correctly
   if(position1 > -1 && position2 > -1){
     adTable[position1][position2] = weight;
     cout << adTable[position1][position2] << endl;
   }
   
   else{
     cout << "Not valid vertex" << endl;
   }
}


//Remove edge between two vertices
void removeEdge(float adTable[20][20], char firstVertex[20], char secondVertex[20], char* vertex[20]){
  int position1 = -1;
  int position2 = -1;
   //Find first index of the vertex
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL && strcmp(vertex[i], firstVertex) == 0){
      position1 = i;
      break;
    }
  }

  //Find second index of the vertex
   for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL && strcmp(vertex[i], secondVertex) == 0){
      position2 = i;
      break;
    }
  }

   //Clear the edge between the two vertices
   if(position1 > -1 && position2 > -1){
     cout << " dassda" << endl;
     adTable[position1][position2] = 0;
   }

   else{
     cout << "Not valid vertex" << endl;
   }

}

//Remove vertex and all edges to that vertex
void removeVertex(char* vertex[20], char removedVertex[20], float adTable[20][20]){
  int check = 0;
  int position = -1;
  
  //Find the vertex to be removed; find position of removed vertex
  for(int i = 0; i < 20; i++){
    if(vertex[i] != NULL && strcmp((char*)vertex[i], (char*)removedVertex) == 0){
      position = i;
      check++;
      break;
    }
  }

  //The label is there, clear all edges to the removed vertex and remove vertex
  if (check > 0){
    delete vertex[position];
    vertex[position] = NULL;
    for(int i = 0; i < 20; i++){
      adTable[i][position] = 0;
    }
    
    for(int i = 0; i < 20; i++){
      adTable[position][i] = 0;
    }
    cout << "edges to the vertex have been cleared" << endl;
  }

  //Vertex not found
  if(check == 0) {
    cout << "The vertex was not found" << endl;
    return;
  }

}
