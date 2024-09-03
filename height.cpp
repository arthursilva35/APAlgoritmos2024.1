#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void imprimeVetor(vector<int> &vetor){
    for(int i = 0; i < vetor.size(); i++){
        if(i == vetor.size() - 1){ cout << vetor[i] << endl; continue; }
        cout << vetor[i] << " ";
    }
}



int main(){
    int nc;
    
    cin >> nc;
    
    for(int i = 0; i < nc; i++){
        int n;

        cin >> n;

        vector<int> alturas;

        for(int i = 0; i < n; i++){
            int cur_altura;
            cin >> cur_altura;

            alturas.push_back(cur_altura);
        }

        sort(alturas.begin(), alturas.end());
        
        imprimeVetor(alturas);

    }
    return 0;
}