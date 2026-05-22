#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// vector<int> history;
vector<string> allTicks;




bool selectionnerAleatoire(const std::vector<string>& diagnostic, const std::vector<string>& control) {
    if (diagnostic.empty()) return {};

    // Moteur aléatoire
    vector<int> liste1;
     vector<int> liste2;
     vector<int> selectedItem;
     vector<int> selectedItemControl;
     vector<string> copyDiagnostic;
    ofstream outFile("inputs.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open the file for writing." << endl;
        return false;
    }
    std::mt19937 rng(std::random_device{}());
    int max = diagnostic.size()< control.size()?diagnostic.size():control.size();
    // Nombre aléatoire d'éléments à sélectionner (entre 1 et taille de la liste)
    std::uniform_int_distribution<int> distTime(1, max/2);
    int nbTime = distTime(rng);
    cout << "max == "<<  max << endl;
    cout << "nb time == "<<  nbTime << endl;
    // Copier et mélanger la liste
    std::uniform_int_distribution<int> distTemp(nbTime-1, nbTime);
    int nbTemp = distTemp(rng);
    cout << "nb temp == "<<  nbTemp << endl;
    for(int i=1;i<=diagnostic.size();i++){
        liste1.push_back(i);
    }
    for(int i=1;i<=control.size();i++){
        liste2.push_back(i);
    }
    std::vector<int> copie = liste1;
    std::shuffle(copie.begin(), copie.end(), rng);
    selectedItem = std::vector<int>(copie.begin(), copie.begin() + nbTime);
    std::shuffle(copie.begin(), copie.end(), rng);
    selectedItemControl = std::vector<int>(copie.begin(), copie.begin() + nbTemp);
   /* for(int i=0;i<selectedItem.size();i++){
        cout<< selectedItem[i] <<" ";
    }*/
   // cout<<endl;
    string suffixClocks = "";
    for (int j=0;j<control[0].size();j++){
        suffixClocks = suffixClocks + "0";
    }
    string prefixClocks = "";
    for (int j=0;j<diagnostic[0].size();j++){
        prefixClocks = prefixClocks + "0";
    }
    int k=0;
    for(int i=0;i<diagnostic.size();i++){
        
        copyDiagnostic.push_back("schedule("+diagnostic[i]+suffixClocks+")");
        auto it = find(selectedItem.begin(), selectedItem.end(), i+1);
        if ((it != selectedItem.end())&&(k<control.size())) {
            copyDiagnostic.push_back("advanceOf(sec,101)");
            while(k<control.size()){
                copyDiagnostic.push_back("schedule("+prefixClocks+control[k]+")");
                auto ft = find(selectedItemControl.begin(), selectedItemControl.end(), k+1);
                copyDiagnostic.push_back("advanceOf(sec,6)");
                k++;
                if(ft!=selectedItemControl.end()){
                    copyDiagnostic.push_back("get_temperature(200)");
                    break;
                }
            }
        }else{
            copyDiagnostic.push_back("advanceOf(sec,1)");
        }
    }
    while(k<control.size()){
        copyDiagnostic.push_back("schedule("+prefixClocks+control[k]+")");
        auto ft = find(selectedItemControl.begin(), selectedItemControl.end(), k+1);
        copyDiagnostic.push_back("advanceOf(sec,6)");
        k++;
    }
   /*for(int i=0;i<copyDiagnostic.size();i++){
        cout<< copyDiagnostic[i] << endl;
    }*/
    // Retourner les nbElements premiers éléments
    // copyDiagnostic;
    for (string n : copyDiagnostic) outFile << n << endl;
    outFile.close();
    return true;
}

//vector<string> getAllTicks(const char *file_name)
vector<string> getAllTicks(char *filename)
{
// tag::code[]
    pugi::xml_document doc;
    vector<string> ticks;
    // char *file_name = "trace";
    pugi::xml_parse_result result = doc.load_file(filename);
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


int main() {
    // std::vector<int> liste = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<string> diagnostic = getAllTicks("diagnostic_trace");
    std::vector<string> control = getAllTicks("control_trace_old");
    selectionnerAleatoire(diagnostic, control);

    return 0;
}


