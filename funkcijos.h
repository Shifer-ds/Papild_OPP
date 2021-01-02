
#include "funkcijos.cpp"
using namespace std;
int menu_pasirinkimas();
void splitter(string &str, char delim, vector<string> &out);
vector<string> nuskaitymo_test(string failo_pav);
vector<string> nuskaitymas(string failo_pav);
vector<string> unikalios_reiksmes(vector<string> in);
string zodis_pagal_id(map<string,int> zodziaisuID,int id);
map<string,int> zodziai_su_unikaliu_id(vector<string> skirtingi);
map<string,int> zodziu_pasikartojimai(multimap< int, string, less< int > > box,  map<string,int> zodziaisuID);
