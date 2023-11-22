// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#include <iostream>   // gets cin, cout, cerr
#include "p13.h"

//******************************************************************************

huffNode::huffNode(char val, int key, huffNode *left, huffNode *right) {
    // Instructor provided
    this->val = val;
    this->key = key;
    this->left = left;
    this->right = right;
}
