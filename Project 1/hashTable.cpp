#include "Hashtable.h"





hashTable::hashTable(float a, int displayit, int sizeIwant)
{
    //Method to initilize the hashTable object
    //Precondition:Call to create a hashTable object
    //Postcondition:hashTable object created with three varibles stored the hash constant, the amount of data members to display and the size of the table

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

    table = new entry[desiredarraysize];

    for(int x = 0; x<desiredarraysize; x++)
    {

        table[x].word = " ";
        table[x].displacementvalue = 0;
        table[x].totalreadin = 0;
    }

}

hashTable::~hashTable()
{
    //Destructor for the hashTable object
    //Precondition:hashTable object created
    //Postcondition:hashTable object deleted

    delete table;

}


void hashTable::insert(string tobeheld)
{
    //A method to insert a string into the hashTable object
    //Precondition:hashTable object created
    //Postcondition:string stored inside the hashTable


    bool hasbeenstored = false;
    //temp varaibles to contain data from the table during the robin hood exchange
    string tempword;
    int tempdis;
    int temptotal;
    int x;//indexing location
    int originx;//original x so that the program can tell if it has checked the entire table
    int helddis; //tobeheld's displacement value
    int total; //holds the total contained if there is a robin hood switch
    x = hash(tobeheld);


    total = 0;
    //setting displacement value to zero
    helddis = 0;
    //varible to check to see if the linear probe has checked the entire table
    originx = x;

    if(this->table[x].word != " ")
    {


       //A check to see if this spot in the table is occupied by something

       if(this->table[x].word ==tobeheld)
        {
            //A check to see if the word occupying th espot is the same as the one being added

            this->table[x].totalreadin++;

        }



      while(hasbeenstored == false)
    {
        x++;
        helddis++;
      //while the string has not been stored
      if(originx == x)
      {

          //a conditional to check if the table has returned to the original hash position, exits the method
          cout<<"I'm sorry but it seems your table has no space, ending program..."<<endl;
          exit(-1);
      }
      else
    {


      if(x > desiredarraysize)
      {
          //if statement to wrap around if the end of the table is reached
         x -= desiredarraysize;

      }

      else if(this->table[x].word != " ")
      {
          if(this->table[x].word == tobeheld)
          {
              //if statement to check if the object is already stored int he table, if so increments the totalreadin by 1
              table[x].totalreadin++;
              hasbeenstored = true;
          }
          else if(this->table[x].displacementvalue < helddis)
          {
              //if statement to check if the displacement value of what is stored in the list is lower that what is trying to be stored
              //if so a robin hood exchange occurs and the two swap places and the linear probe continues

              //exchanging the held data into a temporary container
              tempword = this->table[x].word;
              tempdis = this->table[x].displacementvalue;
              temptotal = this->table[x].totalreadin;

              //moving the new data into this container
              this->table[x].word = tobeheld;
              this->table[x].displacementvalue = helddis;
              this->table[x].totalreadin = total;


              //moving olddata into new storage
              tobeheld = tempword;
              helddis = tempdis;
              total = temptotal;
          }
      }
      else
      {
          //nothing is in the space this is trying to be placed in so it gets placed
          //this is used after a collision occurs
          this->table[x].word = tobeheld;
          this->table[x].displacementvalue = helddis;
          this->table[x].totalreadin = total;

          //ends the loop
          hasbeenstored = true;
      }
     }

  }
    }


  else
  {

      //if the first spot the table hashes to is empty this is executed
      this->table[x].word = tobeheld;
      this->table[x].displacementvalue = helddis;
      this->table[x].totalreadin = total;
  }



}

int hashTable::hash(string tobehashed)
{

    //Method to find the correct index for a word being inserted into the hashTable using the formula (
    //Precondition:hashTable object created and a string being inserted
    //Postcondition:a indexlocation to insert the string into the hashTable
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
    //Precondition:hashTable object created
    //Postcondition:Contents of hashTable object displayed
    cout<<"Index"<<setw(15)<<"Word"<<setw(15)<<"Count"<<setw(15)<<"Displacement value"<<endl;
    cout<<"---------------------------------------------------"<<endl;
  while (g <tobedisplayed)
    {
        i++;
        if(table[i].word != " ")
        {
           cout<<i<<setw(15)<<table[i].word<<setw(15)<<table[i].totalreadin<<setw(15)<<table[i].displacementvalue<<endl;
           g++;
        }

    }
}

int hashTable::searchit(string tobesearched)
{
    int x;
    int originx;
    x = hash(tobesearched);
    originx = x;
    int totalsearched = 0;

    if( this->table[x].word == tobesearched)
    {
        cout<<"Found "<<table[x].word<<endl;
        cout<<"It was stored "<<table[x].totalreadin<<" times"<<endl;
        return(x);

    }
    else
    {
        while(this->table[x].word != tobesearched)
        {
            x++;
            totalsearched++;
            //cout<<x<<endl;
            if(x == desiredarraysize)
            {
                //if x hits the end of the table loops back around to check the beginning
                x -=desiredarraysize;

            }
            if(x == originx)
            {
                //if x gets back to the place it originally hashed to search ends
                cout<<"Your querry is not in the table..."<<endl;
                break;
            }
        }

        cout<<"Found "<<table[x].word<<endl;
        cout<<"It was stored "<<table[x].totalreadin<<" times"<<endl;
        //returns an int so it can be used in the delete method
        return(x);

    }


}

void hashTable::delentry(string tobedel)
{
    int x;

    //uses the searchit method to search the list for the entry specified by the user
    x = searchit(tobedel);

    //replaces the data held in the table with the data originally held when the table was created so this spot can be used again
    table[x].word = " ";
    table[x].totalreadin = 0;
    table[x].displacementvalue = 0;
}





