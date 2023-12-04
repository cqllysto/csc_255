// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#include <iostream>   // gets cin, cout, cerr
#include <fstream>
#include <string>
#include "p13.h"
using namespace std;

//******************************************************************************
// Instructor Provided

huffNode::huffNode(char val, int key, huffNode *left, huffNode *right) {
    this->val = val;
    this->key = key;
    this->left = left;
    this->right = right;
}

//******************************************************************************
// Aidan Wright

huffman::huffman() {
    pq = new huffPQ(FCOUNT);
    freqs = new int [FCOUNT];
    for (int i = 0; i < FCOUNT; ++i) {
        freqs[i] = 0;
    }
    fileSize = 0;
    root = NULL;
}

//******************************************************************************
// Andrew Chapuis

huffman::~huffman() {
    // Clear the huffTree then delete the pq and the freq array
    clear(root);

    if (pq != NULL) {
        delete pq;
        pq = NULL;
    }

    if (freqs != NULL) {
        delete[] freqs;
        freqs = NULL;
    }
}


//******************************************************************************
// Instructor provided

void huffman::clear() {
    // traverse the tree, deleting all the nodes
    // and clear the counts and empty the pq
    clear(root);
    fileSize = 0;
    root = NULL;

    for (int i = 0; i < FCOUNT; i++) {
        freqs[i] = 0;
    }

    pq->clear();
}

//******************************************************************************
// Instructor Provided

void huffman::printPattern(char val, int freq, encoding code) const {
    cout << val << "(" << (100.0*(float)freq/(float)fileSize) << "%) ";
    for (int i = 0; i < code.patCount; i++) {
        cout << (int)(((code.pat >> code.patCount - 1 - i)) & 1);
    }
    cout << endl;
}

//******************************************************************************
// Instructor provided

void huffman::printIt() const {
    encoding code;
    code.pat = 0;
    code.patCount = 0;
    printIt(root, code);
}

//******************************************************************************
// Instructor provided

void huffman::dumpTree() const {
    encoding code;
    code.pat = 0;
    code.patCount = 0;
    dumpTree(root, code);
}

//******************************************************************************
// Instructor Provided

encoding *huffman::getEncodings() const {
    encoding *rv = new encoding[FCOUNT];
    encoding code;
    code.pat = 0;
    code.patCount = 0;
    getEncodings(root, code, rv);
    return rv;
}

//******************************************************************************
// Instructor Provided

int huffman::getOutFileSizeBits() const {
    int rc = 0;
    encoding *encodings = getEncodings();

    for (int i = 0; i < FCOUNT; i ++) {
        rc += encodings[i].patCount * freqs[i];
    }

    delete [] encodings;

    return rc;
}


//******************************************************************************
// Instructor Provided

int huffman::getInFileSizeBytes() const {
    return fileSize;
}


//******************************************************************************
// Aidan Wright

// Reads a file and updates the freq array with their frequency
bool huffman::importFile(string fname) {
    bool rc = false;
    ifstream file(fname);

    if (file.is_open()) {
        rc = true;
        char a = 0;
        // Go through the file and increment freq and fileSize
        while (file.get(a)) {
            // Update character frequency
            freqs[a]++;
            // Update file size
            fileSize++;
        }
        file.close();
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

// Builds the huffNode tree that will be enqueued in the huffPQ
void huffman::buildTree(){
    for (int i = 0; i < FCOUNT; i++) {
        // Only the chars that occur at least once will be used to create 
        // huffNodes
        if (freqs[i] != 0) {
            huffNode *a = new huffNode(i,freqs[i]);
            // After a huffnode has been created, it will be enqueued
            pq->enq(a);
        }
    }
    // Allocate two huffNode pointers that will be used in the loop that 
    // will enqueue huffNodes until the final huffTree has been made
    huffNode *left, *right;
    while (pq->count() > 1) {
        if (pq->deq(left) && pq->deq(right)) {
            // Create a new huffNode using the left and rght
            huffNode *parent = new 
                huffNode('@', left->key + right->key, left, right);
            // Enqueue the new huffNode back into the PQ
            pq->enq(parent);
        }
    }

    // The last remaining node in the queue is the root of the Huffman tree
    pq->deq(root);
}

//******************************************************************************
// Andrew Chapuis

// Private version of the clear function that will clear the children before
// clearing the parent
void huffman::clear(huffNode *p){
    if (p) {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

//******************************************************************************
// Aidan Wright

void huffman::getEncodings(huffNode *p, encoding code, encoding *v) const{
    if (p) {
        if (p->left == NULL && p->right == NULL) {
            // Leaf node, save the encoding in rv
            v[static_cast<unsigned char>(p->val)] = code;
        } else {
            // Traverse left with '0' by creating a new encoding object
            // and updating its pat by a shift and incrementing the patCount
            encoding left = code;
            left.pat <<= 1;
            left.patCount++;
            getEncodings(p->left, left, v);

            // Traverse right with '1' by creating a new encoding object
            // and updating its pat by a shift and an or then increment 
            // the patCount
            encoding right = code;
            right.pat = (right.pat << 1) | 1;
            right.patCount++;
            getEncodings(p->right, right, v);
        }
    }
}


//******************************************************************************
// Andrew Chapuis

// Private version of printIt() that will print the code of each leaf in the 
// tree
void huffman::printIt(huffNode *p, encoding code) const{
    if (p) {
        if (p->left == NULL && p->right == NULL) {
            // Leaf node, save the encoding in rv
            printPattern(p->val, p->key, code);
        } else {
            // Traverse left with '0' by creating a new encoding object
            // and updating its pat by a shift and incrementing the patCount
            encoding left = code;
            left.pat <<= 1;
            left.patCount++;
            printIt(p->left, left);

            // Traverse right with '1' by creating a new encoding object
            // and updating its pat by a shift and an or then increment 
            // the patCount
            encoding right = code;
            right.pat = (right.pat << 1) | 1;
            right.patCount++;
            printIt(p->right, right);
        }
    }
}


//******************************************************************************
// Andrew Chapuis

// Prints every node in the tree in order
void huffman::dumpTree(huffNode *p, encoding code) const{
    if (p) {
        // Since it prints in order, it will go to the left child, print, then
        // go to the right child
        dumpTree(p->left, code);
        printPattern(p->val, p->key, code);
        dumpTree(p->right, code);
    }
}
