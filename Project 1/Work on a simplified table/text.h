#ifndef HASHTABLE
#define HASHTABLE

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>


using namespace std;

class entry
{
public:

    entry(string, int, int);

    ~entry();

    addcon();

    adddou();

    swapout();


};

class hashTable
{
public:
    hashTable(float, int, int);

    ~hashTable();
    int hash(string);

    void insert(string);

    void display();



protected:





    float A;//varible for any hash table constant

    int tobedisplayed; //varible fot the amount of objects on the table the user wants to be displayed

    int desiredarraysize; //The size that the user desires for their array

    hashTablestore* table;

    int totalcollisionsz;
};
#endif // HASHTABLE
