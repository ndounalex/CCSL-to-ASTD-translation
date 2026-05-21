
#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <list>

using namespace std;

// vector<int> history;
vector<string> allTicks;

//vector<string> getAllTicks(const char *file_name)
vector<string> getAllTicks()
{
// tag::code[]
    pugi::xml_document doc;
    vector<string> ticks;
    char *file_name = "trace";
    pugi::xml_parse_result result = doc.load_file(file_name);
    pugi::xml_node root = doc.child("trace:Trace");
    if(root == NULL){
        cout << "Pas de root de type trace" << endl;
    }
    cout << doc.child("Trace").attribute("xmlns:trace").value() << endl;
    for (pugi::xml_node tool: root.children("logicalSteps"))
    {
        string tick = "";
        for (pugi::xml_node eventOccurence: tool.children("eventOccurrences")){
            string eState="";
            string fState = "";
            string name="";
            
            for (pugi::xml_attribute attr: eventOccurence.attributes())
            {
               name= attr.name();
                if(name=="eState"){
                    eState = attr.as_string();
                }else if(name =="fState"){
                    fState = attr.as_string();
                }
            }
            tick = ((eState=="noTick") && (fState=="noTick"))?tick+"0":tick+"1";
        }
        cout<< tick << endl;
        ticks.push_back(tick);
    }
    return ticks;
}

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


