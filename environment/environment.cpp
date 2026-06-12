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

bool addEvents(vector<string>& inputs, string ticks, const vector<string>& events, string observerItem){
    bool foundEvent = false;
   // if(observerItem!="CCSL"){inputs.push_back("advanceOf(sec,1)");}
    for(int m=0;m<ticks.size();m++){
        if((ticks[m]=='1')&&(m<events.size())&&(events[m]!="")){
            inputs.push_back(events[m]);
            foundEvent = true;
        }
    }
    // if(foundEvent && (observerItem=="CCSL")){inputs.push_back("advanceOf(sec,1)");}
    return foundEvent;
}


bool selectionnerAleatoire(const std::vector<string>& diagnostic, const vector<string>& diagnosticEVents,  const std::vector<string>& control, 
    const vector<string>& controlEvents, string observerItem, string output) {
    if (diagnostic.empty()) return {};
    

    // Moteur aléatoire
    vector<int> liste1;
     vector<int> liste2;
     vector<int> selectedItem;
     vector<int> selectedItemControl;
     vector<string> copyDiagnostic;
    ofstream outFile(output!=""?output:"new_inputs.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open the file for writing." << endl;
        return false;
    }
    std::mt19937 rng(std::random_device{}());
    int max = diagnostic.size()< control.size()?diagnostic.size():control.size();
    // Nombre aléatoire d'éléments à sélectionner (entre 1 et taille de la liste)
    std::uniform_int_distribution<int> distTime(1, max/2);
    int nbTime = distTime(rng);
    // Copier et mélanger la liste
    std::uniform_int_distribution<int> distTemp(nbTime-1, nbTime);
    int nbTemp = distTemp(rng);
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
        if(observerItem == "CCSL")addEvents(copyDiagnostic, diagnostic[i], diagnosticEVents, observerItem);
        copyDiagnostic.push_back("schedule("+diagnostic[i]+suffixClocks+")");
        if(observerItem != "CCSL")addEvents(copyDiagnostic, diagnostic[i], diagnosticEVents, observerItem);
        auto it = find(selectedItem.begin(), selectedItem.end(), i+1);
        if ((it != selectedItem.end())&&(k<control.size())) {
            copyDiagnostic.push_back("advanceOf(sec,101)");
            while(k<control.size()){
                if(observerItem == "CCSL")addEvents(copyDiagnostic, control[k], controlEvents, observerItem);
                copyDiagnostic.push_back("schedule("+prefixClocks+control[k]+")");
                if(observerItem != "CCSL")addEvents(copyDiagnostic, control[k], controlEvents, observerItem);
                auto ft = find(selectedItemControl.begin(), selectedItemControl.end(), k+1);
                copyDiagnostic.push_back("advanceOf(sec,6)");
                k++;
                if(ft!=selectedItemControl.end()){
                    copyDiagnostic.push_back("get_temperature(200)");
                    break;
                }
            }
        }else{
            // copyDiagnostic.push_back("advanceOf(sec,1)");
        }
    }
    while(k<control.size()){
        if(observerItem == "CCSL")addEvents(copyDiagnostic, control[k], controlEvents, observerItem);
        addEvents(copyDiagnostic, control[k], controlEvents, observerItem);
        // copyDiagnostic.push_back("schedule("+prefixClocks+control[k]+")");
        if(observerItem == "CCSL")addEvents(copyDiagnostic, control[k], controlEvents, observerItem);
        auto ft = find(selectedItemControl.begin(), selectedItemControl.end(), k+1);
        copyDiagnostic.push_back("advanceOf(sec,6)");
        k++;
    }
    for (string n : copyDiagnostic) outFile << n << endl;
    outFile.close();
    return true;
}

//vector<string> getAllTicks(const char *file_name)
vector<string> getAllTicks(const char *filename)
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
        ticks.push_back(tick);
    }
    return ticks;
}

std::vector<std::string> lireFichierIndexe(const std::string& chemin) {

    std::ifstream fichier(chemin);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + chemin);
    }

    // Première passe : trouver max_index
    int max_index = -1;
    int index;
    std::string valeur;

    while (fichier >> index >> valeur) {
        if (index < 0) {
            throw std::runtime_error("Index négatif détecté : " + std::to_string(index));
        }
        if (index > max_index) {
            max_index = index;
        }
    }

    if (max_index == -1) {
        return {}; // fichier vide
    }

    // Initialisation du tableau
    std::vector<std::string> tableau(max_index + 1, "");

    // Deuxième passe : remplir le tableau
    fichier.clear();
    fichier.seekg(0);

    while (fichier >> index >> valeur) {
        tableau[index] = valeur;
    }

    fichier.close();
    return tableau;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <fichier1> <fichier2> ... <fichierN>" << std::endl;
        return 1;
    }

    string observerItem = "";
    string output = "";
    std::vector<std::string> fichiers;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--observer") {
            if (i + 1 < argc) {
                observerItem = argv[i + 1];
                i++; // sauter la valeur du paramètre nommé
            } else {
                std::cerr << "Erreur : --output requiert une valeur" << std::endl;
                return 1;
            }
        }if (arg == "--output") {
            if (i + 1 < argc) {
                output = argv[i + 1];
                i++; // sauter la valeur du paramètre nommé
            } else {
                std::cerr << "Erreur : --output requiert une valeur" << std::endl;
                return 1;
            }
        } else {
            fichiers.push_back(arg);
        }
    }
    string diagnosticEventsFile = fichiers[1];
    string controlEventsFile = fichiers[3];
    vector<string> diagnoticEvents = lireFichierIndexe(diagnosticEventsFile);
    vector<string> controlEvents = lireFichierIndexe(controlEventsFile);
    std::vector<string> diagnostic = getAllTicks(fichiers[0].c_str());
    std::vector<string> control = getAllTicks(fichiers[2].c_str());
    selectionnerAleatoire(diagnostic,diagnoticEvents, control, controlEvents, observerItem, output);

    return 0;
}


