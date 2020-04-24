// Matt Franchi // CPSC 2120 // Spring 2020
// Assignment 3 : Definition File for TNode class

#ifndef A3_TNODE_H
#define A3_TNODE_H


#include "Animal.h"
#include <iostream>

using namespace std;
class TNode {
protected:
    TNode * yes, * no;
    string contents;
    virtual ~TNode ( ){ }
    // print is inline and virtual to allow for customized InternalNode behavior
    virtual void print() { cout << contents << endl; }

    TNode():yes(nullptr),no(nullptr){}
    friend class DecisionTree;

};

class InternalNode : public TNode {

public:
    InternalNode(string &c)
    {
        contents = c;
    }

    // overriden print function for InternalNode
    void print() override { cout << "(" << contents << ")" << endl;}
};

class LeafNode : public TNode {

public:
    LeafNode(string &c)
    {
        contents = c;
    }
};

#endif //A3_TNODE_H
