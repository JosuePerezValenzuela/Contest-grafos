#include <bits/stdc++.h>

using namespace std;

int main(){
    char matriz[5000][20];
    string palabra;
    int k = 0;

    while(true){
        cin >> palabra;
        if(palabra[0] != '#'){
            int i;
            int tamanio = palabra.size();
            //Lleno mi matriz con las letras de la palabra
            for(i = 0; i < tamanio; i++){
                matriz[k][i] = palabra[i]; 
            }
            while(i != 21){
                //Lleno lo demas con "basura"
                matriz[k][i++] = 'a';
            }
            k++;
        }else{
            break;
        }
    }

    unordered_map<char, int> mapa;
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < k; j++){
            //Si es mayuscula en ascii
            if(matriz[j][i] > 64 && matriz[j][i] < 91){
                mapa[matriz[j][i]]++;
            }
            //Si es la primera vez que lo veo
            if (mapa[matriz[j][i]] == 1){
                cout << matriz[j][i];
            }
        }
    }
    cout << "\n";
}