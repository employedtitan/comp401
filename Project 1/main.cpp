#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include "WibergA_6.h"

using namespace std;

int main()
{
    string tempcontain;
    string filename;

    int tablesize;
    float a;
    int displayit;

    tablesize == 100; //Size of the table

    a = 17; //Hash function constant


    displayit == 15; //items to be displayed


    filename == 'test.txt' //file to be read in

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
