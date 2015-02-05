//WibergA_6
//
//The purpose of this program is to create a hash table to store a read in text file and also to experiment with varible sizes for the table and
//Knuth's constant
//
//Input: Table size, a float value for the constant for the hashing formula, how many items to be displayed, and the file name to be read in
//
//Output: A formated table detailing the index, word, amount of times occured in the file, and number of collisions which displays
//however many objects the user wanted to see
#ifndef HASHTABLE
#define HASHTABLE

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>


using namespace std;

struct hashTablestore
{
    string word;
    int collisions;
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



protected:





    float A;//varible for any hash table constant

    int tobedisplayed; //varible fot the amount of objects on the table the user wants to be displayed

    int desiredarraysize; //The size that the user desires for their array

    hashTablestore* table;

    int totalcollisionsz;
};
#endif // HASHTABLE
