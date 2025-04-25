
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <list>

using namespace std;

// vector<int> history;

void clockCounterDiff (int &counter, int c1, int c2, string clock){
    int c1_tick = clock[c1] == '1' ? 1:0;
    int c2_tick = clock[c2] == '1' ? 1:0;
    counter = counter + c1_tick-c2_tick;
}

void clockCounterMod(int &counter, int c1, string clock, int p) {
    int c1_tick = clock[c1] == '1' ? 1:0;
    counter = (counter + c1_tick)%p;
}

void updateBuffer (int c1, int c2, string clock, int Buffer[] , int d){
    int c1_tick = clock[c1] == '1' ? 1:0;
    int c2_tick = clock[c2] == '1' ? 1:0;
    if(c2_tick){
        for(int i=d-1;i>0;i--){
            Buffer[d-1]=Buffer[d-2];
        }
        Buffer[0]=0;
    }
    if(c1_tick){Buffer[0]=1;}
} 


