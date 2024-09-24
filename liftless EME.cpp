#include <bits/stdc++.h>

using namespace std;

int n, m;
//Grafo representado en lista de adyacencia
vector <pair <int, int>> grafo [100005];
//Para guardar las distancias minimas 
long long distMin [100005];
//Para saber el grado de cada vertice
long long d [100005];

//Recorrido en profundidad en busca de la distancia minima desde el nodo u
void dfs(int u){
    if(distMin[u] != -1){
        // si ya se calculo, devolvemos
        return;
    }
    long long m = INT_MAX;
    if(d[u] == 0){
        m = 0;
    }
    int limite = grafo[u].size();
    for(int i = 0; i < limite; i++){
        int v = grafo[u][i].first;
        int w = grafo[u][i].second;
        dfs(v);
        m = min(m, (long long) distMin[v] + (long long) w);
    }
    distMin[u] = m;
}

int main(){
    string caso;
    while(cin >> caso){
        cin >> n >> m;
        //Limpieza del grafo y listas
        for(int i = 0; i < n * m * 2; i++){
            grafo[i].clear();
            d[i] = 0;
            distMin[i] = -1;
        }
        //Lectura para llenar el grafo
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    int vertice = (i - 1) * m + j;
                    int verticeAd = i * m + k;
                    int peso;
                    cin >> peso;
                    grafo[vertice].push_back(make_pair(verticeAd, peso));
                    d[vertice]++;
                }
            }
        }
        long long resp = LLONG_MAX;
        for(int i = 0; i < m; i++){
            dfs(i);
            resp = min(resp, distMin[i]);
        }
        resp += (long long) 2 * (n - 1);
        cout << caso << endl;
        cout << resp << endl;
    }
}