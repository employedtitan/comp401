#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include "Hashtable.h"

using namespace std;

int main()
{
    string tempcontain;//A varible for the words from the file
    string filename;//A varible to hold the filename

    int tablesize;
    float a;
    int displayit;

    tablesize = 100;

    a = 0.618;


    displayit = 20;


    filename = "collisiontest.txt";

    ifstream fin;
    int please;
    fin.open(filename.c_str());

    if(fin.fail())
    {
        cout<<"FATAL ERROR! "<<filename<<" did not open."<<endl;
        exit(-1);
    }



    hashTable T(a, displayit, tablesize);



    while(fin)
    {
        fin>>tempcontain;

        T.insert(tempcontain);


    }


    T.display();
    T.delentry("the");
    T.searchit("the");
}

