from random import randint
import os
import string

def main():
    
    
    x = 0
    
    f = open('test.txt', 'w')
    
    while(x < 1001):
        
        y = randint(0, 1000)
       
        f.write(str(y))
       
        f.write('\n')
       
        x = x + 1
       
       
    
    print "all done"
    
    f.close()
    
    
    
    


if __name__ == '__main__':
    main()
    
    
    
    
