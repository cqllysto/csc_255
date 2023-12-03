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
huffman::~huffman() {
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

void huffman::printPattern(char val, int freq, encoding code) const {
    cout << val << "(" << (100.0*(float)freq/(float)fileSize) << "%) ";
    for (int i = 0; i < code.patCount; i++) {
	    cout << (int)(((code.pat >> code.patCount - 1 - i)) & 1);
    }
    cout << endl;
}

//******************************************************************************

void huffman::printIt() const {
    encoding code;
    code.pat = 0;
    code.patCount = 0;
    printIt(root, code);
}

//******************************************************************************

void huffman::dumpTree() const {
    encoding code;
    code.pat = 0;
    code.patCount = 0;
    dumpTree(root, code);
}

//******************************************************************************

encoding *huffman::getEncodings() const {
    encoding *rv = new encoding[FCOUNT];
    encoding code;
    code.pat = 0;
    code.patCount = 0;
    getEncodings(root, code, rv);
    return rv;
}

//******************************************************************************

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

int huffman::getInFileSizeBytes() const {
    return fileSize;
}


//******************************************************************************
// Aidan Wright

bool huffman::importFile(string fname) {
    bool rc = false;
    ifstream file(fname);
        
    if (!file.is_open()) {
        rc = false;
    } else {
        rc = true;
        char a = 0;
        while (file.get(a)) {
            // Update character frequency
            freqs[a]++;
            // Update file size
            fileSize++;
        }
        file.close();
    }
    
    // Testing this function
    // for (int i = 0; i < FCOUNT; ++i) {
    //     cout << freqs[i] << endl;
    // }
    // cout << fileSize;

    return rc;
} // reads the input file

//******************************************************************************
// Aidan Wright

void huffman::buildTree(){
    for (int i = 0; i < FCOUNT; i++) {
        if (freqs[i] != 0) {
            char c = static_cast<char>(i);
            huffNode *a = new huffNode(c,freqs[i]);
            pq->enq(a);
        }
    }

    pq->printIt2();

    while (pq->count() > 1) {
        huffNode *leftChild, *rightChild;
        if (pq->deq(leftChild) && pq->deq(rightChild)) {
            huffNode *parent = new huffNode('\0', 
                leftChild->key + rightChild->key, leftChild, rightChild);
            pq->enq(parent);
        }
    }

    // The last remaining node in the queue is the root of the Huffman tree
    pq->deq(root);
    pq->printIt2();

}

//******************************************************************************
// Aidan Wright

void huffman::clear(huffNode *p){
    if (p) {
        clear(p->left);
        clear(p->right);
        delete p;
    }
} // the private, recursive function of clear

//******************************************************************************
// Aidan Wright
void huffman::getEncodings(huffNode *p, encoding code, encoding *v) const{
    if (p) {
        if (p->left == NULL && p->right == NULL) {
            // Leaf node, save the encoding in rv
            v[static_cast<unsigned char>(p->val)] = code;
        } else {
            // Traverse left with '0'
            encoding left = code;
            left.pat = (left.pat <<= 1);
            left.patCount++;
            getEncodings(p->left, left, v);

            // Traverse right with '1'
            encoding right = code;
            right.pat <<= 1;
            right.pat |= 1;
            right.patCount++;
            getEncodings(p->right, right, v);
        }
    }
}


//******************************************************************************
// Aidan Wright
void huffman::printIt(huffNode *p, encoding code) const{
    if (p) {
        if (p->left == NULL && p->right == NULL) {
            // Leaf node, save the encoding in rv
            printPattern(p->val, p->key, code);
        } else {
            // Traverse left with '0'
            encoding left = code;
            left.pat = (left.pat << 1);
            left.patCount++;
            printIt(p->left, left);

            // Traverse right with '1'
            encoding right = code;
            right.pat = (right.pat << 1) | 1;
            right.patCount++;
            printIt(p->right, right);
        }
    }
}


//******************************************************************************
// Aidan Wright
void huffman::dumpTree(huffNode *p, encoding code) const{
    if (p) {
        dumpTree(p->left, code);
        printPattern(p->val, p->key, code);
        dumpTree(p->right, code);
    }
}