// Matt Franchi // CPSC 2120 // Spring 2020
// Assignment 3 - DecisionTree class implementation file

#include "DecisionTree.h"

using namespace std;

// CONSTRUCTOR: Parameterized
DecisionTree::DecisionTree(set<Animal> & data )
{
    string splitFeature = getSplit(data);
    root = createTreeFor(data);
}

// DESTRUCTOR
DecisionTree::~DecisionTree( )
{
    deleteTree(root);
}

// FUNCTION: deleteTree
// helper method for class destructor
// recursively deletes tree - postorder
void DecisionTree::deleteTree(TNode* &node)
{
    if(!node) return;
    deleteTree(node->yes);
    deleteTree(node->no);
    delete(node);
}

// FUNCTION: createTreeFor
// creates subtrees based off of data input
TNode * DecisionTree::createTreeFor( set<Animal> & data )
{
    // CASE I : Leaf Node
    if(data.size() == 1) {
        string animal = data.begin()->getName();
        return new LeafNode(animal);
    }
    // CASE II: Internal Node
    else
    {
        // Initialize variables
        string splitFeature = getSplit(data);
        TNode *node = new InternalNode(splitFeature);
        set<Animal> haveSplitFeature, notSplitFeature;

        // iterate through each animal, divide into two sets based off of feature
        for(auto animal : data)
        {
            // CASE I : animal has the split feature
            if(animal.hasFeature(splitFeature))
            {
                set<string> features = animal.getFeatures();
                features.erase(splitFeature);
                string name = animal.getName();
                auto animalAdj = Animal(name,features);
                haveSplitFeature.emplace(animalAdj);
            }
            // CASE II: animal does NOT have the split feature
            else { notSplitFeature.emplace(animal); }
        }
        // only process child node if the sub-data is not empty
        if(!haveSplitFeature.empty()) node->yes = createTreeFor(haveSplitFeature);
        if(!notSplitFeature.empty()) node->no = createTreeFor(notSplitFeature);

        // return the complete node
        return node;
    }
}

// FUNCTION : getSplit
string DecisionTree::getSplit( set<Animal> & data )
{
    // return flag value if the given data was empty
    if(data.empty())
    {
        return "n/a";
    }
    // create a map to store the weighted features
    // key = feature name, val = # times found
    map<string,int> weightedFeatures;

    // iterate through each animal in data
    for(auto animal : data)
    {
        // iterate through each feature
        for(auto feature : animal.getFeatures())
        {
            // CASE I : feature is not in weightedFeatures
            if(weightedFeatures.find(feature) == weightedFeatures.end())
            {
                weightedFeatures.emplace(feature,1);
            }
            // CASE II: feature is already in weightedFeatures
            else
            {
                weightedFeatures.find(feature)->second ++;
            }
        }
    }

    // lambda expression combined with templated max_element to get maximum value from map
    // incorporates STL pair that matches type of map - <string, int>
    auto x = max_element(weightedFeatures.begin(),weightedFeatures.end(),
        [](const pair<string, int>&p1, const pair<string, int>&p2) {
            return p1.second < p2.second; });

    // return the name of the highest-occuring feature
    return x->first;
}

// FUNCTION: dump - uses preOrderPrint
void DecisionTree::dump()
{
    // set depth at 0 to start
    // depth indicates how much to tab
    int depth = 0;
    preOrderPrint(root,depth);
}

// FUNCTION: preOrderPrint
void DecisionTree::preOrderPrint(TNode* &v, int depth)
{
    // CASE I : node is null
    if (!v) { return; }
    // CASE I : node is valid
    else
    {
        // print depth tabs
        for(int n = 0; n < depth; n ++){ cout << "..."; }
        // print the contents of the node, then newline
        v->print();
    }
    // recursive preorder traversal
    // increment depth once per function call
    preOrderPrint(v->yes,++depth);
    preOrderPrint(v->no,depth);
}