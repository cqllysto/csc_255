// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9
// Date: 11/01/23

#ifndef __P9_H
#define __P9_H
#include "p8.h"

class Graph {
    private:
        int labelToVid(int label) const;
        int *a;
        intList *labels;
        int n;
        int vCount;
        int eCount;
        bool directed;

    public:
        Graph(int n = 100, bool directed = true);
        ~Graph();
        bool createV(int label);
        bool addEdge(int uLabel, int vLabel, int weight);
        bool deleteEdge(int uLabel, int vLabel);
        void clear();
        bool isEdge(int uLabel, int vLabel) const;
        bool isV(int label) const;
        int inDegree(int label) const;
        int outDegree(int label) const;
        int sizeV() const;
        int sizeUsedV() const;
        int sizeE() const;
        void printIt() const;
};


#endif