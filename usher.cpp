#include <bits/stdc++.h>

using namespace std;
#define INF (1<<29)

int dp[505][505];

int main(){
    int tc, caja, n;
    cin >> tc;
    while(tc--){
        cin >> caja >> n;
        //Llenamos el dp con valores altos
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = INF;
            }
            if(i != 0){
                dp[i][i] = 0;
            }
        }
        int k, x, costo;
        cin >> k;
        //Lleno el dp "caso base", lo del usher a quien puede pasar
        while(k --){
            cin >> x;
            dp[0][x] = 0;
        }
        //Por cada feligres leo sus reglas
        for(int i = 1; i <= n; i++){
            cin >> k;
            while(k--){
                //Leido el monto que pone y a quien pasa, lo guardo en dp
                cin >> costo >> x;
                dp[i][x] = min(dp[i][x], costo);
            }
        }
        //Quiero tener el menor monto
        for(int k = 0; k <= n; k++){
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int resp = 0;
        int actual = 0;
        while(true){
            actual += dp[0][0];
            if(actual >= caja){
                break;
            }
            actual--;
            resp++;
        }
        cout << resp << endl;
    }
    return 0;
}