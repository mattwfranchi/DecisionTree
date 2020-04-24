//
// Created by Matt on 4/9/2020.
//

#ifndef A3_ANIMAL_H
#define A3_ANIMAL_H

#include <string>
#include <set>
using namespace std;

class Animal
{
private:
    const string name;
    const set<string> features;
public:

    Animal(string n, set<string> & f);
    string getName() const ;
    set<string> getFeatures() const ;
    bool hasFeature(string s) const;

    // both overloaded operators are friend functions
    friend bool operator== (const Animal &one, const Animal &two);

    friend bool operator < (const Animal &one, const Animal &two);
};


#endif //A3_ANIMAL_H
