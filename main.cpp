//Andrew Kinney

#include "MyString.h"
#include <iostream>

using namespace std;

int main()
{
    //Variable declarations
    int maxLen = 100;
    char userString[maxLen];
    
    //Input first two strings
    cout << "Please enter the first string: ";
    cin.getline(userString, maxLen+1);
    MyString s1(userString);    
    
    cout <<"Please enter the second string: ";
    cin.getline(userString, maxLen+1);
    MyString s2(userString);
    
    //Compare them
    if(s1.sameAs(s2))
        cout << "These strings are the same";
    else
        cout << "These strings are not the same";
    cout << endl;
    cout << endl;
    
    //Input third string
    cout << "Please enter a possible palindrome: ";
    cin.getline(userString, maxLen+1);
    MyString s3(userString);
    
    //See if it's a palindrome
    if(s3.isPalendrome())
        cout << "This is a palindrome";
    else
        cout << "This is not a palendrome";
    cout << endl;
    
    return 0;
}
