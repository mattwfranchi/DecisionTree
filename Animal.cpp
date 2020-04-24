//
// Created by Matt on 4/9/2020.
//

#include "Animal.h"
using namespace std;

// CONSTRUCTOR : Parameterized
Animal::Animal(string n, set<string> & f):name(n),features(f){}

// FUNCTION : getName
string Animal::getName() const { return name; }

// FUNCTION : getFeatures
set<string> Animal::getFeatures() const{ return features; }

// FUNCTION : hasFeature
bool Animal::hasFeature(string s) const
{
    return features.empty() ? false : features.find(s) != features.end();
}

// OPERATOR: overloaded equality
bool operator==(const Animal &one, const Animal &two)
{
    return one.name == two.name;
}

// OPERATOR: overloaded less-than comparison operator
bool operator<(const Animal &one, const Animal &two)
{
    return one.name < two.name;
}