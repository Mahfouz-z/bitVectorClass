/*
    Name: Mohamed Mafhouz Shehawy
    gnu complier with c++11 is required
    To compile run:
        make clean
        make all
    Run using:
        ./main
    
    N.B: The class is extended by many debugging statements; however,
    this could be later modified and only use the return values that
    indicate errors. That could be easiy done by using a #ifndef VERBOSE
    statements.
*/

#include <iostream>
#include "bitVector.h"


using namespace std;



int main()
{
    //Testing Invalid Vector
    cout << "Testing Invalid Vector\n";
    bitVector a(-1); //declare incorrect vector
    a.setValue(1,1); //set an incorrectly declared object
    a.Value(1); //unset an incorrectly declared object
    cout << "_____________________________________\n\n";
    
    //Testing Move Constructor
    cout << "Testing Move Constructor\n";
    bitVector b = bitVector(1000);
    cout << "_____________________________________\n\n";

    //Testing Copy Constructor
    cout << "Testing Copy Constructor\n";
    bitVector c(b);
    cout << "_____________________________________\n\n";

    //Testing setting bit out of bounds
    cout << "Testing setting bit out of bounds\n";
    c.setValue(10000, 1); 
    cout << "_____________________________________\n\n";

    //Testing unsetting bit out of bounds
    cout << "Testing unsetting bit out of bounds\n";
    c.setValue(10000, 0); 
    cout << "_____________________________________\n\n";

    //Testing getting bit out of bounds
    cout << "Testing getting bit out of bounds\n";
    c.Value(10000); 
    cout << "_____________________________________\n\n";

    //Testing setting a bit and getting it
    cout << "Testing setting a bit and getting it\n";
    c.setValue(3,1);
    bool val = c.Value(3);
    cout << "Returned Value: " << val << endl;
    cout << "_____________________________________\n\n";

    //Testing unsetting the same bit and getting it
    cout << "Testing unsetting the same bit and getting it\n";
    c.setValue(3,0);
    val = c.Value(3);
    cout << "Returned Value: " << val << endl;
    cout << "_____________________________________\n\n";

    return 0;
}