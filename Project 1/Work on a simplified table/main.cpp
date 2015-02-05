#include<iostream>
#include<stdlib.h>
#include<fstream>
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

    cout<<"Please enter your desired table size: ";
    cin>>tablesize;

    cout<<"Please enter your desired constant for the hash function: ";
    cin>>a;


    cout<<"Please enter how many items you would like displayed: ";
    cin>>displayit;


    cout<<"Please enter the filename: ";
    cin>>filename;

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
