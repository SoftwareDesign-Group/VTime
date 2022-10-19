//Andrew Kinney
//Software Design
//Lab4_(main)
//October 1, 2022

#include <iostream>
#include "vTime.h"

using namespace std;

int main()
{
    //Testing constructor and previous member functions with new sole data member "m_secondsSinceMidnight"
    VTime myTime(5, 23, 59);
    cout << "New time construction: " << myTime << endl;

    myTime.setHours(7);
    cout << "Set hours to 7:        " << myTime << endl;

    myTime.setMinutes(38);
    cout << "Set minutes to 38:     " << myTime << endl;

    myTime.setSeconds(45);
    cout << "Set seconds to 45:     " << myTime << endl;

    myTime.addSeconds(1000);
    cout << "Add 1000 seconds:      " << myTime << endl << endl;

    cout << myTime << " + 2,500s = " << myTime + 2500 << endl;

    cout << myTime << " + 100,000s = " << myTime + 100'000 << endl << endl;

    cout << "Here's a change in the code!" << endl;

    return 0;
}


