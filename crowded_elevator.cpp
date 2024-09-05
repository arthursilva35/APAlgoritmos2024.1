#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void imprimeVetor(vector<int> &vetor){
    for(int i = 0; i < vetor.size(); i++){
        cout << vetor[i] << " ";
    }
}



int main(){
    int t;

    cin >> t;
    
    for(int i = 0; i < t; i++){
        int energia = 0;
        
        int n, c, m;

        vector<int> andaresParaVisitar;
        
        cin >> n >> c >> m;

        for(int i = 0; i < m; i++){

            int andar;

            cin >> andar;

            andaresParaVisitar.push_back(andar);            
        }

        sort(andaresParaVisitar.begin(), andaresParaVisitar.end());

        while(!andaresParaVisitar.empty()){
            int tam = andaresParaVisitar.size();
            
            energia += andaresParaVisitar[tam - 1]*2;

            for(int j = 0; j < c; j++){
                if(!andaresParaVisitar.empty()){
                    
                    andaresParaVisitar.pop_back();
                }
                
            }
        }

        cout << energia << endl;
    }
    return 0; 
}