
#include "hashTable.h"




template <class type>
hashTable::hashTable(float a, int displayit, int sizeIwant)
{
    //Method to initilize the hashTable object

    this->A = a;
    this->tobedisplayed = displayit;
    this->desiredarraysize = sizeIwant;
    this->totalcollisionsz = 0;

    if(tobedisplayed > desiredarraysize)
    {
        //check to see if the amount they want displayed is greater than the amount in the array
        cout<<"I'm sorry you cannot display more items than can exist in your array, exiting program"<<endl;
        exit(-1);
    }

    table = new hashTablestore[desiredarraysize];

    for(int x = 0; x<desiredarraysize; x++)
    {

        table[x].word = " ";
        table[x].collisions = 0;
        table[x].totalreadin = 0;
    }

}

hashTable::~hashTable()
{
    //Destructor for the hashTable object


    delete table;

}

template <class type>
void hashTable::insert(string tobeheld)
{
    //A method to insert a string into the hashTable object


    bool hasbeenstored = false;
    int numberofcollisions = 0;
    int x;
    x = hash(tobeheld);


    if(this->table[x].word != " ")
    {


       //A check to see if this spot in the table is occupied by something

       if(this->table[x].word ==tobeheld)
        {
            //A check to see if the data occupying the spot is the same as the data being added

        this->table[x].totalreadin++;

        }



      numberofcollisions++;
      totalcollisionsz++;

      x = x + (numberofcollisions * numberofcollisions);

      while(hasbeenstored)
    {
      //while the string has not been stored
      if(numberofcollisions > (desiredarraysize*2))
      {
          //Check to see if the amount of items to be put in the list exceeds the array size using collisions (probably doesn't work)
          cout<<"I'm sorry but it seems your list is full, ending program..."<<endl;
          exit(-1);
      }
      else
    {


      if(x > desiredarraysize)
      {
          //if statement to wrap around
         x -= desiredarraysize;
      }
      else if(this->table[x].word != " ")
      {
          numberofcollisions++;
          totalcollisionsz++;
          x = x+ (numberofcollisions * numberofcollisions);
      }
      else
      {
          this->table[x].word = tobeheld;
      }
     }

  }
    }


  else
  {

      this->table[x].word = tobeheld;
  }



}

int hashTable::hash(string tobehashed)
{

    //Method to find the correct index for a word being inserted into the hashTable using the formula (

    float key;

  for(int i = 0; i<tobehashed.length();i++)
  {
      key +=tobehashed[i];

  }

  int theend;

  int whole;

  float indeices;

  indeices = key*this->A;

  whole = indeices;

  indeices -= whole;

  indeices *= desiredarraysize;

  theend = indeices;

  return theend;
}

void hashTable::display()
{
    cout<<totalcollisionsz<<endl;
    int i = 0;
    int g = 0;
    //A method to display a select amount of word from the hashTable (number chosen by user)

    cout<<"Index"<<setw(15)<<"Word"<<setw(15)<<"Count"<<setw(15)<<"Collisions"<<endl;
    cout<<"---------------------------------------------------"<<endl;
  while (g <tobedisplayed)
    {
        i++;
        if(table[i].word != " ")
        {
           cout<<i<<setw(15)<<table[i].word<<setw(15)<<table[i].totalreadin<<setw(15)<<table[i].collisions<<endl;
           g++;
        }

    }
}




