#include <bits/stdc++.h>

using namespace std;

void aux(){
    string palabra;
    cin >> palabra;
    vector <char> lista;
    int alf[26] = {};
    lista.push_back(palabra[0]);

    for(int i = 1; i < palabra.size(); i++){
        if(lista.back() == palabra[i]){
            lista.pop_back();
        }else{
            //A es 65 x lo q restando A a cualquier palabra lo convertiremos en un numero
            //entre 0 y 26 correspondiente al alfabeto
            alf[lista.back() - 'A']++;
            lista.push_back(palabra[i]);
            alf[lista.back() - 'A']++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(alf[i]){
            cout << char(i + 'A') << " = " << alf[i] << endl;
        }
    }
}

int main(){
    int casos;
    cin >> casos;
    int num = 1;
    while(casos--){
        cout << "Case " << num << endl;
        aux();
        num++;
    }
    return 0;
}