//Andrew Kinney

#include "MyString.h"
#include <iostream>

using namespace std;

//Constructors
MyString::MyString()                         //No arg
{
    size = 0;
}

MyString::MyString(const char* source)      //c-string from main
{
    //Get size
    int i = 0;
    while(source[i] != '\0')
    {
        i++;
    }
    size = i;
    
    //Create c-string
    sPtr = new char[size];

    for(i = 0; i < size; i++)
    {
        sPtr[i] = source[i];
    }
    
}

MyString::MyString(const MyString& source)  //copy constructor
{
    size = source.size;
    if(size != 0)
    {
        sPtr = new char[size];
        for(int i = 0; i < size; i++)
            sPtr[i] = source.sPtr[i];
    }
}
    
//Getters and setters
int MyString::length()
{
    int length = size;
    return length;
}

char MyString::getChar(int index)
{
    char ch;
    ch = sPtr[index];
    return ch;
}

void MyString::setChar(int index, char ch)
{
    sPtr[index] = ch;
    return;
}
    
//Other
void MyString::display()
{
    for(int i = 0; i < size; i++)
        cout << sPtr[i];
    return;
}

void MyString::normalize()
{
    //temp array to hold current string, also find the new size of new normalized c-string
    char tempString[size];
    int newSize = 0;
    for(int i = 0; i < size; i++)
    {
        tempString[i] = sPtr[i];
        if((sPtr[i] >= 'A' && sPtr[i] <= 'Z') || (sPtr[i] >= 'a' && sPtr[i] <= 'z'))
        {
            newSize++;
        }
    }
        
    delete[] sPtr;      //delete original string
    sPtr = new char[newSize];   //new, empty one with correct size
    
    //populate new sPtr with only letters
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if((tempString[i] >= 'A' && tempString[i] <= 'Z') || (tempString[i] >= 'a' && tempString[i] <= 'z'))
        {
            char ch = tempString[i];
            ch = tolower(ch);       //make it lower case aswell before storing it
            sPtr[j] = ch;
            j++;
        }  
    }
    size = newSize;     //correct the size variable
}


void MyString::reverse()
{
    char tempString[size];
    
    //make temp array that's reversed
    int j = 0;
    for(int i = size-1; i >= 0; i--)
    {
        tempString[j] = sPtr[i];
        j++;
    }

    //transfer the reveresed string to sPtr
    for(int i = 0; i < size; i++)
    {
        sPtr[i] = tempString[i];
    }
}

bool MyString::sameAs(const MyString& source)
{
    //if they're not the same length, automatically we know they're not the same
    if(size != source.size)
    {
        return false;
    }
    
    for(int i = 0; i < size; i++)
    {
        //at any point they don't match, return false
        if(sPtr[i] != source.sPtr[i])
        {
            return false;
        }
    }
    
    //Makes it through all that, they're the same
    return true;
    
}

bool MyString::isPalendrome()
{
    //Normalize it
    normalize();
    
    //Make a copy
    char tempString[size];
    for(int i = 0; i < size; i++)
        tempString[i] = sPtr[i];
        
    //Reverse sPtr
    reverse();
    
    //Compare
    for(int i = 0; i < size; i++)
    {
        if(sPtr[i] != tempString[i])
            return false;
    }
    
    //If it makes it this far, it's a palindrome!
    return true;
}
    
//Destructor!
MyString::~MyString()
{
    if (size != 0)
        delete[] sPtr;
}
