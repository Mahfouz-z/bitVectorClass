#ifndef BIT_VECTOR
#define BIT_VECTOR
 
#include <iostream>

using namespace std;

class bitVector 
{
    char* data;
    int charVectorSize;
    int size;
    int vid;
    static int id;
  public:
    bitVector(int s = 32);
    bitVector (const bitVector& a);
    bitVector (bitVector&& a);
    ~bitVector();
    int setValue(int i, bool v);
    int Value(int i);
};
 
#endif