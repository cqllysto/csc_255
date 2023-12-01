// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#include <iostream>   // gets cin, cout, cerr
#include "p13.h"
using namespace std;

//******************************************************************************
huffman::huffman() {
}

//******************************************************************************
huffman::~huffman() {
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