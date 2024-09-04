#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void imprimeVetor(vector<int> &vetor){
    for(int i = 0; i < vetor.size(); i++){
        if(i == vetor.size() - 1){ cout << vetor[i] << endl; continue; }
        cout << vetor[i] << " ";
    }
}

int BubbleSortSwapCounter(vector<int> &vetor){
    int swapCounter = 0;
    int tam = vetor.size();

    
    for(int k = 1; k < tam; k++){ //controla o número de elementos já ordenados
        for(int i = 0; i < tam - k; i++){ // responsável pelas trocas em si
            if(vetor[i] > vetor[i + 1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i + 1] = temp;
                swapCounter++;
            }
        }
    }

    return swapCounter;
}

int main(){
    int N;

    cin >> N;

    for (int i =  0; i < N; i++){
        int L;

        vector<int> trem;

        cin >> L;

        for(int i=0; i < L; i++){
            int cur;
            cin >> cur;
            trem.push_back(cur);
        }

        int numSwaps = BubbleSortSwapCounter(trem);
        
        printf("Optimal train swapping takes %d swaps.", numSwaps);
        cout << endl;

    }
    return 0;
}