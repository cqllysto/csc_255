// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#ifndef __P13_H
#define __P13_H

#include <string>

class huffNode {
    public:
        // These are the constructor and destructor of the class
        // using 0 instead of NULL to avoid forcing #include <stdio.h> in the header file
        huffNode(char val, int key, huffNode *left = 0, huffNode *right = 0);
        ~huffNode();
        
        int key;
        char val;
        huffNode *left;
        huffNode *right;
};


class huffPQ {
    private:
        huffNode **entries;
        int pqSize;
        int qCount;
        int parent(int index);
        int left(int index);
        int right(int index);
        void swap (huffNode *&x, huffNode *&y);
        void bubbleUp(int index);
        void heapify(int index);

    public:
        // These are the constructor and destructor of the class
        // using 0 instead of NULL to avoid forcing #include <stdio.h> in the header file
        huffPQ(int n);
        ~huffPQ();
        
        bool enq(huffNode *v ); // enq and deq, note the type of the parameter
        bool deq(huffNode * &v); // both return true if successful; otherwise false.
        void clear(); // causes the PQ to be cleared.
        int count() const; // returns the number of items in the PQ
};

class encoding {
    public:
        int patCount;
        unsigned int pat;
};


class huffman {
    private:
        static const int fCount = 128;
        huffPQ *pq;
        int *freq;
        int fileSize; // this is where the character count of the input file will be remembered.
        huffNode *root; // this is the root of the Huffman tree, once it is fully built.
        void clear(huffNode *p); // the private, recursive version of clear; causes the given node and all its childrent to be deleted.
        void getEncodings(huffNode *p, encoding code, encoding *rv) const; // this is the private version of the recursive encoding traversal. This will fill the entries of the rv array that gets passed in. At each leaf, it saves the encoding in rv, indexed by the val of the huffNode.
        void printPattern(char val, int freq, encoding code) const; // this is a helper function for printIt() and dumpTree() . It prints the val and the %frequency for that val, and then the binary encoding. See the p13correctOutput.txt file for the proper format.
        void printIt(huffNode *p, encoding code) const; // this is the private recursive extension of the Huffman tree traversal that results in the printing of each leaf via the printPattern() function.
        void dumpTree(huffNode *p, encoding code) const; // this is a traditional in=order tree traversal that prints every node, including interior nodes. The printing is done by printPattern(). This function is good for debugging.

    private:
        huffman(); // the constructor; it will cause, among other things, the PQ to be created with FCOUNT capacity.
        ~huffman(); // the destructor; lots of details to be managed, but it manage all that in two lines.
        bool importFile(std::string fname); // this reads the input file, character by character. For each character it keeps count in freqs[], which is indexed by the character just read in. It also keeps track of the input file’s size.
        void buildTree(); // This is used after the input file has been read in and processed. For each non-zero entry in freqs[], creates a hffNode for that character and enques it into the pq.
        void clear(); // calls the private version passing the root of the tree.
        encoding *getEncodings() const; // creates the array rv[] with FCOUNT entries and then calls the private version to do the traversal and get all the encodings.
        int getOutFileSizeBits() const; // These two functions return what their name says they would return.
        int getInFileSizeBytes() const;
        void printIt() const; // these are the public starters of the recursive traversals for printing the Huffman tree.
        void dumpTree() const;
};



#endif