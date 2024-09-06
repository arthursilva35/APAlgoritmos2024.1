#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void imprimeVetor(vector<int> &vetor){
    for(int i = 0; i < vetor.size(); i++){
        if(i == vetor.size() - 1){ cout << vetor[i] << endl; continue; }
        cout << vetor[i] << " ";
    }
}


int calculoPD(vector<int> &tempos, vector<int> &quantidades, int limite){
    int tam = tempos.size();

    vector<vector<int>> f(tam + 1, vector<int>(limite + 1, 0));

    for(int i = 1; i < tam + 1; i++){
        for(int j =1; j <limite + 1; j++){
            
            if(quantidades[ i - 1] > j){
                
                f[i][j] = f[i-1][j];
            
            }
            else{
                f[i][j] = max(f[i-1][j], tempos[i-1]+f[i-1][j - quantidades[i-1]]);
            }
        }
    }

    return f[tam][limite];
}




int main() {
    int n, p;

    cin >> n;
    while(n != 0){
        cin >> p;

        vector<int> tempos;
        vector<int> quantidades;

        for(int i = 0; i < n; i++){
            int t, q;
            
            cin >> t  >> q;

            tempos.push_back(t); quantidades.push_back(q);
        }

        int tempoFinal = calculoPD(tempos, quantidades, p);

        printf("%d min.\n", tempoFinal);
    
        cin >> n;
    }
}