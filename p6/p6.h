
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
        int qCount;
        int qCapacity;
        int *values;

        // Methods
        int parent(int index) const;
        int left(int index) const;
        int right(int index) const;
        void printIt(int ind, int count) const; 
        void swap(int *x, int *y); // swaps two integers with each other
        void bubbleUp(int index); // performs the heap bubble-up operation
        void heapify(int index); // performs the heap heapify operation

    public:       
        iPQ(int qCapacity);
        ~iPQ();
        bool enq(int v);
        bool deq(int &v);
        void printIt() const;
        void clear();
        int count() const;

};

#endif