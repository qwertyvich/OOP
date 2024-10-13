#include <iostream>
#include <cstring>
#include "../include/palindrom.h"

const int N = 1000;

bool palindrom(const char *string1)              
{
    char string2[N];

    int len1 = strlen(string1);
    for(int i=0;i<len1;++i)
    {
        string2[i] = string1[len1- i-1];
    }
    string2[len1+1] = '\0';

    for(int i=0;i<len1;++i)
    {
        if(string1[i] != string2[i])
        {
            return false;
        }

    }
    //std::cout << string2 << endl;
    return true;
    
}