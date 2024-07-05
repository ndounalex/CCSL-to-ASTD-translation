
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <list>

using namespace std;

// vector<int> history;
int history[7] = {0};
list<int> delayForCount;


void updateHistory(int history[],string clock) {
    for(string::size_type i=0;i<clock.size();i++){
        if(clock[i]=='1')
            history[i]++;
    }
}

void updateOccurenceList(string clock, int c3, int c2, list<int>& listItem, int d) {
    list<int>::iterator listIterator;
    if((clock[c2]=='1')&&(listItem.back()!=0)){
        listItem.push_back(0);
    }
    if(clock[c3]=='1'){
        for(listIterator = listItem.begin(); listIterator != listItem.end();listIterator++){
            *listIterator = *listIterator + 1;
        }
    }
    if((listItem.size()> 0) && (listItem.front()==(d+1))){
        listItem.pop_front();
    }
}
