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
    huffPQ *pq = new huffPQ(FCOUNT);
    freqs = new int [FCOUNT];
    for (int i = 0; i < FCOUNT; ++i) {
        freqs[i] = 0;
    }
    fileSize = 0;
    root = NULL;
}

//******************************************************************************
huffman::~huffman() {
    delete pq;
    delete freqs;
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
            huffNode *a = new huffNode(i,freqs[i]);
            pq->enq(a);
        }
    }

}

//******************************************************************************
// Aidan Wright

void huffman::clear(huffNode *p){} // the private, recursive function of clear

//******************************************************************************
// Aidan Wright
void huffman::getEncodings(huffNode *p, encoding code, encoding *v) const{
    
}


//******************************************************************************
// Aidan Wright
void huffman::printIt(huffNode *p, encoding code) const{}


//******************************************************************************
// Aidan Wright
void huffman::dumpTree(huffNode *p, encoding code) const{}