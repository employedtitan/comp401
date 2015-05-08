import os
import random

def cocktail_sort(alist):
    #setting up holder variable and the beginning and ending
    begin = -1
    end = len(alist) - 1
    holder = 0
    
    
    while True:
        
        begin = begin + 1
        swapped = False
        for i  in range(begin, end):
            
            
            if alist[i] > alist[i + 1]:
                #code to swap two values in the list if the one to the left is bigger than the one to the right
                holder = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = holder
                swapped = True
                
           
        end = end - 1
        swapped = False
        for i in range(end, begin, -1):
            
            if alist[i] < alist[i - 1]:
                #code to swap two values in the list if the one to the right is smaller than the one to the left
                holder = alist[i]
                alist[i] = alist[i-1]
                alist[i-1] = holder
                swapped = True
    
        if swapped == False:
            return alist
        

    
def populate(emptylist):
    #populates the list with 100 random numbers
    
    for x in range(0 ,10000):
        y = random.randint(0, 1000)
        emptylist.append(y)
        
   

def main():
    
    newlist = []
    
    populate(newlist)
    
    print(newlist)
    
    newlist = cocktail_sort(newlist)
    
    print(newlist)
    
    


if (__name__ == '__main__'):
    
    main()
    

