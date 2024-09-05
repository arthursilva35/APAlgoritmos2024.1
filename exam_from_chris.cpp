#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void imprimeVetor(vector<string> &vetor){
    for(int i = 0; i < vetor.size(); i++){
        cout << vetor[i] << " ";
    }
}



int main(){
    int n, k;

    int instanciaCounter = 1;

    while (cin >> n >> k && n > 0){
        vector<string> alunos;

        map<string, int> ordem;

        for(int i = 0; i < n; i++){
            string nome;
            
            cin >> nome;
            
            alunos.push_back(nome);

            ordem[nome] = i;
        }
        int f = 0;
        
        while(ordem.size() > 0 && k > 0){
            for(map<string, int>::iterator it = ordem.begin(); it != ordem.end() && k > 0; ++it){
                if (it->second - f <= k) {
                    k -= (it->second - f);

                    for(int i = it->second; i > f; --i) {
                        alunos[i] = alunos[i - 1];
                        ++ordem[alunos[i - 1]];
                    }

                    alunos[f] = it->first;
                    ++f;
                    ordem.erase(it->first);
                    break;
                }

            }
        }

        printf("Instancia %d\n", instanciaCounter++);

        imprimeVetor(alunos);

        cout << endl;
        cout << endl;
    }
}