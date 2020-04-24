// Matt Franchi // CPSC 2120 // Spring 2020
// Assignment 3 : Driver file

#include "Animal.h"
#include "DecisionTree.h"

#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    // CHECK : number of arguments is correct (a.out fileName)
    if(argc != 2)
    {
        cout << "Usage: ./a.out file_name" << endl;
        exit(1);
    }

    // create ifstream instance to read from file
    ifstream inFile;
    //
    inFile.open(argv[1]);

    // variables needed to process the set of animals
    string line; // line of text from file
    set<Animal> animals;
    string animalName, feature;
    set<string> features;

    // CHECK : File exists
    if(inFile)
    {
        // get each line while not at eof
        while(getline(inFile, line))
        {
            // create istringstream to process each line
            istringstream iss(line);
            // first string is animal name
            if(iss) iss >> animalName;

            // anything after are features
            while(iss)
            {
              iss >> feature;
              // append feature to set
              features.emplace(feature);
            }

            animals.emplace(Animal(animalName,features));
            // clear features set after each animal is processed
            features.clear();
        }
    }
    else
    {
        cout << "Error: File Not Found. Exiting..." << endl;
        exit(2);
    }

    // create the decision tree from parameterized constructor
    auto *tree = new DecisionTree(animals);
    // dump the tree after it is created
    tree->dump();

    // clear the animals set, as it is no longer needed
    animals.clear();
    // close the file
    inFile.close();
    // delete the tree
    delete tree;

    return 0;
}