#ifndef HASHTABLE
#define HASHTABLE

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>


using namespace std;

template <class type>
struct hashTablestore
{
    type word;
    type collisions;
    type totalreadin;

};

template <class type> class hashTable
{
public:
    type hashTable(type, type, type);

    ~hashTable();

    type hash(type);

    void robinHood();

    void insert(type);

    void display();



protected:





    float A;//varible for any hash table constant

    int tobedisplayed; //varible fot the amount of objects on the table the user wants to be displayed

    int desiredarraysize; //The size that the user desires for their array

    hashTablestore* table;

    int totalcollisionsz;
};
#endif // HASHTABLE
