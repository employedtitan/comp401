#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "text.h"

using namespace std;

int main()
{
    string tempcontain;//A varible for the words from the file
    string filename;//A varible to hold the filename

    int tablesize;
    float a;
    int displayit;

    tablesize = 2000;

    a = 0.125;


    displayit = 15;


    filename = "test.txt";

    ifstream fin;

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
}
