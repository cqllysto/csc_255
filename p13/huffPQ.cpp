// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#include <iostream>   // gets cin, cout, cerr
#include "p13.h"

using namespace std;


//******************************************************************************
// Andrew Chapui

huffPQ::huffPQ(int n) {

}


huffNode **entries; // this is for the list of huffNode pointers
int pqSize; // The capacity of the queue, which is set at construction
int qCount; // The number of items in the queue

int parent(int index) const;
int left(int index) const;
int right(int index) const;

void swap(huffNode *&x, huffNode *&y); // Traditional swap
void bubbleUp(int index); // Moves the huffNode up the heap if needed
void heapify(int i); // Moves the huffNose down the heap if needed
public:
huffPQ(int n); // Constructor
~huffPQ(); // Destructor

bool enq(huffNode *v); 
bool deq(huffNode *&v);
void clear(); // Causes the PQ to be cleared
int count () const; // Returns the number of items in the PQ