#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matriz_grafo (1e4);
vector<bool> visitado (1e4, false);

int acha_custo_menor (int atual, int destino){
	visitado[atual] = true;

	int custo_atual = matriz_grafo[atual][0];
	int q_rua_atual = matriz_grafo[atual][1];

	if (atual == destino){
		return (custo_atual);
	}

	//verifica a quantidade de saídas
	if (q_rua_atual > 0){
		//o menor começa com o primeiro caminho
		int menor = acha_custo_menor (matriz_grafo[atual][2], destino);

		for (int i = 1 ; i < q_rua_atual ; i++){
			int rua_atual = i+1;
			if (! visitado[rua_atual]){
				if (menor > acha_custo_menor (matriz_grafo[atual][rua_atual], destino)){
					menor = acha_custo_menor (matriz_grafo[atual][rua_atual], destino);
				}
			}
		}
	}

	visitado[atual] = false;
}

int main() {
	int n_paradas;
	cin >> n_paradas;

	//o indice 0 de cada vetor será o custo da parada i
	//o indice 1 de cada vetor será a quantidade de ruas saindo de i
	for (int i = 1 ; i <= n_paradas ; i++){
		int aux;
		cin >> aux;
		matriz_grafo[i].push_back(aux);
		matriz_grafo[i].push_back(0);
	}

	int n_ruas;
	cin >> n_ruas;

	//armazena as ruas existentes entre os pontos
	for (int i = 0 ; i < n_ruas ; i++){
		int origem, destino;
		cin >> origem >> destino;
		matriz_grafo[origem].push_back(destino);
		matriz_grafo[origem][1]++;
	}

	//aqui começa as consultas, os dados já estão prontos
	int n_consultas;
	cin >> n_consultas;

	for (int i = 0 ; i < n_consultas ; i++){
		int destino;
		cin >> destino;
		int custo = acha_custo_menor (1, destino);
		cout << custo << endl;
	}
}