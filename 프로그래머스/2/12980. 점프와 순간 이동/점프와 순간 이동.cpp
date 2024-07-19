#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int solution(int n)
{
    int k = 0;
    while (n) {
        if (n%2 == 0) n /= 2;
        else {
            k++;
            n-=1;
        }
    }
    
    
    return k;
}