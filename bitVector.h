#ifndef BIT_VECTOR
#define BIT_VECTOR
 
#include <iostream>


class bitVector 
{
    char* data;
    int charVectorSize;
    int size;
    int vid;
    static int id;
    

  public:
    bitVector(int s = 32);
    bitVector (const bitVector&);
    bitVector (bitVector&&);
    ~bitVector();
    int setValue(int, bool);
    int Value(int) const;
    int operator[](int) const; 
};
 
#endif