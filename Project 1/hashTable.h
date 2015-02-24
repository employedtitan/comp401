#ifndef HASHTABLE
#define HASHTABLE

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>


using namespace std;

struct entry
{

    string word;
    int displacementvalue;
    int totalreadin;


};

class hashTable
{
public:
    hashTable(float, int, int);

    ~hashTable();
    int hash(string);

    void insert(string);

    void display();

    int searchit(string);

    void delentry(string);


protected:





    float A;//varible for any hash table constant

    int tobedisplayed; //varible fot the amount of objects on the table the user wants to be displayed

    int desiredarraysize; //The size that the user desires for their array

    entry* table;

    int totalcollisionsz;
};
#endif // HASHTABLE

