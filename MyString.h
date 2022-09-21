//Andrew Kinney

#ifndef string_h
#define string_h

class MyString
{
    //Data members
private:
    int size;
    char* sPtr;
    
public:
    //Constructors
    MyString();                         //no arg
    MyString(const char* source);       //c-string from main
    MyString(const MyString& source);   //copy constructor
    
    //Getters and setters:)
    int length();
    char getChar(int index);
    void setChar(int index, char ch);
    
    //Other
    void display();
    void normalize();
    void reverse();
    bool sameAs(const MyString& source);
    bool isPalendrome();
    
    //Destructor!
    ~MyString();
};

#endif 
    
    
    
    
