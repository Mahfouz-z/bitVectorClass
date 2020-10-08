#include <iostream>
#include <climits>
#include "bitVector.h"


using namespace std;

int bitVector::id = 0;

bitVector::bitVector(int s):size(s), charVectorSize((s + CHAR_BIT - 1)/CHAR_BIT), vid(++id)
{
    // Note, exception handling for memorey allocation was not implemented
    // as we assumed the inavalability of STL
    if(charVectorSize > 0)
    {
        //init the array to all unset
        data = new char[charVectorSize];
        for (int i = 0; i < charVectorSize; i++)
        {
            data[i] = 0;
        }
        cout << "object with ID: "<< this->vid << " Created a bitVector of size: " << s << endl; 
    }
    else 
    {
        cout << "object with ID: "<< this->vid << ": Invalid non-zero value entered, vector is not created!\n";
        data = nullptr;
        size = -1;
        charVectorSize = -1;
    }
 
}

bitVector::bitVector (const bitVector& a):size(a.size), charVectorSize(a.charVectorSize), data(new char[a.charVectorSize]) //copy
{ 
    cout << "object with ID: "<< this->vid << " Running Copy Constructor copying " << "object with ID: "<< a.vid << " to itself!" << endl;
    for(int i=0; i<size; i++)
        data[i]=a.data[i];
}

bitVector::bitVector (bitVector&& a):size(a.size), charVectorSize(a.charVectorSize), data(a.data) //move
{ 
    cout << "object with ID: "<< this->vid << " Running Move Constructor moving " << "object with ID: " << a.vid << " to itself!" << endl;
    a.data = nullptr;
    a.size = 0;
    a.charVectorSize = 0;
}

bitVector::~bitVector()
{
    cout << "object with ID: "<< this->vid << " running destructor!\n";
    if(data!=nullptr)
        delete [] data;
    else 
        cout << "\tnothing to delete\n";
}

int bitVector::setValue(int i, bool v)
{
    if(i < size && i >= 0)
    {
        char & elm = data[i/CHAR_BIT];
        if(v == true)
        {
            elm = elm | (1 << (i%CHAR_BIT));
            cout << "object with ID: "<< this->vid << " has set bit number " << i << endl;
        }
        else
        {
            elm = elm & ~(1 << (i%CHAR_BIT));       
            cout << "object with ID: "<< this->vid << " has unset bit number " << i << endl;
        }
        return 0;
    }
    else if(size > 0)
    {
        cout << "You provided " << "object with ID: "<< this->vid << " with invalid index" << endl;
        return -1;
    }
    else
    {
        cout << "object with ID: "<< this->vid << " Invalid Object, Cannot be set!" << endl;
        return -2;
    }
    
}

int bitVector::Value(int i)
{
    if(i < size && i >= 0)
    {
        bool bitValue = data[i/CHAR_BIT] & (1 << (i%CHAR_BIT));
        cout << "object with ID: "<< this->vid << " will return the value " << bitValue << " from index " << i << endl;
        return (bitValue);
    }
    else if(size > 0)
    {
        cout << "object with ID: "<< this->vid << " cannot return the value at index " << i << " as this index is out of bounds. -1 will be returned" << endl;
        return -1;
    }
    else
    {
        cout << "object with ID: "<< this->vid << " Invalid Object, Cannot be unset, -2 will be returned!" << endl;
        return -2;
    }
}
