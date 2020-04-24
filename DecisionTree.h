// Matt Franchi // CPSC 2120 // Spring 2020
// Assignment 3 : Declaration file for DecisionTree class

#ifndef A3_DECISIONTREE_H
#define A3_DECISIONTREE_H


#include "Animal.h"
#include "TNode.h"
#include <map>
#include <algorithm>
#include <iostream>

class DecisionTree
{
private:
    TNode *root;

public:

    DecisionTree(set<Animal> & data ) ;
    ~DecisionTree( ) ;
    void deleteTree(TNode* &root);
    TNode * createTreeFor( set<Animal> & data ) ;
    string getSplit( set<Animal> & data ) ;
    void dump() ;
    void preOrderPrint(TNode* &v, int depth) ;
};


#endif //A3_DECISIONTREE_H
