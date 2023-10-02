// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 6
// Date: 10/02/23

#ifndef __P6_H
#define __P6_H


class iPQ {
    private:
        // Data
        int qCount; // Keeps track of the number of entries in PQ
        int qCapacity; // The maximum number of entries that can be 
        int *values; // The array pointer t

        // Methods
        int parent(int index) const; // Returns the parent of an index
        int left(int index) const; // Returns the left child of an index
        int right(int index) const; // Returns the right child of an index
        void printIt(int ind, int count) const; // Prints the queue by level
        void swap(int *x, int *y); // swaps two integers with each other
        void bubbleUp(int index); // performs the heap bubble-up operation
        void heapify(int index); // performs the heap heapify operation

    public:      
	// Constructor and destructor
        iPQ(int qCapacity = 100);
        ~iPQ();

	// Places a value in the queue
        bool enq(int v);
	// Takes the maximum value out of the queue
        bool deq(int &v);
	// Public function that calls the private printIt
        void printIt() const;
	// clears the queue
        void clear();
	// Returns the number of entries in the queue
        int count() const;
};

#endif
