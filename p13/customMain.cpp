#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "p13.h"

using namespace std;

//******************************************************************************

int main(int argc, char *argv[]) {
    int bitCount;
    int byteCount;

    if (argc >= 2) {
	huffman *myHuff = new huffman();

	string s(argv[1]);
	myHuff->importFile(s);
	myHuff->buildTree();
	//myHuff->printIt();

    } else {
	cerr << "Usage: " << argv[0] << " filename" << endl;
    }
}

//******************************************************************************
