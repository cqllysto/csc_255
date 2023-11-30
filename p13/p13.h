// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#ifndef __P13_H
#define __P13_H

class huffNode {
    public:
	int key;
	char val;
	huffNode *left, *right;
	huffNode(char val, int key, huffNode *left = NULL, 
	    huffNode *right = NULL);
};

class huffPQ {
    private:
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
};

class encoding {
    public:
	int patCount; // This is the length of a bit encoding
	unsigned int pat; // This is the bit encoding
};

class huffman {
    private:
	static const int FCOUNT = 128;
	huffPQ *pq; // The queue to be used
	int *freqs; // an array of frequencies
	int fileSize; // The character count of the input file
	huffNode *root; // This is sthe root of the Huffman tree

	void clear(huffNode *p); // the private, recursive function of clear
	void getEncodings(huffNode *p, encoding code, encoding *v) const;
	void printPattern(char val, int freq, encoding code) const;
	void printIt(huffNode *p, encoding code) const;
	void dumpTree(huffNode *p, encoding code) const;
    
    public:
	huffman(); // Constructor
	~huffman(); // Destructor

	bool importFile(std::string fname); // reads the input file
	void buildTree();
	void clear();
	encoding *getEncodings() const;
	int getOutFileSizeBits() const;
	int getInFileSizeBytes() const;
	void printIt const;
	void dumpTree() const;
};

#endif
