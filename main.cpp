#include "funkcijos.h"

using namespace std;

int main()
{
    cout << "atlikti testa/ programos paleidimas (0/1)";
    int x = 0;
    x = menu_pasirinkimas();
    vector<string> zodziai;
    if(x == 0){
        zodziai = nuskaitymo_test("test.txt");
    }else{
        zodziai = nuskaitymas("straipsnis.txt");
    }
    vector<string> skirtingi = unikalios_reiksmes(zodziai);
    map<string,int> zodziaisuID = zodziai_su_unikaliu_id(skirtingi);

    multimap< int, string, less< int > > box;
    for(string z: zodziai)
    {
        box.insert(make_pair(zodziaisuID.find(z)->second,z));
    }

    map<string,int> rezul = zodziu_pasikartojimai(box, zodziaisuID);

    map<string, int>::iterator itr = rezul.begin();
    while ( itr != rezul.end() )
    {
        if ( (*itr).second == 1 )
            itr = rezul.erase( itr );
        else
            itr++;
    }

    ofstream out("1isvestis.csv");
    map<string,int>::iterator in;
    out<<"zodis,pasik"<<endl;
    for(in=rezul.begin(); in!=rezul.end(); in++)
    {
        out<<in->first<<','<<in->second<<endl;
    }
    out.close();

    vector<string> rezultato_zodziai;
    for(map<string,int>::iterator it = rezul.begin(); it != rezul.end(); ++it)
    {
        rezultato_zodziai.push_back(it->first);
    }

    ifstream inn("straipsnis.txt");
    ofstream outt("lentele.csv");
    string eilute;
    int i = 1;
    outt<<"eilutes"<<',';
    for(string z:rezultato_zodziai){
        outt<<z<<',';
    }
    outt<<endl;
    int sizas = rezultato_zodziai.size();
    while (getline(inn, eilute))
    {
        vector<int> bigNulis(sizas);
        /*ispjaunam url'us visiskai, nevisi formatai tinka...*/
        regex url("\\S*www\\.\\S+");
        string str = regex_replace(eilute,url,"");
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
        vector<string> zodziai;
        splitter(str,' ',zodziai);
        outt<<i<<" Eilute: "<<',';
        for(string z:zodziai)
        {
            if (find(rezultato_zodziai.begin(), rezultato_zodziai.end(), z) != rezultato_zodziai.end())
            {
                auto it = find(rezultato_zodziai.begin(), rezultato_zodziai.end(), z);
                int index = it - rezultato_zodziai.begin();
                bigNulis[index] = 1;
                }
            }
        for(int z:bigNulis){
        outt<<z<<',';
        }
        outt<<endl;
        i++;
    }
    inn.close();
    outt.close();

    ifstream inurl("straipsnis.txt");
    string textas((istreambuf_iterator<char>(inurl)),istreambuf_iterator<char>());
    inurl.close();
    transform(textas.begin(), textas.end(), textas.begin(),[](unsigned char c)
    {
        return tolower(c);
    });
    vector<string> texto_zodziai;
    splitter(textas,' ',texto_zodziai);

    regex url_regex("\\S*www\\.\\S+");
    sregex_iterator iter(textas.begin(), textas.end(), url_regex);
    sregex_iterator end;
    while(iter != end)
    {
        for(unsigned i = 0; i < iter->size(); ++i)
        {
            cout<< (*iter)[i] << endl;
        }
        ++iter;
    }
    return 420;
}
