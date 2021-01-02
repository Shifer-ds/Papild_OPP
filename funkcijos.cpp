#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <regex>
#include <algorithm>
#include <cctype>
#include <set>
#include <iterator>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

int menu_pasirinkimas()
{
    int pasirink;
    cin >> pasirink;

    //Error check
    while ((cin.good() == false) or !(pasirink == 1 or pasirink == 0))
    {
        cout << "neteisinga ivestis." << '\n';

        cin.clear();
        cin.ignore(999, '\n');

        //is naujo paparaso:
        cout << "Bandykite dar karta: ";
        cin >> pasirink;
    }
    return pasirink;
};

void splitter(string &str, char delim, vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

vector<string> nuskaitymo_test(string failo_pav)
{
    ifstream in(failo_pav);
    string str((istreambuf_iterator<char>(in)),istreambuf_iterator<char>());
    cout<<str<<endl;
    /*ispjaunam url'us visiskai, nevisi formatai tinka...*/
    cout<<"----------"<<endl;
    regex url("\\S*www\\.\\S+");
    str = regex_replace(str,url,"");
    cout<<str<<endl;
    /*ispjaunam taskus */
    cout<<"----------"<<endl;
    regex task ("[^a-z|^A-Z \n]+");
    str = regex_replace(str,task,"");
    cout<<str<<endl;
    /*keiciam /n i tarpus */
    cout<<"----------"<<endl;
    regex nal("\n");
    str = regex_replace(str,nal, " ");
    cout<<str<<endl;
    /*didziosios -> mazosios*/
    cout<<"----------"<<endl;
    transform(str.begin(), str.end(), str.begin(),[](unsigned char c)
    {
        return tolower(c);
    });
    cout<<str<<endl;
    cout<<"----------"<<endl;
    vector<string> zod_masyvas;
    splitter(str,' ',zod_masyvas);
    return zod_masyvas;
}

vector<string> nuskaitymas(string failo_pav)
{
    ifstream in(failo_pav);
    string str((istreambuf_iterator<char>(in)),istreambuf_iterator<char>());
    cout<<str<<endl;
    /*ispjaunam url'us visiskai, nevisi formatai tinka...*/
    regex url("\\S*www\\.\\S+");
    str = regex_replace(str,url,"");
    /*ispjaunam taskus */
    regex task ("[^a-z|^A-Z \n]+");
    str = regex_replace(str,task,"");
    /*keiciam /n i tarpus */
    regex nal("\n");
    str = regex_replace(str,nal, " ");
    /*didziosios -> mazosios*/
    transform(str.begin(), str.end(), str.begin(),[](unsigned char c)
    {
        return tolower(c);
    });
    vector<string> zod_masyvas;
    splitter(str,' ',zod_masyvas);
    return zod_masyvas;
}

vector<string> unikalios_reiksmes(vector<string> in)
{
    vector<string> skirtingi = in;
    sort(skirtingi.begin(), skirtingi.end());
    skirtingi.erase( unique( skirtingi.begin(), skirtingi.end() ), skirtingi.end() );
    return skirtingi;
}
string zodis_pagal_id(map<string,int> zodziaisuID,int id)
{
    for (auto it = zodziaisuID.begin(); it != zodziaisuID.end(); ++it)
        if (it->second == id)
            return it->first;
}

map<string,int> zodziai_su_unikaliu_id(vector<string> skirtingi)
{
    map<string,int> zodziaisuID;
    int j = 0;
    for(string z:skirtingi)
    {
        zodziaisuID.insert(pair<string,int>(z,j));
        j++;
    }
    return zodziaisuID;
}

map<string,int> zodziu_pasikartojimai(multimap< int, string, less< int > > box,  map<string,int> zodziaisuID)
{
    int i = zodziaisuID.size();
    map<string,int> rezultatas;
    for(int k = 0 ; k < i ; k ++)
    {
        rezultatas.insert(pair<string,int>(zodis_pagal_id(zodziaisuID,k),box.count(k)));
    }
    return rezultatas;
}
