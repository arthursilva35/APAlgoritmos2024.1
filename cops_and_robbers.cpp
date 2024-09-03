// Questão de Backtracking

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void imprimeMatriz(int matriz[5][5]){
    for(int j = 0; j < 5; j++){
        for(int k = 0; k < 5; k++){
            if(k == 4){ cout << matriz[j][k] << endl; continue;}
            cout << matriz[j][k] << " ";
        }
    }
}

bool valido(int (&matriz)[5][5], int x, int y, int (&visitado)[5][5]){
    if (0 <= x && x < 5 && 0 <= y && y < 5 && matriz[x][y] == 0 && visitado[x][y] == false){return true;}
    else{return false;}    
}

bool labirinto(int (&matriz)[5][5], int x, int y, int (&visitado)[5][5]){
    
    visitado[x][y] = true; // marca a posição x, y como visitada

    if(x == 4 && y == 4){
        return true;
    }

    vector<pair<int,int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // direçoes nas quais vamos procurar por caminhos livre, a partir de uma posição x, y 

    for(int i = 0; i < dir.size(); i++){
        int viz_x = x + dir[i].first, viz_y = y + dir[i].second; // x e y do vizinho que vamos verificar
        if(valido(matriz, viz_x, viz_y, visitado) == true){
            bool novo_caminho = labirinto(matriz, viz_x, viz_y, visitado); // backtracking
            if(novo_caminho ==  true){ return true;}
        } 

    }

    return false;
}


int main(){
    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        int m[5][5]; // inicializa matriz 5x5
        int visitado[5][5]; // inicializa matriz de visitados
        
        // pega labirinto da entrada
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                int num;

                cin >> num;

                m[j][k] = num;
                visitado[j][k] = false;
            }
        }

        if(labirinto(m, 0, 0, visitado) == true){
            cout << "COPS" << endl;
        }else{
            cout << "ROBBERS" << endl;
        }

    }
    return 0;
}
