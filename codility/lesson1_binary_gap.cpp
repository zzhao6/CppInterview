// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include<iostream>

int solution(int N) {
    int longGap = 0;    // longest gap
    int currGap = 0;    // current gap
    bool metFirstOne = false;
    
    while(N > 0){
        
        int j = N & 1; // last digit of N
         
        if (!metFirstOne)   // don't start count until met the first one from rhs
        {
            if (j == 1)
            {
                metFirstOne = true;
                continue;
            }    
        }
        
        if (metFirstOne)
        {
            if (j == 0)
            {
                currGap++;
            }
            else if (j == 1)
            {
                if (longGap < currGap)
                {
                    longGap = currGap;
                }
                currGap = 0;
            }
        }
        
        N = N >> 1; // move 1 digit to the right
    }
    return longGap;
}